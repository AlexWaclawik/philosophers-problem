//will take in and send the forks
//follows this logic
//while()
    //read pakcet from mailbox
    //if philosopher is thinking
        //if message token from node 'j' send fork to node 'j' and keep token
    //else if philsopher is HUNGRY
        //if message has both fork and token
            //clean the fork and keep both fork and token for philosopher to eat
        //else if message only has fork
            //clean the fork and keep it
        //else if it is only a token
            //if fork is clean
                //keep token
            //if fork is dirty
                //send both fork and token in one messge
        //below if statement is unrelated to above else if statements ubt within the philosopher is HUNGRY section
        //IF node has both forks
            //send a notify to Philospher to EAT
    //else if philospher == EATING
        //if mesage is token
            //keep the token

#include <Runner.h>
//#include "Philosopher.h"
//#include "Changer.h"

void Runner::Runner() {

}


void Runner::Runner(Philosopher* philosopher1, Changer & parentChanger)
: Changer(parentChanger)
{
    phil = philosopher1;
    while (keepGoing) {
        state = phil->getState();
        recievedFromID = parentChanger->getMsgID();//get packet from mailbox NO IDEA HOW TO DO THIS PLZ HELP
        msg = parentChanger->getMsg();//^these two lines should happen at like the same time not sure how to put these two lines together
        //also needs to be turned into a two charcter long string
        bool forkBool = false;
        if(got packet from mailbox){
            if(state == "THINKING") {
                if (msg == "01") {
                    //send fork to reciedFromID
                    parentChanger->sendFork(recievedFromID);//notify parent changer to send 
                }
            }
            else if(state == "HUNGRY") {
                if (msg == "11") {
                    parentChanger->cleanFork(true);//cleans fork and sends TRUE so that changer knows that it has both fork and 
                }
                else if (msg == "10") {
                    parentChanger->cleanFork(false);//cleans fork and send FALSE so that the changer knows that the token was not sent as well
                }
                else if (msg == "01") {
                    forkBool = parentChanger->getCleanState(recievedFromID);//gets state of fork from recieved ID
                    if (forkBool) {//True means it is clean
                        parentChanger->tokenGot(recievedFromID);//tells parentChanger that we now have token
                    }
                    else {
                        parentChanger->sendBoth(recievedFromID);//tells parentChanger that we have recieved a token and that our fork is dirty therefore send both back
                    }

                }
                if (parentChanger->doWeHaveThem()) {//checks if we have both forks
                    parentChanger->notify();//if we do then notify parentChanger to notify philosopher to eat
                }
            }
            else if(state == "EATING") {
                if (msg == "01") {
                    parentChanger->tokenGot(recievedFromID);//tells parentChanger that we now have a fork
                }
            }
        }
        keepGoing = parentChanger->getEND();//gets whether to end loop
    }
}


void Runner::~Runner() {

}


void Runner::setState(std::string newState) {
	this->state = newState;
}
