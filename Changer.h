#ifndef CHANGER_H_
#define CHANGER_H_

#include "Philosopher.h"
#include "Mailbox.h"
#include <iostream>

class Changer {
	
	private:
		std::string currentState;
		int sid;
		int rid;
		Mailbox* mail;
	public:
		Changer();
		~Changer();
		void acquire();
		void stateChange(std::string newState);
		void release();
};

#endif
