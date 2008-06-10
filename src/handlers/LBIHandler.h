#ifndef _HEC_INSTRUCTIONS_LBI_HANDLER
#define _HEC_INSTRUCTIONS_LBI_HANDLER 1

#include "InstructionHandler.h"

class LBIHandler : public InstructionHandler {
public:
	virtual int execute(U1 * RAM, U4 IP, U4 * R, U4 HS, U4 SS) {
		U1 register_number = RAM[IP - 1];
		U1 value = RAM[IP - 2];
		R[register_number] = value;
		return 2;
	}
};

#endif