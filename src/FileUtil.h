#ifndef _HEC_FILE_UTIL
#define _HEC_FILE_UTIL 1

#include <fstream>

class FileUtil {
public:
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