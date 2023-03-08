#include "Mage.h"
#include "Berserk.h"
#include "Elf.h"
#include "Troll.h"


#define death_1 150
#define death_2 70
#define death_3 30

#define Coin_1 399
#define Coin_2 1319

#define Sound_1 1568
#define Sound_2 2637
#define Sound_3 400
#define Sound_4 2349
#define Sound_5 500

#define Sound_6 392
#define Sound_7 4000

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

#define trig 10
#define echo 9
#define buzzer 8

#define Button 5


#define blue_L 6
#define green_L 3
#define red_L 11 

int countB = 0;       //number of clicks to button
int printC = 0;       //Menu print count
int opt;              //Menu pick
int roundN = 0;

int changeS = 0;      //Represents the stat type that will be changed based on luck factor
int luckF_V = 0;      //Represents the Luck factor generated value     

float timeBetween; //Variable to hold wave input on Distance component
float distance;

// change this to make the song slower or faster
int tempo = 140;

int stats[3] = {0,0,0};     //Three Stats of troll enemies 




// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Gren Hill Zone - Sonic the Hedgehog
  // Score available at https://musescore.com/user/248346/scores/461661
  // Theme by Masato Nakamura, arranged by Teddy Mason
  
  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
  NOTE_E4,-1,
  REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

  REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
  REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,-1, //end 1

  //repeats from 1

  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
  NOTE_E4,-1,
  REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

  REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
  REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,8, //end 2
  NOTE_E4,-2, NOTE_A4,8, NOTE_CS5,8, 
  NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8, NOTE_A5,-4,

};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void tabGenerator(int n){
  for(int i=0; i < n; i++){
    Serial.print("\t");
  }
}

void spaceGenerator(int n){
  for(int i=0; i < n; i++){
    Serial.println("");
  }
}

void printMenu()
{
  tabGenerator(10);
  Serial.println(F(" DUEL THE GAME"));
  tabGenerator(10);
  Serial.println(F("    1-Play"));
  tabGenerator(10);
  Serial.println(F("    2-Guide"));
  tabGenerator(10);
  Serial.println(F("    3-Exit"));
  tabGenerator(8);
  Serial.println(F("Button-Mute Music(Use it before proceed the game)"));
}

int postMenu(){
  char p = '!';
  PostLed();
  Serial.println(F("*Wait"));
  delay(1000);
  playActionMusic();
  Serial.println(F("You are still here"));
  delay(2000);
  playActionMusic();
  Serial.println(F("So"));
  delay(3000);
  playActionMusic();
  Serial.println(F("Wanna play again ?(y/n)"));

    while(1){
      if(Serial.available() > 0){
        p = Serial.read();

          if(p == 'y'){
          stopLed();
          return 1;
        }
        else if(p == 'n'){
          Serial.println(F("As you wish..."));
          delay(3000);
          Serial.println(F("See you?"));
          delay(2000);
          stopLed();
          return 2;
        }
        else if(p != '!' ){
          Serial.println(F("U supposed to enter y or n dude its that simple..."));
          delay(3000);
        }

      }
  
    }
}

int decidePos(){
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  timeBetween = pulseIn(echo, HIGH);
  distance = (timeBetween/29.1)/2;

  //Serial.print("Distance-> ");
  //Serial.print(distance);
  //Serial.print(" cm\n");
  if(distance < 10)
  {
    Serial.print("Attack position\n");
    return 0;
  }
  else if(distance > 10 && distance < 25)
  {
    Serial.print("Defence Position\n");
    return 1;
  }
  else{
    //Not in duel area
    return -1;
  }
}

