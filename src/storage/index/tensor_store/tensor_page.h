#pragma once

#include <atomic>
#include <cassert>

#include "storage/page/page_id.h"

/* TensorPage is an adaptation of the regular Page class from src/storage/page.h, specifically for handling tensor files
 * and interact with the TensorBufferManager
 */
class TensorPage {
    friend class TensorBufferManager;
    friend class FileManager;

public:
    static constexpr size_t SIZE = 4096;

    // contains file_id and page_number of this page
    PageId page_id;

    // mark as dirty so when page is replaced it is written back to disk
    inline void make_dirty() noexcept { dirty = true; }

    // get the start memory position of `SIZE` allocated bytes
    inline char* get_bytes() const noexcept { return bytes; }

    inline uint32_t get_page_number() const noexcept { return page_id.page_number; }

private:
    // Start memory address of the page
    char* bytes;

    // Count of objects using this page, modified only by buffer_manager
    std::atomic<uint32_t> pins;

    // Used by the replacement policy
    bool second_chance;

    // True if data in memory is different from disk
    bool dirty;

    TensorPage() noexcept :
        page_id       (FileId(FileId::UNASSIGNED), 0),
        bytes         (nullptr),
        pins          (0),
        second_chance (false),
        dirty         (false) { }

    void pin() noexcept {
        pins++;
        second_chance = true;
    }

    void unpin() noexcept {
        assert(pins > 0 && "Cannot unpin if pin count is 0");
        pins--;
    }

    void set_bytes(char* bytes) {
        this->bytes = bytes;
    }

    // Only meant for buffer_manager.remove()
    void reset() noexcept {
        assert(pins == 0 && "Cannot reset page if it is pinned");
        this->bytes         = nullptr;
        this->page_id       = PageId(FileId(FileId::UNASSIGNED), 0);
        this->pins          = 0;
        this->second_chance = false;
        this->dirty         = false;
    }

    void reassign(PageId page_id) noexcept {
        assert(!dirty && "Cannot reassign page if it is dirty");
        assert(pins == 0 && "Cannot reassign page if it is pinned");
        assert(second_chance == false && "Should not reassign page if second_chance is true");

        this->page_id       = page_id;
        this->pins          = 1;
        this->second_chance = true;
    }

    // Reassign without preventing this page from immediately being replaced, because the preload will fill the buffer
    void reassign_preload(PageId page_id) noexcept {
        assert(!dirty && "Cannot reassign page if it is dirty");
        assert(pins == 0 && "Cannot reassign page if it is pinned");
        assert(second_chance == false && "Should not reassign page if second_chance is true");

        this->page_id = page_id;
    }
};
