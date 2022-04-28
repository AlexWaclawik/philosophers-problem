/*
 * mailbox.h
 * Copyright(c) 2022 Dongsoo S. Kim
 */
 //copied over from past projects
#ifndef MAILBOX_H
#define MAILBOX_H

#include <map>
#include <queue>
#include <mutex>

using namespace std;

typedef unsigned short uint16;

class MailBox {
  struct item {
    int length;
    char *content;
  }; 
  typedef queue<item> mailbox_t; 
  map<uint16,mailbox_t> _mailboxes;
  mutex mtx;
  std::vector<Philosopher*> vectorOfPholosophers;
public:
  MailBox() {};
  ~MailBox();
  bool empty(uint16 dest); 
  int send(uint16 dest, const void *packet, int len);
  int recv(uint16 dest, void *packet, int max);
  void giveVector(std::vector<Philosopher*>);
};

#endif