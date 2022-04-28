#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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
void FileIO::parseString(std::string input, std::vector<std::vector<int>> &dataArray){
    std::stringstream ss;
    std::string delimiter1 = ":";
    std::string delimiter2 = ",";
    int nodeNumber = 0;
    int nConnector;
    std::string temp;
    //int nodevals[4];
    temp = input.substr(0,input.find(delimiter1));
    ss << temp;
    ss >> nodeNumber;
    //nodevals[0] = nodeNumber;
    ss = std::stringstream();
    input.erase(0, input.find(delimiter1) + delimiter1.length());
    //std::cout << "Node: " << nodeNumber << std::endl;
    bool keepGoing = true;
    dataArray[nodeNumber - 1][0] = nodeNumber;
    int count = 1;
    while(keepGoing){
        if((input.find(delimiter2) == std::string::npos)){
            keepGoing = false;
        }
        temp = input.substr(0,input.find(delimiter2));
        ss << temp;
        ss >> nConnector;
        ss = std::stringstream();
        dataArray[nodeNumber - 1][count] = nConnector;
        count++;
        input.erase(0, input.find(delimiter2) + delimiter2.length());
        //std::cout <<"Connected to:" << nConnector << std::endl;
        //nodevals[count] = nConnector;
    }

}

FileIO::FileIO(){
  std::ifstream inFile;
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
  std::vector<std::vector<int>> vect(totalNodeNum, std::vector<int> (totalNodeNum, 0));
  
  while(line < totalNodeNum){
    appString = readFile(line);//format with Node: Connection, Connection, etc
    //std::cout << appString<<std::endl;
    parseString(appString, vect);
    line = line + 1;
  }//end while
	for(int i = 0; i < totalNodeNum;i++){
      for(int j = 0; j < totalNodeNum; j++){
        std::cout << vect[i][j]<<std::endl;
      }
      std::cout << "End of " << i + 1 << " node"<<std::endl;
  }
}//end main

FileIO::~FileIO(){

}

std::vector<std::vector<int>> FileIO::getVector(){
    //std::cout << vect[0][0];
	return vect;
}