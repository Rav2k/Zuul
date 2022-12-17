#include <iostream>
#include <cstring>
#include "room.h"
#include <iterator>
#include <map>
# include <vector>
using namespace std;

room::room(){
}

void room::setitem(char* item){
  items.push_back(item);
  
}

void room::setdescription(char* newdescription){
  description = new char[50];
  strcpy(description, newdescription);
}

char* room::getdescription(){
  return description;
}

void room::exit(const char* direction, room* room2){
  follow.insert(pair<const char*, room*>(direction, room2));
}

void room::printer(){
  map<const char*, room*>::iterator itr;
  cout << "Exists and rooms.";
    for (itr = follow.begin(); itr != follow.end(); ++itr) {
      cout << '\t' << itr->first << '\t' << itr->second->getdescription()
             << '\n';
    }
    cout << endl; 
}
room* room::getRoom(char* userdirection){
  map<const char*, room*>::iterator itr;
  cout << "Finding room..."<<endl;
    for (itr = follow.begin(); itr != follow.end(); ++itr) {
      if(strcmp(itr->first, userdirection) == 0){
	return itr->second;
      }
    }
    return NULL; 
}
