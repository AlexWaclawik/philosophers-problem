/*
 * mailbox.h
 * Copyright(c) 2022 Dongsoo S. Kim
 */

#ifndef MAILBOX_H_EXISTS
#define MAILBOX_H_EXISTS

#include <map>
#include <queue>
#include <mutex>
#include "Philosopher.h"

using namespace std;

typedef unsigned short uint16;

class Mailbox {
  struct item {
    int length;
    char *content;
  };
  private: 
    typedef queue<item> mailbox_t; 
    map<uint16,mailbox_t> _mailboxes;
    mutex mtx;
    std::vector<Philosopher*> vectorOfPholosophers;
  public:
    Mailbox();
    ~Mailbox();
    bool empty(uint16 dest); 
    int send(uint16 dest, const void *packet, int len);
    int recv(uint16 dest, void *packet, int max);
    void giveVector(std::vector<Philosopher*>);
};

#endif
