#include <stdio.h>
#include <stdlib.h>

typedef struct Position{
    int x;
    int y;
}Position;

typedef struct Mob{
    int attack;
    int defence;
    int lifePoint;
    Position pos;
}Mob;

typedef struct Player{
    int life;
    int isDead;
    Mob playerMob;
}Player;

typedef struct MapGame{
    int arrayGame[0][0];
    int mapHeight;
    int mapWidth;
    Mob mobs[0];
    int countMobs;
    Player myPlayer;
} MapGame;

int hitMob(Mob mobAttack, Mob mobDef){
    return mobAttack.attack - mobDef.defence;
}

int defPlayer(Mob mobAttack, Player playerDef){
    printf("player have %d life points \n", playerDef.playerMob.lifePoint);
    return mobAttack.attack - playerDef.playerMob.defence;
}

char inputChar(){
    int userChoise = 1;
    char userNumber[1];

    while(userChoise){
        scanf ("%s", userNumber);

            userChoise = atoi(userNumber);
            if(userChoise == 0){
                    return *userNumber;
            }else{
                userChoise = 1;
            }
            printf ("Please use just alpha");
    }

    return 0;
}

int main()
{
    //Create player
    struct Position posPlayer;
    posPlayer.x = 0;
    posPlayer.y = 0;

    struct Mob playerMob;
    playerMob.attack = 3;
    playerMob.defence = 1;
    playerMob.lifePoint = 9;
    playerMob.pos = posPlayer;

    struct Player player;
    player.isDead = 1;
    player.life = 4;
    player.playerMob = playerMob;

    //Create mob1
    struct Position posMob1;
    posMob1.x = 2;
    posMob1.y = 1;

    struct Mob mob1;
    mob1.attack = 2;
    mob1.defence = 1;
    mob1.lifePoint = 6;
    mob1.pos = posMob1;

    //Create mob2
    struct Position posMob2;
    posMob2.x = 2;
    posMob2.y = 1;

    struct Mob mob2;
    mob2.attack = 10;
    mob2.defence = 1;
    mob2.lifePoint = 6;
    mob2.pos = posMob1;

    while(player.isDead){
        player.playerMob.lifePoint = defPlayer(mob2, player);
        printf("player have %d life points \n", player.playerMob.lifePoint);
        if(player.playerMob.lifePoint <= 0){
            player.life --;
            if(player.life <= 0){
                player.isDead = 0;
            }
        }
        inputChar();
    }

    printf("you loose \n");

    return 0;
}
