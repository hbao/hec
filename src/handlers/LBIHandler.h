#ifndef HEC_INSTRUCTIONS_LBI
#define HEC_INSTRUCTIONS_LBI 1

#include "InstructionHandler.h"

class LBIHandler : InstructionHandler {
public:
	LBIHandler(U1 * ram, int ip, U1 * r) : RAM(ram), IP(ip), R(r) {};
	virtual int execute();
	
private:
	U1 * RAM;
	int IP;
	U1 * R;
};

#endif