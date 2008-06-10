#ifndef _HEC_INSTRUCTIONS_INSTRUCTION_HANDLER
#define _HEC_INSTRUCTIONS_INSTRUCTION_HANDLER 1

#include "../DataTypes.h"

class InstructionHandler {
public:
	virtual ~InstructionHandler(){};
	virtual int execute(U1 * RAM, U4 IP, U4 * R) = 0;
};

#endif