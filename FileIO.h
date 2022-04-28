
#ifndef FILEIO_H_EXISTS
#define FILEIO_H_EXISTS

#include <iostream>
#include <fstream>
#include <string>

class FileIO {
    private:
        std::string totalString;
     public:
        FileIO();
        ~FileIO();
        std::string readFile(int);
        std::string appendString(std::string, std::string);
        std::string getString();
};

#endif