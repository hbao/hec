ROOT_DIR = $(shell pwd)

SRC_DIR = $(ROOT_DIR)/src
TEST_DIR = $(ROOT_DIR)/test
LIB_DIR = $(ROOT_DIR)/lib
GEN_DIR = $(ROOT_DIR)/gen
BIN_DIR = $(ROOT_DIR)/bin

CXX_TEST_DIR = ${LIB_DIR}/cxxtest
INCLUDE_OPTIONS = -I ${CXX_TEST_DIR} -I ${TEST_DIR} -I ${SRC_DIR}

TEST_FILES = $(shell find $(TEST_DIR) -name *.h)
TEST_SUITES = $(TEST_FILES:$(TEST_DIR)/%.h=%)

all: clean test

.PHONY: clean compile_tests test

clean:
	rm -rf ${GEN_DIR}

compile_tests:
	mkdir -p ${GEN_DIR}
	mkdir -p ${BIN_DIR}
	
	@for suite in $(TEST_SUITES); do \
		(echo Generating test runner from $${suite} ...); \
		(cd ${TEST_DIR} && ${CXX_TEST_DIR}/cxxtestgen.pl --error-printer -o ${GEN_DIR}/$${suite}_runner.cpp $${suite}.h); \
		(g++ ${INCLUDE_OPTIONS} -o ${BIN_DIR}/$${suite}_runner ${GEN_DIR}/SampleTestSuite_runner.cpp); \
	done

test: compile_tests
	@for suite in $(TEST_SUITES); do \
		(${BIN_DIR}/$${suite}_runner); \
	done