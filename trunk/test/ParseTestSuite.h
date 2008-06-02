#include <cxxtest/TestSuite.h>

#include "VM.h"

class ParseTestSuite : public CxxTest::TestSuite {
public:
	void testLoadInstructionsFromHECFile() {
		VM vm;
		vm.load("test/LBI.hec");
		vm.execute();
		TS_ASSERT_EQUALS(7, vm.R[1]);
		TS_ASSERT_EQUALS(5, vm.R[2]);
	}
};
