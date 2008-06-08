#ifndef _HEC_INSTRUCTIONS_LAI_HANDLER
#define _HEC_INSTRUCTIONS_LAI_HANDLER 1

#include "InstructionHandler.h"

class LAIHandler : InstructionHandler {
public:
	LAIHandler(U1 * ram, U4 ip, U4 * r) : RAM(ram), IP(ip), R(r) {};
	virtual int execute() {
		U1 result_register_number = RAM[IP - 1];
		U1 offset_register_number = RAM[IP - 2];
		U1 value[4];
		for(int i = 0; i < 4; i++) {
			value[i] = RAM[IP - 3 - i];
		}
		memcpy(R + result_register_number * sizeof(U4), value, sizeof(U4));
		R[result_register_number] += R[offset_register_number];
		return 6;
	};
	
private:
	U1 * RAM;
	U4 IP;
	U4 * R;
};

#endif