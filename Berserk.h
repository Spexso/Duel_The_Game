// Berserk character
#ifndef Berserk.h
#define Berserk.h

#include <Arduino.h>

class berserk {
  private:
    int strenght;
    int magic;
    int speed;
  
  public:
  berserk(){
    strenght = 4;
    magic = 2;
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