// Mage character
#ifndef Mage.h
#define Mage.h

#include <Arduino.h>

class mage {
  private:
    int strenght;
    int magic;
    int speed;
  
  public:
  mage(){
    strenght = 1;
    magic = 4;
    speed = 2;
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