#ifndef _HEC_INSTRUCTIONS_LAD_HANDLER
#define _HEC_INSTRUCTIONS_LAD_HANDLER 1

#include "InstructionHandler.h"

class LADHandler : public InstructionHandler {
public:
	virtual int execute(U1 * RAM, U4 IP, U4 * R, U4 HS, U4 SS) {
		U1 register_number = RAM[IP - 1];
		U1 value[4];
		for(int i = 0; i < 4; i++) {
			value[i] = RAM[IP - 2 - i];
		}
		memcpy(R + register_number * sizeof(U4), value, sizeof(U4));
		return 5;
	};
};

#endif