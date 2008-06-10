#include "VM.h"
#include "handlers/LBIHandler.h"
#include "handlers/LADHandler.h"
#include "handlers/LAIHandler.h"
#include "handlers/LBHandler.h"
#include "handlers/SBHandler.h"
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
	
	handlers[LBI] = new LBIHandler();
	handlers[LAD] = new LADHandler();
	handlers[LAI] = new LAIHandler();
	handlers[LB] = new LBHandler();
	handlers[SB] = new SBHandler();
}

VM::~VM() {
	delete[] RAM;
	
	map<U1, InstructionHandler*>::iterator it;
	for(it = handlers.begin(); it != handlers.end(); it++) {
		delete it->second;
	}
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
	try {
		IP -= getInstructionHandler(cmd) -> execute(RAM, IP, R, HS, SS); 
	} catch (U1 cmd) {
		IP ++;
		throw cmd;
	}
}

InstructionHandler * VM::getInstructionHandler(U1 cmd) {
	map<U1, InstructionHandler*>::iterator it = handlers.find(cmd);
	if(it == handlers.end()) {
		DEBUG("\nUnrecognized command : %d\n", cmd)
		throw cmd;
	}
	return it->second;
}