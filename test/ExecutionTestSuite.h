#include <cxxtest/TestSuite.h>

#include "VM.h"

class ExecutionTestSuite : public CxxTest::TestSuite {
public:
	void testInitializeInstructionPointer() {
		VM vm;
//		TS_ASSERT_EQUALS(vm.IP, vm.BS);
	}
};
