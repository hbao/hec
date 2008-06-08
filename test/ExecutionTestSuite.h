#include <cxxtest/TestSuite.h>

#include "VM.h"

class ExecutionTestSuite : public CxxTest::TestSuite {
public:
	void testInitializeInstructionPointer() {
		VM vm;
		TS_ASSERT_EQUALS(vm.IP, vm.BS);
	}
	
	void testInsertInstruction() {
		VM vm;
		U1 * instruction = createLBIInstruction(0, 7);
		vm.insertInstruction(instruction);
		TS_ASSERT_EQUALS(3, vm.IP - vm.BS);
		delete[] instruction;
	}
	
	void testLBI() {
		VM vm;
		TS_ASSERT_EQUALS(0, vm.R[0])
		
		U1* instruction = createLBIInstruction(0, 7);
		vm.insertInstruction(instruction);
		vm.execute();
		TS_ASSERT_EQUALS(7, vm.R[0])
		TS_ASSERT_EQUALS(vm.IP, vm.BS);

		delete[] instruction;
	}
	
	void testMultipleLBIs() {		
		U1 instructions[7];
		instructions[0] = LBI;
		instructions[1] = 1;
		instructions[2] = 3;
		instructions[3] = LBI;
		instructions[4] = 2;
		instructions[5] = 4;
		instructions[6] = EOF;
		
		VM vm;
		vm.insertInstruction(instructions);
		vm.execute();
		
		TS_ASSERT_EQUALS(3, vm.R[1]);
		TS_ASSERT_EQUALS(4, vm.R[2]);
	}
	
	void testCannotExecuteUnrecognizedInstruction() {
		U1 * instruction = createLBIInstruction(0, 0);
		instruction[0] = UNKNOWN;
		
		VM vm;
		vm.disableDebug();
		vm.insertInstruction(instruction);
		TS_ASSERT_THROWS(vm.execute(), U1);
		TS_ASSERT_EQUALS(3, vm.IP - vm.BS);
		
		delete[] instruction;
	}
	
private:
	U1 * createLBIInstruction(U1 register_number, U2 value) {
		U1 * lbi_instruction = new U1[4];
		lbi_instruction[0] = LBI;
		lbi_instruction[1] = register_number;
		lbi_instruction[2] = value;
		lbi_instruction[3] = EOF;
		return lbi_instruction;
	}
};
