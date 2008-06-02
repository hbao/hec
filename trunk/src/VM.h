#ifndef _HEC_VM
#define _HEC_VM 1

#include "DataTypes.h"

class VM {
public:
	int BS, BE, HS, HE, SS, TOP;

	VM();
	VM(int stack_size, int heap_size, int text_size);
	virtual ~VM();
	
	U1 read(int index);
	void write(int index, U1 value);

private:
	U1 * RAM;
	
	void initialize(int stack_size, int heap_size, int text_size);
};

#endif