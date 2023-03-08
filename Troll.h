// Troll character
#ifndef Troll.h
#define Troll.h

#include <Arduino.h>

class troll {
  private:
    int strenght;
    int magic;
    int speed;
  
  public:
  troll(){
    strenght = 1;
    magic = 1;
    speed = 1;
  }
  void changeStr(int n){
    strenght = n;
  }
  void changeMgc(int n){
    magic = n;
  }
  void changeSpd(int n){
    speed = n;
  }

  int getStr(){
    return strenght;
  }

  int getMgc(){
    return magic;
  }

  int getSpd(){
    return speed;
  }
};


#endif