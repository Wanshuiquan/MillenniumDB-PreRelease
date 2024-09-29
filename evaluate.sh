#!/bin/bash
set -e; set -u; set -o pipefail
BLUE='\033[0;34m'; RED='\033[0;31m'; GREEN='\033[0;32m'; NC='\033[0m';
ERROR=false

VENV=$MDB_HOME/evaluation/.venv
TESTS=$MDB_HOME/evaluation

if ! diff -q $VENV/requirements.txt $TESTS/requirements.txt; then
    python3 -m venv $VENV
    source $VENV/bin/activate
    python3 -m pip install -r $TESTS/requirements.txt
    cp $TESTS/requirements.txt $VENV/requirements.txt
else
    source $VENV/bin/activate
fi

# Configure build and compile
cmake -B $MDB_HOME/build/Release -D CMAKE_BUILD_TYPE=Release
cmake --build $MDB_HOME/build/Release -j 16



# Remove MQL tmp dir
[[ -d  $TESTS/data/ ]] && echo -e ${BLUE}Removing  $TESTS/mql/tmp/${NC} && rm -r  $TESTS/data/facebook &&  rm -r  $TESTS/data/youtube && rm  $TESTS/data/youtube.qm

#manipulate_data
python3 $TESTS/script/evaluation.py


if [[ $ERROR ]]; then
    echo -e "${RED}TESTS FAILED${NC}"
    exit 1
else
    echo -e "${GREEN}ALL TESTS PASSED${NC}"
    exit 0
fi