int getRandomNum(int Tth){
  // Tth represents the xth. trait
  int randScaler;
  
  if(roundN != 4){
    
    if(roundN > 2){
      randScaler = random(3,5);
      stats[Tth] = randScaler;
      return randScaler;
    }  
    else if(stats[Tth-1] == 4){
      randScaler = random(2,4);
      stats[Tth] = randScaler;
      return randScaler;
    }
    else{
      randScaler = random(1,4);
      stats[Tth] = randScaler;
      return randScaler;
    } 
  
  }
  else{
    randScaler = random(3,7);
    stats[Tth] = randScaler;
    return randScaler;
  }
    

  
}

void LuckMenu(){
  Serial.println(F("Wizard wants you to pick one of these traits..."));
  delay(1000);
  Serial.println(F("1-Strenght"));
  Serial.println(F("2-Magic"));
  Serial.println(F("3-Speed"));
  Serial.print(F("->"));
}

int increaseLuck(){
  int rate = random(0, 101);    //% based luck
  if(rate > 70){
    return 1;
  }
  else{
    return 2;
  }
}

int LuckFactor(){
  int rand_ = random(0,101);    //% based luck
  int inc;                     // stat increase value
  int pick = 1;

    Serial.println(F("///////////////////////////////////////////////////"));
    Serial.print(F("You stumbled upon a WIZARD on your way!"));
    delay(1000);
    Serial.print(F("."));
    delay(1000);
    Serial.print(F("."));
    delay(1000);
    Serial.print(F("."));
    blinkLed();
    //Luck factor to get elected for wizard buff
    if(rand > 75){
      inc = increaseLuck();

      spaceGenerator(2); 
      //Luck factor to apply buff 
      if(random(3) == 0){
        spaceGenerator(2);
        Serial.println(F("How unlucky of you WIZARD thinks you are not worthy!"));
        Serial.println(F("///////////////////////////////////////////////////"));
        delay(1500);
        return -1;
      }else{
        spaceGenerator(2);
        Serial.println(F("LUCK is on your side! Wizard decides to help you"));
        delay(1500);
        Serial.println(F("You have a chance to increase one of your stats!!"));
        delay(1500);
      }
      //
      LuckMenu();
      //
      while(Serial.available() == 0){}

        pick = Serial.parseInt();
      
      spaceGenerator(1);

        if(pick == 1){
          Serial.print("You are strong as _Gimli_ now - Strenght stat increased by ");
          Serial.println(inc);
          changeS = 1;
          luckF_V = inc;
          Serial.println(F("///////////////////////////////////////////////////"));
          delay(1000);
          return 1;
        }
        else if(pick == 2){
          Serial.print("Your magic could summon a Balrog! - Magic stat increased by ");
          Serial.println(inc);
          changeS = 2;
          luckF_V = inc;
          Serial.println(F("///////////////////////////////////////////////////"));
          delay(1000);
          return 1;
        }
        else if(pick == 3){
          Serial.print("I can see you running in the woods of Valinor - Speed stat increased by ");
          Serial.println(inc);
          changeS = 3;
          luckF_V = inc;
          Serial.println(F("///////////////////////////////////////////////////"));
          delay(1000);
          return 1;
        }
        else{
          Serial.println("You did not obey the rules of WIZARD and got nothing...");
          delay(1000);
          Serial.println(F("Do not test the patience of WIZARD next time"));
          delay(1500);
          Serial.println(F("///////////////////////////////////////////////////"));
          return -1;
        }
        
    }
    else{
      //No luck factor initiated
      Serial.print(F("Wizard teleported somewhere else"));
      delay(800);
      Serial.print(F("."));
      delay(800);
      Serial.print(F("."));
      delay(800);
      Serial.println(F("."));
      Serial.println(F("///////////////////////////////////////////////////"));
      changeS = 0;
      return -1;
    }
}

