# Duel-The-Game
RPG game that developed for Arduino 

## Menu
- Play 
- Guide 
- Exit
- Button(to stop music and go on with the game)

## Class Choosing Menu
- Berserk 
- Mage 
- Elf

## Game Mechanic Breakdown
(Game depends on luck for most cases)
Main villian is troll master and He sents trolls to deal with our hero. Every troll has different stats based on randomization(this is our luck factor). 
### Luck based events
- Every turn we have a chance to randomly find a sword (35 percent chance) 
- Get a blessing from the mage (25 percent chance)

Accordingly, our strength will increase. For example, If we meet a
sword as in the picture, our strength will increase by 1 point.

In addition, if we come across the poison of the troll master (20 percent chance), our power will
decrease. 

### Proximity Sensor's role in game

According to the proximity distance values of our hero, he can take two kinds of positions:
#
1. Attack: When the hero is in this position, his characteristics change as follows

a. Strength +1

b. Magic -1

c. Speed +1
#
2. Defense: When the hero is in this position, his characteristics change as follows

a. Magic +1

b. Speed -1
#
### Level System
If our hero can beat 4 trolls in a row then Troll Master sends a BOSS monster which is a dragon.

The stats of these dragons are higher than trolls
(Definitely 6. It becomes a level property, and the lowest level property is 4. In addition, as the
round progresses, the characteristics of the trolls become higher and stronger opponents appear in
front of us.

based on luck its one of the following:
- Fire Dragon Balrog
- Ice Dragon Viserion

### Endgame
- Won ( Cute background music will play on ) 
- Lose : 
Game asks to user if want to continue the game. In that case we’ll start the duel again. If we don’t
continue, the code will terminate itsef and arduino.
