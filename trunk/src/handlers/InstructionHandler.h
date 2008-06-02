#ifndef HEC_INSTRUCTIONS_INSTRUCTION_HANDLER
#define HEC_INSTRUCTIONS_INSTRUCTION_HANDLER 1

#include "../DataTypes.h"

class InstructionHandler {
public:
	virtual ~InstructionHandler(){};
	virtual int execute() = 0;
};

#endif