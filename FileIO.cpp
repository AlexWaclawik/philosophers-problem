#include <iostream>
#include <fstream>
#include <string>
#include "FileIO.h"


std::string FileIO::readFile(int lineToRead){
  std::ifstream inFile;
  inFile.open("input.txt");
  std::string lineRead = "";
  for(int i = 0; i < lineToRead; i++){
    std::getline(inFile, lineRead);
  }//end for(i)
  std::getline(inFile, lineRead);
  inFile.close();
  return(lineRead);
}//end readFile function


//added comments to help with pseudocodes version of the code
std::string FileIO::appendString(std::string input, std::string totalString){
    std::string end = input + "|" + totalString;
    return end;
}

FileIO::FileIO(){
  std::ifstream inFile;
  totalString = "";
  std::string appString = "";
  int line = 0;
  int totalNodeNum = 0;
  inFile.open("input.txt");
  while(getline(inFile, appString)){
    totalNodeNum++;
  }//end length finder
  inFile.close();
  appString = "";
  //vect = vect(totalNodeNum, std::vector<int> (totalNodeNum, 0));
  while(line < totalNodeNum){
    appString = readFile(line);//format with Node: Connection, Connection, etc
    totalString = appendString(appString, totalString);
    line = line + 1;
  }//end while
}//end main

FileIO::~FileIO(){

}