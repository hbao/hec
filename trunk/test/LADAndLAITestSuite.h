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
};
