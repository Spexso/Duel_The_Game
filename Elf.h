// elf character
#ifndef Elf.h
#define Elf.h

#include <Arduino.h>

class elf {
  private:
    int strenght;
    int magic;
    int speed;
  
  public:
  elf(){
    strenght = 2;
    magic = 2;
    speed = 3;
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