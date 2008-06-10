#ifndef _HEC_INSTRUCTIONS_LBI_HANDLER
#define _HEC_INSTRUCTIONS_LBI_HANDLER 1

#include "InstructionHandler.h"

class LBIHandler : public InstructionHandler {
public:
	LBIHandler(U1 * ram, U4 ip, U4 * r) : InstructionHandler(ram, ip, r) {};
	virtual int execute() {
		U1 register_number = RAM[IP - 1];
		U1 value = RAM[IP - 2];
		R[register_number] = value;
		return 2;
	}
};

#endif