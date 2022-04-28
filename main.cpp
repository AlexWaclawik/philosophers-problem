//will make and start the philosophers also will give eah pilosopher a fork not wure how to give the corect amount of tokens
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include "Mailbox.h"
#include "Philosopher.h"
#include "Runner.h"
#include "Changer.h"
#include "FileIO.h"



int main() {
	FileIO file = new FileIO();
    std::string fileInfo = file.getString();
    std::vector<std::vector<int>> vectorInt = parseString(fileInfo);
    std::vector<std::thread> vectorPhilosopher;
    int values[vectorInt.size()];
    int philospherID = 0;
    for (int i = 0; i < vectorInt.size(); i++) {
        philosopherID = vectorInt[i][0];
        for (int j = 0; j < vectorInt.size(); j++) {
            values[j] = vectorInt[i][j];
        }
        vectorPhilosopher.emplace_back(Philosopher, values);
    }
}

std::vector parseString(std::string input) {
    std::string modify = input;
    std::string delimiter1 = ":";
    std::string delimiter2 = ",";
    std::string delimiter3 = "|";
    char ch1 = '|';
    char ch2 = ',';
    int numberOfPhilosophers = std::count(modify.begin(), modify.end(), ch);
    int philosopherNumber;
    std::vector<std::vector<int>> vectorInt(numberOfPhilosophers, std::vector<int>(numberOfPhilosophers, 0));
    std::stringstream ss;
    std::string temp;
    bool keepGoing1 = true;
    bool keepGoing2 = true;
    
    int vector1DLocation = 0;
    int vector2DLocation = 1;
    int vector2DNum = 0;
    std::string subset = "";
    while (keepGoing1) {
        if ((std::count(modify.begin(), modify.end(), ch1)) == 0) {
            keepGoing1 = false;
        }
        ss = std::stringstream();
        temp = "";
        temp = modify.substr(0, modify.find(delimiter1));
        ss << temp;
        ss >> philosopherNumber;
        ss = std::stringstream();
        vectorInt[vector1DLocation][0] = philosopherNumber;


        modify.erase(0, input.find(delimiter1) + delimiter1.length());
        

        keepGoing2 = true;
        vector2DLocation = 1;
        subset = modify.substr(0, modify.find(delimiter3));
        while (keepGoing2) {
            if ((std::count(subset.begin(), subset.end(), ch2)) == 0) {
                temp = subset.substr(0, 1);

                ss = std::stringstream();
                ss << temp;
                ss >> vector2DNum;
                ss = std::stringstream();

                vectorInt[vector1DLocation][vector2DLocation] = vector2DNum;
                keepGoing2 = false;
            }
            else {
                temp = input.substr(0, input.find(delimiter2));

                ss = std::stringstream();
                ss << temp;
                ss >> vector2DNum;
                ss = std::stringstream();

                vectorInt[vector1DLocation][vector2DLocation] = vector2DNum;
                subset.erase(0, subset.find(delimiter2) + delimiter2.length());
                vector2DLocation++;
            }
        }
        if ((std::count(modify.begin(), modify.end(), ch1)) != 0) {
            modify.erase(0, input.find(delimiter3) + delimiter3.length());
        }
        vector1DLocation++;
    }
    return vectorInt;
}