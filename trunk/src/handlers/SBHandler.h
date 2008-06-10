#ifndef _HEC_INSTRUCTIONS_SB_HANDLER
#define _HEC_INSTRUCTIONS_SB_HANDLER 1

#include "InstructionHandler.h"

class SBHandler : public InstructionHandler {
public:
	virtual int execute(U1 * RAM, U4 IP, U4 * R, U4 HS, U4 SS) {
		U1 value_register_number = RAM[IP - 1];
		U1 address_register_number = RAM[IP - 2];
		U1 address_to_put = R[address_register_number];
		RAM[address_to_put] = R[value_register_number];
		return 2;
	}
};

#endif