int swordFactor(){
  int rand = random(0,101);         //% based on luck
  
  Serial.println(F("You looted a grave"));
  delay(1000);
  Serial.print(F("."));
  delay(1000);
  Serial.print(F("."));
  delay(1000);
  Serial.print(F("."));

  blinkLed();           //Initiate effect
    // %35 Luck factor to find sword
    if(rand > 65){
      Serial.println(F("And You found a sword that used to belong to a fallen warrior..."));    
      Serial.println(F("///////////////////////////////////////////////////"));
      delay(2000);
      return 1;
    }
    else{
      Serial.println(F("And you found nothing..."));
      Serial.println(F("///////////////////////////////////////////////////"));
      delay(2000);
      return -1;
    }

}

int potionFactor(){
  int rand = random(0,101);
  spaceGenerator(1);
  Serial.println(F("Troll Master has thrown its potion to You! And"));
  delay(1000);
  Serial.print(F("."));
  delay(1000);
  Serial.print(F("."));
  delay(1000);
  Serial.print(F("."));

  blinkLed();             //Initiate effect

    // %20 Luck to get poisoned
    if(rand > 80){
      Serial.println(F("It worked... You are poisoned!!!"));
      delay(2000);
      return 1;
    }
    else{
      Serial.println(F("Potion was weak and did not effect you..."));
      delay(2000);
      return -1;
    }
}

int bossRand(){
  int r = random(0,101);
  spaceGenerator(1);
  
  if( r > 50){
    Serial.println("Its a Balrog!!");
    return 0;
  }
  else{
    Serial.println("VISERION is on sight!!");
    return 1;
  }

}

/////////////////////// TEXT MESSAGES ///////////////////////////////
/**/
void mes(){
  if(roundN == 4){
    Serial.print(F("Y-")); 
    delay(1000);
    Serial.print(F("."));
    delay(1000);
    Serial.print(F("."));
    delay(1000);
    Serial.print(F("."));
    Serial.print(F("you tamed a dragon with your BARE hands!"));
    
  }
  else
    Serial.print(F("Awrr! Looks like your are stronger than this filthy troll\n"));
}

void mes1(){
  if(roundN == 4){
    Serial.print(F("Knee peasent!"));
  }
  else
    Serial.print(F("Troll is stronger! YOU Weakling Hahahahahaha-\n"));
}

void mes2(){
  if(roundN == 4){
    Serial.print(F("Smarter than a Dragon ?!?"));
  }
  else
    Serial.print(F("Hmm.. We have a wise one here everyone\n"));
}

void mes3(){
  if(roundN == 4){
    Serial.print(F("Dragons are not very intellectual anyway..."));
  }
  else
    Serial.print(F("WHAHAHAHAH imagine being more dumb than a troll You lost on this trait\n"));
}

void mes4(){
  if(roundN == 4){
    Serial.print(F("I-I just can't believe you are faster than a Dragon "));
  }
  else
    Serial.print(F("Migthy HERMES! You are fast\n"));
}

void mes5(){
  if(roundN == 4){
    Serial.print(F("There is no way you thought you are faster than a Dragon"));
  }
  Serial.print(F("Oh don't tell me you are a real life turtle... You lost on this trait\n"));
}

void mesDeath(){
  if(roundN == 4){
    Serial.print(F("Dragon burned your flesh and bones away!"));
  }
  else
    Serial.print(F("A cruel death is upon you!\n"));
  //Death Sound Effeect
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.print(".");
  delay(1000);
  playDeathSound();
  Serial.print(F("\nNOW\n"));
  delay(2000);
  clearTerminal();
      for(int x=0;x<450;x++){
          digitalWrite(red_L, LOW);
          Serial.print(F("DIE DIE DIE DIE DIE DIE"));
          tone(buzzer, death_1, 35);
          delay(10);
          tone(buzzer, death_2, 35);
          delay(10);
          tone(buzzer, death_3, 35);
          digitalWrite(red_L, HIGH);
          noTone(buzzer);
      }
 delay(5000);

  clearTerminal();
}

void mesR1(){
  Serial.print(F("Not bad hero! You still need to beat many trolls though\n"));
  delay(3000);
}

