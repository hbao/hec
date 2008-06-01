#include "VM.h"

VM::VM() {
	VM(1024, 1024, 4096);
}

VM::VM(int stack_size, int heap_size, int text_size) {
	RAM = 0;
	BE = HS = text_size;
	HE = SS = HS + heap_size;
	TOP = SS + stack_size;
}