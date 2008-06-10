#include <cxxtest/TestSuite.h>

#include "VM.h"

class CommandsTestSuite : public CxxTest::TestSuite {
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
	
	void testLBShouldTakeByteAtAddressR2AndStoreInR1() {
		U1 instruction[4];
		instruction[0] = LB;
		instruction[1] = 0;
		instruction[2] = 1;
		instruction[3] = EOF;
		
		VM vm;
		vm.R[1] = 0;
		vm.write(vm.HS, 0xAB);
		vm.insertInstruction(instruction);
		vm.execute();
		
		TS_ASSERT_EQUALS(0xAB, vm.R[0]);
	}
	
	void testSBShouldPlaceByteInR1AtAddressInR2() {
		U1 instruction[4];
		instruction[0] = SB;
		instruction[1] = 0;
		instruction[2] = 1;
		instruction[3] = EOF;
		
		VM vm;
		vm.R[0] = 0xAB;
		vm.R[1] = 0x0A;
		vm.insertInstruction(instruction);
		vm.execute();
		
		TS_ASSERT_EQUALS(0xAB, vm.read(vm.HS + 0x0A));
	}
};