void mesR2(){
  Serial.print(F("Looks like you might be able to live one more day\n"));
  delay(3000);
}

void mesR3(){
  Serial.print(F("Do you really believe you can beat my trolls??"));
            
            Serial.print(".");
            delay(555);
            Serial.print(".");
            delay(555);
            Serial.println(".");
            delay(555);
            Serial.println("How pathetic...");
            delay(3000);
}

void mesR4(){
  Serial.println(F("I-I-I gotta admit that I might did underestimated you..."));
            delay(3000);
}

void mesR5(){
   Serial.print(F("Well\n"));
            Serial.print(".");
            delay(1000);
            Serial.print(".");
            delay(1000);
            Serial.print(".");
            delay(1000);
            Serial.println(F("You won! You killed all of your enemies"));
            Serial.println(F("Good job-"));
            Serial.print("I");
            delay(500);
            Serial.print(" ");
            delay(300);
            Serial.print("g");
            delay(500);
            Serial.print("u");
            delay(500);
            Serial.print("e");
            delay(500);
            Serial.print("s");
            delay(500);
            Serial.println("s");
            
            delay(3000);
}
/**/
/////////////////////// TEXT MESSAGES ///////////////////////////////




void duelGame(){
  stopLed();
  int bossT;
  int wonC = 0;                               //Numbers of won rounds based on stats
  int position;
  digitalWrite(green_L, HIGH);
  digitalWrite(red_L, LOW);
  digitalWrite(blue_L, LOW);
  int classP = chooseClass();
  int Str;
  int Mgc;
  int Spd;
  
    if(classP == 1){
      berserk P;
      Str = P.getStr();
      Mgc = P.getMgc();
      Spd = P.getSpd();
      playSelectMusic();
      Serial.print(F("Berserk picked\n"));
    } 
    else if(classP == 2){
      mage P;
      Str = P.getStr();
      Mgc = P.getMgc();
      Spd = P.getSpd();
      playSelectMusic();
      Serial.print(F("Mage picked\n"));
    } 
    else if(classP == 3){
      elf P;
      Str = P.getStr();
      Mgc = P.getMgc();
      Spd = P.getSpd();
      playSelectMusic();
      Serial.print(F("Elf picked\n"));
    }
    else{
      Serial.print(F("I said pick from these 3...Going back to menu!"));
      playEffectSound();
      return;
    }


    for(int i=0; i < 5;i++,roundN++){
      if(i == 0 && random(1,5) > 2){
        Serial.println(F("Hm good pick I guess"));
        delay(3000);
      }else if(i == 0){
        Serial.println(F("You really picked that ?"));
        delay(1000);
        Serial.println(F("Just sad..."));
        delay(3000);
      }
      spaceGenerator(2);
      clearTerminal();
      stopLed();
      Serial.print(F("---------Round-"));
      Serial.print(i+1);
      Serial.print(F("---------\n"));

    troll Enemy;
    //printClassStat(Enemy.getStr());
    //printClassStat(Enemy.getMgc());
    //printClassStat(Enemy.getSpd());

    if(i == 4){
    
    Serial.print(F("You are facing a DRAGON that summoned by Troll Master :\n"));

    bossT = bossRand();

      if(bossT = 0)
      {
        Enemy.changeStr(6);
        Enemy.changeMgc(getRandomNum(2));
        Enemy.changeSpd(getRandomNum(3));

        Serial.print(Enemy.getStr());
        Serial.print(F(" Strenght\n"));
        Serial.print(Enemy.getMgc());
        Serial.print(F(" Magic\n"));
        Serial.print(Enemy.getSpd());
        Serial.print(F(" Speed\n"));
      }
      else if(bossT = 1)
      {
        Enemy.changeStr(getRandomNum(1));
        Enemy.changeMgc(6);
        Enemy.changeSpd(getRandomNum(3));

        Serial.print(Enemy.getStr());
        Serial.print(F(" Strenght\n"));
        Serial.print(Enemy.getMgc());
        Serial.print(F(" Magic\n"));
        Serial.print(Enemy.getSpd());
        Serial.print(F(" Speed\n"));
      }
    }
    else
    {
    
    Enemy.changeStr(getRandomNum(1));
    Enemy.changeMgc(getRandomNum(2));
    Enemy.changeSpd(getRandomNum(3));

    Serial.print(F("You are facing a Troll that summoned by Troll Master :\n"));

    Serial.print(Enemy.getStr());
    Serial.print(F(" Strenght\n"));
    Serial.print(Enemy.getMgc());
    Serial.print(F(" Magic\n"));
    Serial.print(Enemy.getSpd());
    Serial.print(F(" Speed\n"));
    }
    


  /*Events*/ 
    if(LuckFactor() != -1){
      playSelectMusic();
      if(changeS == 1){
          Str += luckF_V;
      }
      else if(changeS == 2){
          Mgc += luckF_V;
      }
      else if(changeS == 3){
          Spd += luckF_V;
      }

    }

    if(swordFactor() != -1){
      playSelectMusic();
      spaceGenerator(1);
      if(random(0,3) == 0){
        Serial.println(F("It turns out Sword was CURSED"));
        Serial.println(F("Your strenght and magic has decreased by 1"));
        Str -= 1;
        Mgc -= 1; 
      }else{
        Serial.println(F("Your strenght has increased by 1"));
        Str += 1;
      }
    }

    if(potionFactor() != -1){
      playSelectMusic();
      spaceGenerator(1);
      Serial.println(F("Your magic and speed decreased by 1"));
      Mgc -= 1;
      Spd -= 1;  
      Serial.println(F("///////////////////////////////////////////////////"));
    }

  /*Events*/


    //printClassStat(Enemy.getStr());
    //printClassStat(Enemy.getMgc());
    //printClassStat(Enemy.getSpd());

    Serial.println(F("Please place your hero in position!!"));
    while(digitalRead(Button) == LOW){}
    Serial.print(F("Get ready for impact!!!\n"));
      
      position = decidePos();
      spaceGenerator(1);

      //ATTACK POS
      if(position == 0){
        AttackLed();
        if( (Str+1) > Enemy.getStr()){
          playActionMusic();
          spaceGenerator(1);
          Serial.print(F("Strenght Trait => "));
          tabGenerator(1);
          mes();
          spaceGenerator(1);
          wonC++;
        }else{
          playActionMusic();
          Serial.print(F("Strenght Trait => "));
          tabGenerator(1);
          mes1();
          spaceGenerator(1);
        }
        delay(2000);

        if( (Mgc-1) > Enemy.getMgc()){
          playActionMusic();
          Serial.print(F("Magic Trait => "));
          tabGenerator(1);
          mes2();
          spaceGenerator(1);
          wonC++;
        }else{
          playActionMusic();
          Serial.print(F("Magic Trait => "));
          tabGenerator(1);
          mes3();
          spaceGenerator(1);
        }
        delay(2000);

        if( (Spd+1) > Enemy.getSpd()){
          playActionMusic();
          Serial.print(F("Speed Trait => "));
          tabGenerator(1);
          mes4();
          spaceGenerator(1);
          wonC++;
        }else{
          playActionMusic();
          Serial.print(F("Speed Trait => "));
          tabGenerator(1);
          mes5();
          spaceGenerator(1);
        }
        stopLed();
        
        delay(6000);
          //END OF ROUND
          clearTerminal();
          if(wonC >=2 & i == 0){
            wonC = 0;
            playEffectSound();
            mesR1();
          }
          else if(wonC >= 2 & i == 1){
            wonC = 0;
            playEffectSound();
            mesR2();
          }
          else if(wonC >= 2 & i == 2){
            wonC = 0;
            playEffectSound();
            mesR3();
          }
          else if(wonC >= 2 & i == 3){
            wonC = 0;
            playEffectSound();
            mesR4();
          }
          else if(wonC >= 2 & i == 4){
            //Won
            wonC = 0;
            mesR5();
            playWonSound();
            return;
          }
          else if(wonC < 2){
            DeadLed();
            stopLed();
            mesDeath();
            clearTerminal();
            return;
          }
      }
      else if(position == 1){
        //DEF POS
        DefendLed();
        if( (Str) > Enemy.getStr()){
          spaceGenerator(1);
          playActionMusic();
          Serial.print(F("Strenght Trait => "));
          tabGenerator(1);
          mes();
          spaceGenerator(1);
          wonC++;
        }else{
          playActionMusic();
          Serial.print(F("Strenght Trait => "));
          tabGenerator(1);
          mes1();
          spaceGenerator(1);
        }
              delay(2000);

        if( (Mgc+1) > Enemy.getMgc()){
          playActionMusic();
          Serial.print(F("Magic Trait => "));
          tabGenerator(1);
                mes2();
                spaceGenerator(1);
                wonC++;
        }else{
          playActionMusic();
          Serial.print(F("Magic Trait => "));
          tabGenerator(1);
          mes3();
          spaceGenerator(1);
       }
              delay(2000);

        if( (Spd-1) > Enemy.getSpd()){
          playActionMusic();
          Serial.print(F("Speed Trait => "));
          tabGenerator(1);
                mes4();
                spaceGenerator(1);
                wonC++;
        }else{
          playActionMusic();
          Serial.print(F("Speed Trait => "));
          tabGenerator(1);
          mes5();
          spaceGenerator(1);
        }
            stopLed();
            delay(6000);

          // END OF ROUND
          clearTerminal();
          if(wonC >= 2 & i == 0){
                wonC = 0;
                mesR1();
          }
          else if(wonC >= 2 & i == 1){
                wonC = 0;
                mesR2();
          }
         else if(wonC >= 2 & i == 2){
                wonC = 0;
                mesR3();
         }
          else if(wonC >= 2 & i == 3){
                wonC = 0;
                mesR4();
          }
          else if(wonC >= 2 & i == 4){
                //Won
                wonC = 0;
                WonLed();
                mesR5();
                playWonSound();
                return;
          }
          else if(wonC < 2){
                mesDeath();
                delay(4000);
                clearTerminal();
                return;
          }
      }
      else{
        //invalid placement
        Serial.print("Can't see your pawn friend...");
        delay(2000);
        break;
      }

    delay(500);
    } 
    
    stopLed();
}


