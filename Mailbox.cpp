#include "Mailbox.h"
#include <iostream>
#include <string.h>
#include <thread>
#include <sys/time.h>
#include <math.h>
#include "FileIO.h"

Mailbox::Mailbox() {
    
}

// destructor
Mailbox::~Mailbox() {
}

// empty mailbox
bool Mailbox::empty(uint16 dest) {
    bool sentry = true;
    while (sentry) {
        // enter critical section if mutex is available
        if (mtx.try_lock()) {
            // iterate through size of queue, popping each element
            for (int i = 0; i < _mailboxes[dest].size(); i++) {
                _mailboxes[dest].pop();
            }
            // unlock mutex then exit loop
            mtx.unlock();
            sentry = false;
        }
    }
    return true;
}

// send message
int Mailbox::send(uint16 dest, const void *packet, int len) {
    bool sentry = true;
    // create new instance of item struct and assign it msg info
    newMsg = new item;
    newMsg.length = len;
    newMsg.content = *packet;
    while (sentry) {
        // enter critical section if mutex is available
        if (mtx.try_lock()) {
            // push msg onto respective queue, unlock mutex then exit loop
            _mailboxes[dest].push(newMsg);
            mtx.unlock();
            sentry = false;
        }
    }
    return 1;
}

// recieve message
int Mailbox::recv(uint16 dest, void *packet, int max) {
    bool sentry = true;
    while (sentry) {
        // enter critical section if mutex is available
        if (mtx.try_lock()) {
            // assign msg to packet ptr then pop the msg
            *packet = _mailboxes[dest].front();
            _mailboxes[dest].pop();
            // unlock mutex then exit loop
            mtx.unlock();
            sentry = false;
        }
    }
    return 1;
}


void Mailbox::giveVector(std::vector<Philosopher*> vect){
    vectorOfPhilosophers = vect;
}