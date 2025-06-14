#include "fileUtils.h"

namespace photon {
	
	std::string readFile(const char* path) {
		FILE* file = fopen(path, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);

		char* data = new char[length + 1];
		memset(data, 0, length + 1);

		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);
		fclose(file);

		std::string result(data);
		delete[] data;
		return result;
	}
}