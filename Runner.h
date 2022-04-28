
#ifndef RUNNER_H
#define RUNNER_H

//#include <string>
//#include <fstream>
//#include "Philosopher.h"
#include <thread>
#include <iostream>


class Runner {
private:
    Philosopher* phil;//will be a pointer to the parent philsopher
	Changer & parentChanger;
    std::string state;//will be the state that the philsoopher is in
    std::string msg;//string which will hold the two character code
    bool keepGoing = true;//boolean telling the runner to continue the loop
    int recievedFromID;
	Mailbox mail;
public:
    void Runner();
    void Runner(Philosopher*);//constructor to be used normally
    void ~Runner();
	void setState(std::string);
};

#endif
