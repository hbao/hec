#include "VM.h"
#include "handlers/LBIHandler.h"
#include "handlers/LADHandler.h"
#include "handlers/LAIHandler.h"
#include "FileUtil.h"

#include <cstring>
#include <cstdio>

void VM::inspectInstructions() {
	printf("====== Inspecting Instructions ======\n");
	for(int i = IP; i >= BS; i--) {
		printf("%d : %d\n", i, RAM[i]);
	}
	printf("====== Done ======\n");
}

VM::VM() {
	initialize(1024, 4096, 1024);
}

VM::VM(int stack_size, int heap_size, int text_size) {
	initialize(stack_size, heap_size, text_size);
}

void VM::initialize(int stack_size, int heap_size, int text_size) {
	should_debug = true;
	
	int memory_size = stack_size + heap_size + text_size;
	RAM = new U1[memory_size];
	memset(RAM, 0, memory_size * sizeof(U1));
	
	memset(R, 0, 8 * sizeof(U4));
	
	BS = 0;
	BE = HS = text_size;
	HE = SS = HS + heap_size;
	TOP = SS + stack_size;
	
	IP = 0;
}

VM::~VM() {
	delete[] RAM;
}

void VM::load(const char * file_path) {
	FileUtil fileUtil;
	U1 * bytes = fileUtil.loadHECFile(file_path);
	insertInstruction(bytes);
	delete[] bytes;
}

U1 VM::read(int index) {
	return RAM[index];
}

void VM::write(int index, U1 value) {
	RAM[index] = value;
}

void VM::insertInstruction(U1 * bytes) {
	int length;
	for(length = 0; bytes[length] != (U1)EOF; length++) ;
	
	for(int i = length - 1; i >= 0; i--) {
		RAM[IP++] = bytes[i];
	}
}

void VM::execute() {
	while(IP > BS) {
		executeCurrentInstruction();
	}
}

void VM::executeCurrentInstruction() {
	U1 cmd = RAM[--IP];
	switch(cmd) {
		case LBI: {LBIHandler handler(RAM, IP, R); IP -= handler.execute();} break;
		case LAD: {LADHandler handler(RAM, IP, R); IP -= handler.execute();} break;
		case LAI: {LAIHandler handler(RAM, IP, R); IP -= handler.execute();} break;
		default: {
			IP++;
			DEBUG("\nUnrecognized command : %d\n", cmd)
//			inspectInstructions();
			throw cmd;
		}
	}
}