#include "LBIHandler.h"

int LBIHandler::execute() {
	U1 register_number = RAM[IP - 1];
	U1 value = RAM[IP - 2];
	R[register_number] = value;
	return 2;
}
