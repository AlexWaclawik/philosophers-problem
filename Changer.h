#ifndef CHANGER_H_
#define CHANGER_H_

#include "Runner.h"
#include <iostream>

class Changer {
	
	private:
		Runner runner;
		std::string currentState;
		int sid;
		int rid;
		Mailbox* mail;
		int forkPos [4] = {}; 
	public:
		Changer();
		Changer(*philosopherPtr);
		~Changer();
		void acquire();
		void stateChange(std::string newState);
		void release();
};

#endif
