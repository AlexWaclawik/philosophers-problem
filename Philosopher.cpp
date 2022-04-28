//will be the main things running and each philosopher thread will have two threads-a changer and a runner
//runner will collect the forks and distribut the forkes according to the rules 
//changer will work with runner(not sure exactly but I have a diagram from his class)


//philospher basically just has a while loop where it acquires forks
//aquire forks means it is HUNGRY where it will be until it has both forks via changer
//then eats**in critical section
//then realses forks
//then restss for an exponential time
//#include <iostream>
//#include <thread>
//#include <sys/time.h>
//#include <math.h>
#include "Philosopher.h"
//#include <vector>
//#include "Mailbox.h"


Philosopher::Philosopher(int givenID, int* array, Mailbox* mail){
    id = givenID;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] != -1) {
            neighbors.emplace_back(array[i]);
        }
    }
    notDone = true;//main loop for philosopher
    notifyBool = true;//true means stay in entry section
    state = "HUNGRY";//state begins at hungry
    changer= new Changer();//create changer
     //will end when notDoneChange is called
}

Philosopher::~Philosopher(){

}

void Philosopher::giveToken(int giveID){
    changer->giveToken(giveID);
}

void Philosopher::giveFork(int giveID){
    changer->giveFork(giveID);
}

void Philosopher::thinking() {
    this->state = "THINKING";
    this->changer->stateChange(state);//tells changer taht the state has been changed
    this->release();
    sleep(this->getRandomTime());//sleeps for a random time while THINKING
}

void Philosopher::eating() {
    this->state = "EATING";
    change->stateChange(state);//tells changer that the state has been changed this 
    sleep(this->getRandomTime());//sleeps for a random time while EATING
}

float Philosopher::getRandomTime() {
    srand(time(0));
    float random = (std::rand());
    float r = (random) / (RAND_MAX);
    float notYet = -log(r);
    notYet = notYet * 1000;
    int done = (int)notYet;
    return done;
}

void Philosopher::start() {
    while (notDone) {
        this->changer->aquire();//tells changer to aquire 
        while (this->notify()) {//stuck in entry section until changer tells philosopher that it has gotten the forks
            sleep(50);//sleep for 50 miliseconds
        }
        this->eating();
        this->thinking();
    }
}

bool Philosopher::notify()
{
    return notifyBool;
}

bool Philsopher::notify() {
    return notifyBool;
}

void Philosopher::changeNotify(bool check) {
    this->notifyBool = check;
}

void Philosopher::release() {
    this->changer->release();
    this->notifyBool = false;
}

void Philosopher::notDoneChange() {
    notDone = false;
}

std::string Philosopher::getState() {
    return state;
}