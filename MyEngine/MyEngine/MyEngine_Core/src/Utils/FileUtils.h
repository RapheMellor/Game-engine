#pragma once

//Include string path to be able to recognise file names
#include <string>

namespace MyEngine {

	class FileUtils
	{
		//Public functions
	public:
		static std::string read_file(const char* filepath)
		{
			//Open a file and read text
			FILE* file = fopen(filepath, "rt");
			//Look for the end of the file
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			//Read characters in the file until there are no more to read
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			//Read the file for the length of data
			fread(data, 1, length, file);
			//Close the file
			fclose(file);

			std::string result(data);
			//Delete data once it has been used
			delete[] data;
			return result;
		}
	};

}