int chooseClass(){
  int pick;
  Serial.print(F("1-Berserk\t(Str:4,Magic:2,Speed:1)\n"));
  Serial.print(F("2-Mage   \t(Str:1,Magic:4,Speed:2)\n"));
  Serial.print(F("3-Elf    \t(Str:2,Magic:2,Speed:3)\n"));

    while(Serial.available() == 0){}
    pick = Serial.parseInt();

  //Serial.print(pick);
  //Serial.print(F(" is entered\n"));
  spaceGenerator(1);

    return pick;
}

void clearTerminal(){
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}



void playBackgroundMusic(){
   for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
    
    /*
    Check here if button pressed
    */
    if(digitalRead(Button) == HIGH){
      countB++;
      return;
    }
  }
}

void playSelectMusic(){
  tone(buzzer, Coin_1, 100);
  delay(100);
  tone(buzzer, Coin_2, 850);
  delay(300);
  noTone(buzzer);
}

void playActionMusic(){
  tone(buzzer, Coin_2, 125);
  delay(130);
  tone(buzzer, Sound_1,125);
  delay(130);
  tone(buzzer, Sound_2,125);
  delay(130);
  tone(buzzer, Sound_3,125);
  delay(130);
  tone(buzzer, Sound_4,125);
  delay(130);
  tone(buzzer, Sound_5,125);
  delay(125);
  noTone(buzzer);
}

