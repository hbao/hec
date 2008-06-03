#ifndef _HEC_INSTRUCTIONS_LBI_HANDLER
#define _HEC_INSTRUCTIONS_LBI_HANDLER 1

#include "InstructionHandler.h"

class LBIHandler : InstructionHandler {
public:
	LBIHandler(U1 * ram, U4 ip, U4 * r) : RAM(ram), IP(ip), R(r) {};
	virtual int execute();
	
private:
	U1 * RAM;
	U4 IP;
	U4 * R;
};

#endif