#include <cxxtest/TestSuite.h>

#include "VM.h"

class EnvironmentTestSuite : public CxxTest::TestSuite {
public:
	void testCreateVirtualMachine(void) {
		VM vm;
	}
	
	void testInitializeMemoryLayout(void) {
		VM vm(1024, 1024, 2048);
		TS_ASSERT_EQUALS(4096, vm.TOP - vm.RAM);
		TS_ASSERT_EQUALS(2048, vm.BE - vm.RAM);
		TS_ASSERT_EQUALS(vm.BE, vm.HS);
		TS_ASSERT_EQUALS(1024, vm.HE - vm.HS);
		TS_ASSERT_EQUALS(vm.HE, vm.SS);
	}
};
