#include "VM.h"

#include <cstring>

VM::VM() {
	initialize(1024, 1024, 4096);
}

VM::VM(int stack_size, int heap_size, int text_size) {
	initialize(stack_size, heap_size, text_size);
}

void VM::initialize(int stack_size, int heap_size, int text_size) {
	int memory_size = stack_size + heap_size + text_size;
	RAM = new U1[memory_size];
	memset(RAM, 0, memory_size * sizeof(U1));
	
	memset(R, 0, 8);
	
	BS = 0;
	BE = HS = text_size;
	HE = SS = HS + heap_size;
	TOP = SS + stack_size;
}

VM::~VM() {
//	it causes an error message on Mac OS X
//	delete[] RAM;
}

U1 VM::read(int index) {
	return RAM[index];
}

void VM::write(int index, U1 value) {
	RAM[index] = value;
}
