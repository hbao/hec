#ifndef _HEC_INSTRUCTIONS_LB_HANDLER
#define _HEC_INSTRUCTIONS_LB_HANDLER 1

#include "InstructionHandler.h"

class LBHandler : public InstructionHandler {
public:
	virtual int execute(U1 * RAM, U4 IP, U4 * R, U4 HS, U4 SS) {
		U1 target_register_number = RAM[IP - 1];
		U1 address_register_number = RAM[IP - 2];
		U1 address_to_get = R[address_register_number];
		R[target_register_number] = RAM[HS + address_to_get];
		return 2;
	}
};

#endif