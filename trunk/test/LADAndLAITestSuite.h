#include <cxxtest/TestSuite.h>

#include "VM.h"

class LADAndLAITestSuite : public CxxTest::TestSuite {
public:
	void testLADShouldPutAddressIntoRegister() {
		U1 instruction[7];
		instruction[0] = LAD;
		instruction[1] = 0;
		U4 address = 0x01020304;
		memcpy(instruction + 2, (U1*)&address, 4);
		instruction[6] = EOF;
		
		VM vm;
		vm.insertInstruction(instruction);
		vm.execute();
		
		TS_ASSERT_EQUALS(address, vm.R[0]);
	}
	
	void testLAIShouldPutAddressAndOffsetIntoRegister() {
		U1 instruction[8];
		instruction[0] = LAI;
		instruction[1] = 0;
		instruction[2] = 1;
		U4 address = 0x01020300;
		memcpy(instruction + 3, (U1*)&address, 4);
		instruction[7] = EOF;
		
		VM vm;
		vm.R[1] = 0x04;
		vm.insertInstruction(instruction);
		vm.execute();
		
		TS_ASSERT_EQUALS(0x01020304, vm.R[0]);
	}
};
