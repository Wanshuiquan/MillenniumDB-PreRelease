#include "file_manager.h"

#include <sys/stat.h>
#include <fcntl.h>

#include <cassert>
#include <cstring>
#include <new>         // placement new
#include <type_traits> // aligned_storage

#include "query/query_context.h"
#include "storage/buffer_manager.h"
#include "storage/file_id.h"
#include "storage/filesystem.h"

using namespace std;

// memory for the object
static typename std::aligned_storage<sizeof(FileManager), alignof(FileManager)>::type file_manager_buf;
// global object
FileManager& file_manager = reinterpret_cast<FileManager&>(file_manager_buf);


FileManager::FileManager(const std::string& db_folder) :
    db_folder(db_folder)
{
    if (Filesystem::exists(db_folder)) {
        if (!Filesystem::is_directory(db_folder)) {
            throw std::invalid_argument("Cannot create database directory: \"" + db_folder +
                                        "\", a file with that name already exists.");
        }
    } else {
        Filesystem::create_directories(db_folder);
    }
}


void FileManager::init(const std::string& db_folder) {
    new (&file_manager) FileManager(db_folder); // placement new
}


void FileManager::flush(VPage& page) const {
    auto fd = page.page_id.file_id.id;
    lseek(fd, page.page_id.page_number*VPage::SIZE, SEEK_SET);
    auto write_res = write(fd, page.get_bytes(), VPage::SIZE);
    if (write_res == -1) {
        throw std::runtime_error("Could not write into file when flushing page");
    }
    page.dirty = false;
}


void FileManager::flush(PPage& page) const {
    auto fd = page.page_id.file_id.id;
    lseek(fd, page.page_id.page_number*PPage::SIZE, SEEK_SET);
    auto write_res = write(fd, page.get_bytes(), PPage::SIZE);
    if (write_res == -1) {
        throw std::runtime_error("Could not write into tmp file when flushing page");
    }
    page.dirty = false;
}


void FileManager::flush(UPage& page) const {
    auto fd = page.page_id.file_id.id;
    lseek(fd, page.page_id.page_number*UPage::SIZE, SEEK_SET);
    auto write_res = write(fd, page.get_bytes(), UPage::SIZE);
    if (write_res == -1) {
        throw std::runtime_error("Could not write into str hash file when flushing page");
    }
    page.dirty = false;
}


void FileManager::flush(TensorPage& page) const {
    auto fd = page.page_id.file_id.id;
    lseek(fd, page.page_id.page_number*TensorPage::SIZE, SEEK_SET);
    auto write_res = write(fd, page.get_bytes(), TensorPage::SIZE);
    if (write_res == -1) {
        throw std::runtime_error("Could not write into str hash file when flushing page");
    }
    page.dirty = false;
}


void FileManager::read_tmp_page(PageId page_id, char* bytes) const {
    auto fd = page_id.file_id.id;
    lseek(fd, 0, SEEK_END);

    struct stat buf;
    fstat(fd, &buf);
    uint64_t file_size = buf.st_size;

    lseek(fd, page_id.page_number*VPage::SIZE, SEEK_SET);
    if (file_size/VPage::SIZE <= page_id.page_number) {
        // new file page, write zeros
        memset(bytes, 0, VPage::SIZE);
        auto write_res = ftruncate(fd, VPage::SIZE * (page_id.page_number + 1));

        if (write_res == -1) {
            throw std::runtime_error("Could not write into file");
        }
    } else {
        // reading existing file page
        auto read_res = read(fd, bytes, VPage::SIZE);
        if (read_res == -1) {
            throw std::runtime_error("Could not read file page");
        }
    }
}


void FileManager::read_existing_page(PageId page_id, char* bytes) const {
    static_assert((VPage::SIZE == UPage::SIZE) && (VPage::SIZE == TensorPage::SIZE),
                  "read_existing_page used for VPage, UPage and TensorPage");

    auto fd = page_id.file_id.id;

#ifndef NDEBUG
    struct stat buf;
    fstat(fd, &buf);
    uint64_t file_size = buf.st_size;
    assert(page_id.page_number < file_size/VPage::SIZE);
#endif

    // reading existing file page
    lseek(fd, page_id.page_number*VPage::SIZE, SEEK_SET);
    auto read_res = read(fd, bytes, VPage::SIZE);
    if (read_res == -1) {
        throw std::runtime_error("Could not read file page");
    }
}


uint32_t FileManager::append_page(FileId file_id, char* bytes) const {
    static_assert((VPage::SIZE == UPage::SIZE) && (VPage::SIZE == TensorPage::SIZE),
                "append_page used for both VPage, UPage and TensorPage");

    auto fd = file_id.id;
    auto page_number = lseek(fd, 0, SEEK_END) / VPage::SIZE;

    // fill the new page with zeros
    memset(bytes, 0, VPage::SIZE);
    auto write_res = write(fd, bytes, VPage::SIZE);

    if (write_res == -1) {
        throw std::runtime_error("Could not write into file");
    }

    return page_number;
}


FileId FileManager::get_file_id(const string& filename) {
    auto search = filename2file_id.find(filename);
    if (search != filename2file_id.end()) {
        return search->second;
    } else {
        const auto file_path = get_file_path(filename);

        auto fd = open(file_path.c_str(), O_RDWR/*|O_DIRECT*/|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
        if (fd == -1) {
            throw std::runtime_error("Could not open file " + file_path);
        }
        const auto res = FileId(fd);
        filename2file_id.insert({ filename, res });
        return res;
    }
}


TmpFileId FileManager::get_tmp_file_id() {
    std::FILE* tmp_file = std::tmpfile();
    auto fd = fileno(tmp_file);
    if (fd == -1) {
        throw std::runtime_error("Could not open tmp file");
    }
    return TmpFileId(get_query_ctx().thread_info.worker_index, FileId((fd)));
}


void FileManager::remove_tmp(const TmpFileId tmp_file_id) {
    buffer_manager.remove_tmp(tmp_file_id); // clear pages from buffer_manager
    close(tmp_file_id.file_id.id);          // close the file stream, file will be removed
}
