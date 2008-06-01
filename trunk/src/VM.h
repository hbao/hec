#ifndef _HEC_VM
#define _HEC_VM 1

class VM {
public:
	int RAM, BE, HS, HE, SS, TOP;
	VM();
	VM(int stack_size, int heap_size, int text_size);
};

#endif