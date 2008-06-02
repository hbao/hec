#include <cxxtest/TestSuite.h>

#include "VM.h"

class EnvironmentTestSuite : public CxxTest::TestSuite {
public:
	void testCreateVirtualMachine(void) {
		VM vm;
	}
	
	void testInitializeMemoryLayout(void) {
		VM vm(1024, 1024, 2048);
		TS_ASSERT_EQUALS(0, vm.BS);
		TS_ASSERT_EQUALS(4096, vm.TOP - vm.BS);
		TS_ASSERT_EQUALS(2048, vm.BE - vm.BS);
		TS_ASSERT_EQUALS(vm.BE, vm.HS);
		TS_ASSERT_EQUALS(1024, vm.HE - vm.HS);
		TS_ASSERT_EQUALS(vm.HE, vm.SS);
	}
	
	void testInitializeGeneralRegisters(void) {
		VM vm;
		for(int i = 0; i < 8; i++) {
			TS_ASSERT_EQUALS(0, vm.R[i]);
		}
	}
	
	void testReadAndWriteMemory(void) {
		VM vm;
		TS_ASSERT_EQUALS(0, vm.read(vm.BS));
		vm.write(vm.BS, 1);
		TS_ASSERT_EQUALS(1, vm.read(vm.BS));
	}
};
