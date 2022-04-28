//chagner will tell philosopher that it has both forks and it can eat
//this does the sending and recieving of forks via the Mailbox using send and recieve
//the messages to be sent hold the details about the forks and tokens
//send(sid, rid, "|fork|token|")
//0,0 meaning no fork and no token(will not happen)
//0,1 no fork but a token
//1,0 a fork but no token
//1,1 token and fork
//when the forke is cleaned that means that it will be used right away always recieves a dirty fork

//will contain information about which other philosophers it will talk to LEFT and RIGHT
//will also ahve array containing inforamtion abot where the tokens and forks are both LEFT and RIGHT {0,0,0,0} would mean that the philosopher has neither fork nor token for both 

#include "Changer.h"

// constructor
Changer::Changer() {
	
}

// destructor
Changer::~Changer() {
	
}

// acquire fork
void Changer::acquire(void) {
	
}

// change current state
void Changer::stateChange(std::string newState) {
	this->currentState = newState;
}

// release fork
void Changer::release(void) {
	
}