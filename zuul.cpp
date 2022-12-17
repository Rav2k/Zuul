#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include <iterator>
#include <map>

using namespace std;

const char* north ="north";
const char* south ="south";
const char*  east ="east";
const char* west  ="west";

bool hasItem(char* item9, vector<char*> inventory);

int main(){ 
  char userdirection[20];
  room* topOfTheKey = new room();
  char* top = new char[50];
  strcpy(top, "topOfTheKey(basketball)");
  topOfTheKey->setdescription(top);
  char* top2 = new char[50];
  strcpy(top2, "basketball");
  topOfTheKey->setitem(top2);
  room* likeMike = new room();
  char* mike = new char[50];
  strcpy(mike, "Like mike");
  likeMike->setdescription(mike);
  room* england = new room();
  char* land = new char[50];
  strcpy(land, "england");
  england->setdescription(land);
  room* oneTwenty = new room();
  char* one = new char[50];
  strcpy(one, "one-twenty(computer)");
  oneTwenty->setdescription(one);
  char* one2 = new char[50];
  strcpy(one2, "computer");
  oneTwenty->setitem(one2);
  room* narnia = new room();
  char* nar = new char[50];
  strcpy(nar, "narnia(cloakofinvisibility)");
  narnia->setdescription(nar); 
  char* nar2 = new char[50];
  strcpy(nar2, "cloakofinvisibility");
  narnia->setitem(nar2);
  room* office = new room();
  char* off = new char[50];
  strcpy(off, "office (programmingmanual)");
  office->setdescription(off);
  char* off2 = new char[50];
  strcpy(off2, "programmingmanual");
  office->setitem(off2);
  room* pub = new room();
  char* brew = new char[50];
  strcpy(brew, "pub(money)");
  pub->setdescription(brew);
  char* brew2 = new char[50];
  strcpy(brew2, "money");
  pub->setitem(brew2);
  room* outside = new room();
  char* out = new char[50];
  strcpy(out, "outside");
  outside->setdescription(out);
  room* theatre = new room();
  char* thea = new char[50];
  strcpy(thea, "theatre(brokenkey)");
  theatre->setdescription(thea);
  char* thea2 = new char[50];
  strcpy(thea2, "brokenkey");
  theatre->setitem(thea2);
  room* Amath = new room();
  char* ama = new char[50];
  strcpy(ama, "Amath");
  Amath->setdescription(ama);
  room* ravland = new room();
  char* rav = new char[50];
  strcpy(rav, "ravland (videogames)");
  ravland->setdescription(rav);
  char* rav2 = new char[50];
  strcpy(rav2, "videogames");
  ravland->setitem(rav2);
  room* lab = new room();
  char* labo = new char[50];
  strcpy(labo, "lab(wrench)");
  lab->setdescription(labo);
  char* labo2 = new char[50];
  strcpy(labo2, "wrench");
  lab->setitem(labo2);
  room* waterland = new room();
  char* water = new char[50];
  strcpy(water, "waterland");
  waterland->setdescription(water);
  room* alcatraz = new room();
  char* alc = new char[50];
  strcpy(alc, "alcatraz");
  alcatraz->setdescription(alc);
  room* balldontlie = new room();
  char* ball = new char[50];
  strcpy(ball, "Ball dont lie");
  balldontlie->setdescription(ball);
  room* currentRoom = new room();
  topOfTheKey->exit(south, oneTwenty);
  likeMike->exit(south, office);
  england->exit(east, oneTwenty);
  england->exit(south, pub);

  oneTwenty->exit(north, topOfTheKey);
  oneTwenty->exit(east, narnia);
  oneTwenty->exit(south, outside);
  oneTwenty->exit(west, england);
  
  narnia->exit(south, theatre);
  narnia->exit(west, oneTwenty);
  narnia->exit(east, office);
  
  office->exit(south, Amath);
  office->exit(west, narnia);
  office->exit(north, likeMike);
  
  pub->exit(north, england);
  pub->exit(south, ravland);
  pub->exit(east, outside);
  
  outside->exit(north, oneTwenty);
  outside->exit(south, lab);
  outside->exit(east, theatre);
  outside->exit(west, pub);
  
  theatre->exit(north, narnia);
  theatre->exit(south, waterland);
  theatre->exit(east, Amath);
  theatre->exit(west, outside);
  
  Amath->exit(north, office);
  Amath->exit(west, theatre);
  
  ravland->exit(north, pub);
  ravland->exit(south, alcatraz);
  ravland->exit(east, lab);
  
  lab->exit(north, outside);
  lab->exit(south, balldontlie);
  lab->exit(west, ravland);
  lab->exit(east, waterland);
  
  waterland->exit(north, theatre);
  waterland->exit(west, lab);
  
  alcatraz->exit(north, ravland);
  alcatraz->exit(east, balldontlie);
  
  balldontlie->exit(north, lab);
  balldontlie->exit(east, alcatraz);

  vector<char*> inventory;
  char choice[20];
  char choice2[20];
  char item2[20];
  char item3[20];

  currentRoom = outside;
  cout<<"Welcome to Zuul you are currently Outside find your way of escape!"<<endl;
  cout<<"These are the exits: "<<endl;

  while(!(hasItem(brew2, inventory) == true && hasItem(thea2, inventory) == true
	  && hasItem(labo2, inventory) == true && hasItem(one2, inventory) == true &&
	  hasItem(nar, inventory) == true && currentRoom == alcatraz)){
    currentRoom->printer();
    cout<<"What direction would you like to go?"<<endl;
    cin.getline(userdirection, 20);
    currentRoom = currentRoom->getRoom(userdirection);
    cout<<"Curent Room: "<<currentRoom->getdescription()<<endl;

    cout<<"do you want to pick up an item(yes or no)"<<endl;
    cin.getline(choice, 20);
    if(strcmp(choice, "yes")==0){
      cout<<"item: "<<endl;
      cin.getline(item2, 20);
      inventory.push_back(item2);
      cout<< "You now have "<<item2<<endl;
    }else{
      continue;
    }
    
    cout<<"do you want to drop an item(yes or no)"<<endl;
    cin.getline(choice2, 20);
    if(strcmp(choice2, "yes")==0){
      cout<<"item: "<<endl;
      cin.getline(item3, 20);
      for (std::vector<char*>::iterator it = inventory.begin() ; it != inventory.end(); ++it){
	if(strcmp((*it), item3) == 0){
	  inventory.erase(it);
	  break;
	}
      }
      cout<<"item deleted"<<endl;
    }else{
      continue;
    }

  }
  
  cout<<"Great Job you've escaped!"<<endl;
}


bool hasItem(char* item9, vector<char*> inventory){
  for (std::vector<char*>::iterator it = inventory.begin() ; it != inventory.end(); ++it){
    if(strcmp(item9, (*it)) == 0){
      return true;
    }
  }
  return false;
}
