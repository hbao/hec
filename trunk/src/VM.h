#ifndef _HEC_VM
#define _HEC_VM 1

#include <string>
using namespace std;

#include "DataTypes.h"
#include "Commands.h"

#define DEBUG(format, ...) if(should_debug){printf(format, __VA_ARGS__);}

class VM {
public:
	U4 BS, BE, HS, HE, SS, TOP;
	U4 IP;
	U4 R[8];

	VM();
	VM(int stack_size, int heap_size, int text_size);
	virtual ~VM();
	
	void load(const char * file_path);
	U1 read(int index);
	void write(int index, U1 value);
	void insertInstruction(U1 * bytes);
	void execute();
	
	void inspectInstructions();
	void disableDebug() { should_debug = false; }
private:
	U1 * RAM;
	
	void initialize(int stack_size, int heap_size, int text_size);
	void executeCurrentInstruction();
	
	void debug(const char * str, ...);
	bool should_debug;
};

#endif