void playShutdownSound(){
  tone(buzzer, 3000, 1000);
  delay(750);
  tone(buzzer, 2500, 1000);
  delay(750);
  tone(buzzer, 2000, 1000);
  delay(750);
}

void playEffectSound(){
  tone(buzzer, Sound_6, 100);
  delay(200);
  tone(buzzer, Sound_7, 200);
  delay(200);
  tone(buzzer, Sound_1, 100);
  delay(200);
  noTone(buzzer);
}

void playDeathSound(){
  tone(buzzer, death_1, 300);
  delay(300);
  tone(buzzer, death_2, 300);
  delay(300);
  tone(buzzer, death_3, 600);
  delay(300);
}

void playWonSound(){
  tone(buzzer, 1500, 1000);
  delay(1000);
  tone(buzzer, 1700, 1000);
  delay(1000);
  tone(buzzer, 3000, 450);
  delay(1000);
  tone(buzzer, 3000, 450);
  delay(1000);
  tone(buzzer, 2500, 750);
  delay(1000);
  tone(buzzer, 1500, 1000);
  delay(1000);
  tone(buzzer, 1700, 1000);
  delay(1000);
  tone(buzzer, NOTE_GS3, 450);
  delay(500);
  tone(buzzer, NOTE_GS3, 450);
  delay(1000);
  tone(buzzer, 1500, 1000);
  delay(1000);
  tone(buzzer, 1700, 1000);
  delay(1000);
  tone(buzzer, 3000, 450);
  delay(1000);
  tone(buzzer, 3000, 450);
  delay(1000);
  tone(buzzer, 2500, 750);
  delay(1000);
  tone(buzzer, 1500, 1000);
  delay(1000);
  tone(buzzer, 1700, 1000);
  delay(1000);
  tone(buzzer, NOTE_GS3, 450);
  delay(500);
  tone(buzzer, NOTE_GS3, 450);
  delay(1000);
}

