#ifndef CHANGER_H_
#define CHANGER_H_

#include "Runner.h"
#include <iostream>

class Changer {
	
	private:
		Runner runner;
	public:
		Changer();
		~Changer();
		void acquire();
		void stateChange(std::string newState);
		void release();
};

#endif
