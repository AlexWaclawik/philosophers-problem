
#ifndef PHILOSOPHER.H
#define PHILOSOPHER_H

#include <iostream>
#include <thread>
#include <sys/time.h>
#include <math.h>
#include <Philosopher.h>
#include <Runner.h>
#include <Changer.h>


class Philosopher {
private:
    bool notDone;//boolean used to keep the loop going can be ended via notDoneChange()
    bool notifyBool;//entry section boolean
    std::string state;//string for state of philosopher
    Changer changer;//changer
    int id;
    std::vector<int> neighbors;
public:
    Philosopher(int*);//create philsopher and begin the loop
    ~Philosopher();
    void thinking();
    void eating();
    float getRandomTime();//gets random time to sleep and what not
    bool notify();//allows the philsopher to access the notifyBool boolean might be able to be removed
    void changeNotify(bool check);//will allow philosopher to exit the entry section and begin eating
    void release();
    std::string getState();//will contact changer to let it know that the forks can now be released to other philosophers
    void notDoneChange();//will be accessed from main.cpp to end the whole loop
    void start();
    void giveFork(int);
    void giveToken(int);
};

#endif