void ExitLed(){
  digitalWrite(red_L, LOW);
  delay(500);
  digitalWrite(red_L, HIGH);
  delay(500);
  digitalWrite(red_L, LOW);
  delay(500);
  digitalWrite(red_L, HIGH);
  delay(500);
  digitalWrite(red_L, LOW);
  delay(500);
  digitalWrite(red_L, HIGH);
  delay(500);
}

void blinkLed(){
  digitalWrite(green_L, HIGH);
  digitalWrite(red_L, LOW);
  digitalWrite(blue_L, LOW);
  delay(1000);
  digitalWrite(green_L, LOW);
  digitalWrite(red_L, LOW);
  digitalWrite(blue_L, LOW);
  delay(1000);
  digitalWrite(green_L, HIGH);
  digitalWrite(red_L, LOW);
  digitalWrite(blue_L, LOW);
  delay(1000);
  digitalWrite(green_L, LOW);
  digitalWrite(red_L, LOW);
  digitalWrite(blue_L, LOW);
  delay(1000);
}

void AttackLed(){
  digitalWrite(red_L, HIGH);
  digitalWrite(blue_L, HIGH);
  digitalWrite(green_L, LOW);
}

void DefendLed(){
  digitalWrite(red_L, HIGH);
  digitalWrite(green_L, HIGH);
  digitalWrite(blue_L, LOW);
}

void DeadLed(){
  digitalWrite(blue_L, HIGH);
  digitalWrite(green_L, HIGH);
  digitalWrite(red_L, LOW);
}

void WonLed(){
  digitalWrite(blue_L, HIGH);
  digitalWrite(green_L, HIGH);
  digitalWrite(red_L, HIGH);
}

void stopLed(){
  digitalWrite(blue_L, LOW);
  digitalWrite(green_L, LOW);
  digitalWrite(red_L, LOW);
}

