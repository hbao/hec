#ifndef _HEC_INSTRUCTIONS_INSTRUCTION_HANDLER
#define _HEC_INSTRUCTIONS_INSTRUCTION_HANDLER 1

#include "../DataTypes.h"

class InstructionHandler {
public:
	InstructionHandler(U1 * ram, U4 ip, U4 * r) : RAM(ram), IP(ip), R(r) {};
	virtual ~InstructionHandler(){};
	virtual int execute() = 0;
	
protected:
	U1 * RAM;
	U4 IP;
	U4 * R;
};

#endif