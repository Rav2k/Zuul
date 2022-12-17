#ifndef ROOM
#define ROOM
#include <iostream>
#include <cstring>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

class room{
public:
  void printer();
  room();
  const char* name;
  const char* item;
  char* description;
  char* getdescription();
  void setitem(char* item);
  void setdescription(char* newdescription);
  room* getRoom(char* userdirection);
  void exit(const char* direction, room* room2);
  vector<char*> items;
  map<const char*, room*> follow;
};

#endif
