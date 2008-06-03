#ifndef _HEC_FILE_UTIL
#define _HEC_FILE_UTIL 1

#include <fstream>

class FileUtil {
public:
	U1 * loadHECFile(const char * file_path) {
		int file_length = getFileLength(file_path);
		return getFileContent(file_path, file_length);
	};
	
private:
	int getFileLength(const char * file_path) {
		ifstream hec_file(file_path, ios::in|ios::binary);
		long start = hec_file.tellg();
		hec_file.seekg (0, ios::end);
		long end = hec_file.tellg();
		int file_length = end-start;
		hec_file.close();
		return file_length;
	};
	
	U1 * getFileContent(const char * file_path, int size) {
		ifstream hec_file(file_path, ios::in|ios::binary);
		
		U1 header[2];
		header[0] = hec_file.get();
		header[1] = hec_file.get();
		U2 magic_number = 0xDEED;
		if(!memcmp(header, (char*)&magic_number, 2)) {
			printf("\nValidation ERROR -- %s\n", file_path);
			throw "Invalid HEC File";
		}
		
		return loadInstructionSection(hec_file, size - 2);
	}
	
	U1 * loadInstructionSection(ifstream & hec_file, int size) {
		U1 * bytes = new U1[size + 1];
		for(int i = 0; i < size; i++) {
			bytes[i] = hec_file.get();
		}
		hec_file.close();
		bytes[size] = EOF;
		return bytes;
	}
};

#endif