void PostLed(){
  digitalWrite(blue_L, HIGH);
  digitalWrite(green_L, LOW);
  digitalWrite(red_L, LOW);
}

void guideMenu(){
  DefendLed();
  Serial.println(F("Duel The Game"));
  spaceGenerator(1);
  
  Serial.println(F("Game is based on luck and strategy also has ROLEPLAYING elements. Luck has huge influence on game like some events, and enemy stats sets based on luck.")); 
  Serial.println(F("Player is against waves of enemy Trolls that is controlling by Troll Master. Troll Master also communicates with Player :)))"));
  Serial.println(F("Troll Master usually makes fun of Player."));
  
  spaceGenerator(2);
  Serial.print(F("Available Classes:"));
  tabGenerator(9);
  Serial.println(F("Position Mechanic:"));
  Serial.print(F("-Berserk\t(Str:4,Magic:2,Speed:1)"));
  tabGenerator(7);
  Serial.println(F("Attack Position => +1 Strenght | -1 Magic | +1 Speed"));
  Serial.print(F("-Mage   \t(Str:1,Magic:4,Speed:2)"));
  tabGenerator(7);
  Serial.println(F("Defend Position => +1 Magic | -1 Speed"));
  Serial.print(F("-Elf    \t(Str:2,Magic:2,Speed:3)"));
  
  spaceGenerator(2);
  Serial.println(F("Enemy:"));
  Serial.println(F("-Troll\t(Str:1,Magic:1,Speed:1)"));
  Serial.println(F("Troll's stats scales with luck factor to maximum 4"));
  Serial.println(F("Troll's stats generated based on other stats of itself if previous stat is higher than 3 then next start could be maximum 3"));
  Serial.println(F("At Last round you will face a BOSS! Stats of Boss is way higher than Trolls"));

  spaceGenerator(2);
  Serial.println(F("Events:"));
  Serial.println(F("-Stumbling upon Wizard-->(Possible pickable Positive Effect)"));
  Serial.println(F("-Finding grave-->(Possible Positive Effect)"));
  Serial.println(F("-Getting potion thrown-->(Possible Negative Effects)"));

}

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(Button, INPUT);

  pinMode(blue_L, OUTPUT);
  pinMode(red_L, OUTPUT);
  pinMode(green_L, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));
  opt = 0;
  stopLed();
  
}
/*
void test(){
  digitalWrite(green_L, HIGH);
  digitalWrite(blue_L, HIGH);
  digitalWrite(red_L, LOW);
  delay(1500);
  digitalWrite(green_L, LOW);
  digitalWrite(blue_L, LOW);
  digitalWrite(red_L, LOW);
  delay(1500);
}
*/
void loop() {
  
  delay(2000);
  if(printC == 0){
    clearTerminal();
    printMenu();
    stopLed();
    printC++;
  }

  if(countB == 0){
    playBackgroundMusic();
  }


   if(Serial.available() > 0){
    opt = Serial.parseInt();

    switch(opt){
      case 1:
        clearTerminal();
        playSelectMusic();
        duelGame();
        roundN = 0;
        clearTerminal();
        opt = postMenu();
        if(opt == 2){
          clearTerminal();
          delay(50);
          Serial.println(F("Bye"));
          playShutdownSound();
          ExitLed();
          delay(200);
          exit(0);
        }
        clearTerminal();
        //printClass();
        printC = 0;
        countB = 0;
        stopLed();
      break;

      case 2:
      clearTerminal();
        guideMenu();
        spaceGenerator(1);
        Serial.println(F(">>Press the button to return Menu"));
        while(digitalRead(Button) == LOW){}
        printC = 0;
      break;

      case 3:
        clearTerminal();
        delay(50);
        Serial.println(F("Bye"));
        playShutdownSound();
        ExitLed();
        exit(0);
      break;

      default:
        clearTerminal();
        Serial.print(F("Non valid input\n"));
        printC = 0;
      break;
    }
  }
  
}