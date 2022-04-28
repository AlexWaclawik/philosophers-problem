
#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include <fstream>
#include "Philosopher.h"


class Runner {
    private:
        Philosopher *phil;//will be a pointer to the parent philsopher
        std::string state;//will be the state that the philsoopher is in
        std::string msg;//string which will hold the two character code
        bool keepGoing = true;//boolean telling the runner to continue the loop
        int recievedFromID;
    public:
        Runner();
        Runner(Philosopher*);//constructor to be used normally
        ~Runner();
};

#endif
