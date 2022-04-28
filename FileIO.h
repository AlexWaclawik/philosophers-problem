
#ifndef FILEIO_H_EXISTS
#define FILEIO_H_EXISTS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class FileIO {
    private:
		std::vector<std::vector<int>> vect; 
        
	public:
        FileIO();
        ~FileIO();
        std::vector<std::vector<int>> getVector();
        std::string readFile(int);
        void parseString(std::string, std::vector<std::vector<int>>&);
};

#endif