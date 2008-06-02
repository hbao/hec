ROOT_DIR = $(shell pwd)

SRC_DIR = $(ROOT_DIR)/src
OBJ_DIR = $(ROOT_DIR)/obj
TEST_DIR = $(ROOT_DIR)/test
LIB_DIR = $(ROOT_DIR)/lib
GEN_DIR = $(ROOT_DIR)/gen
BIN_DIR = $(ROOT_DIR)/bin

SRC_SUB_DIRS = handlers

CXX_TEST_DIR = ${LIB_DIR}/cxxtest
INCLUDE_OPTIONS = -I ${CXX_TEST_DIR} -I ${TEST_DIR} -I ${SRC_DIR}

TEST_FILES = $(shell find $(TEST_DIR) -name *.h)
TEST_SUITES = $(TEST_FILES:$(TEST_DIR)/%.h=%)
TEST_GENERATED_FILES = $(TEST_SUITES:%=$(GEN_DIR)/%_runner.cpp)
TEST_RUNNERS = $(TEST_SUITES:%=$(BIN_DIR)/%_runner)

SRC_FILES = $(shell find $(SRC_DIR) -name *.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: clean test

all: clean test

$(TEST_GENERATED_FILES):$(GEN_DIR)/%_runner.cpp:$(TEST_DIR)/%.h
	cd ${TEST_DIR} && ${CXX_TEST_DIR}/cxxtestgen.pl --error-printer -o $@ $<

$(TEST_RUNNERS):$(BIN_DIR)/%:$(GEN_DIR)/%.cpp
	g++ ${INCLUDE_OPTIONS} ${OBJ_FILES} -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -o $@ -c $<

test: $(OBJ_FILES) $(TEST_RUNNERS)
	@for suite in $(TEST_SUITES); do \
		${BIN_DIR}/$${suite}_runner; \
	done

clean:
	rm -rf $(GEN_DIR) && mkdir -p $(GEN_DIR)
	rm -rf $(BIN_DIR) && mkdir -p $(BIN_DIR)
	rm -rf $(OBJ_DIR) && mkdir -p $(OBJ_DIR)
	@for subdir in $(SRC_SUB_DIRS); do \
		mkdir -p $(OBJ_DIR)/$${subdir} ; \
	done