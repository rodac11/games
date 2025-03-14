#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/* A proof of concept, meant to compile on my terminal and that's it.

   TODO add functionality for MAC
 */


//========VARIABLES=======


#define COLLECTIBLE_NAME_LENGTH  20
#define COLLECTIBLE_SET_NAME 10
#define INVENTORY_SIZE 12
#define SPECIAL_SIZE 6
#define PLAYER_NAME_SIZE 3
#define SPECIAL_NAME_LENGTH 4
#define INT_LENGTH 4

//========STRUCTS=========

struct collectible {
  char name[COLLECTIBLE_NAME_LENGTH];
  char set[COLLECTIBLE_SET_NAME];
  bool held;
};

struct player {
  int id;
  char name[PLAYER_NAME_SIZE];

  struct collectible special_inventory[SPECIAL_SIZE];
  struct collectible inventory[INVENTORY_SIZE];
};

//========GLOBALS======
char x;
char c;
struct player p;
const char *NAMELIST_PLAYERS[] = {"Rod", "Ira"};
const char *NAMELIST_SPECIAL[] = {"NOTE","SONG"};
const char *NAMELIST_INVENTORY[][3] = {
  {"NOTEBOOK","PANTERA","LAPTOP"},
  {"PHONE","GUITAR","LAPTOP"}
};

//=========MACROS==========
#define HEAD {system("clear"); 	printf("\n ~~~RODRIGO AND IRA'S ADVENTURE~~~  \n\n");}
#define PROMPT(c) {printf("Your choice: "); scanf(" %c", &c);}

//========PROTOTYPES=======

//P1 methods

void p1_start();
void r_laptop();
void notebook();
void pet_cat();

//P2 methods
void p2_start();
void i_laptop();
void phone();
void guitar();

//shared methods (is this a good idea?)
void player_init(int pnum);

//======METHODS=======

 int main () {
	while(c != 1 || c != 2){
		HEAD
		printf("Choose your player: \n [1]-Rodrigo\n [2]-Ira\n\n");
	        PROMPT(c)
		if(c == '1') {
		  player_init(0); // 1 becomes 0 for array's sake
			p1_start();
			break;
		}
		if(c == '2') {
		  player_init(1);// 2 becomes 1 for array's sake
			p2_start();
			break;
		}
		else {
			printf("\nYou have to choose 1 or 2.\n");
			sleep(1);
		}
	}
}

void player_init(int pnum) {
  //assign player id and player name
  p.id = pnum;
  strncpy(p.name, NAMELIST_PLAYERS[pnum], PLAYER_NAME_SIZE);

  //helper variables for special loop
  char id[INT_LENGTH];
  char special_name[SPECIAL_NAME_LENGTH];
  strncpy(special_name, NAMELIST_SPECIAL[pnum], SPECIAL_NAME_LENGTH);

  //loops through special, assigning player-specific set name.
  for(int i = 0; i < SPECIAL_SIZE; i++){
    strncpy(p.special_inventory[i].set, special_name, SPECIAL_NAME_LENGTH);
    p.special_inventory[i].held = false;
  }
  //loops through inventory, assigning false to all.
  for(int i = 0; i < INVENTORY_SIZE; i++){
    p.inventory[i].held = false;
  }
}

void p1_start(){
	HEAD
	  printf("You are %s. A hottie!\n", p.name);
	printf("You are in your room in Tegucigalpa, just chilling."
		" You have your NOTEBOOK and your LAPTOP. PANTERA is sleeping on your BED."
		"\n\nWhat do you want to do?\n\n");

	for(int i = 0; i < SPECIAL_SIZE; i++){
	  printf("%d",i);
	  printf("%s", p.special_inventory[i].set);
	  printf(" %d\n", p.special_inventory[i].held);
	}

	while(1){
		printf("[1]-Open your LAPTOP \t[2]-Check your NOTEBOOK \t[3]-Pet PANTERA\n\n");
		PROMPT(c)
			switch(c) {
			case '1':
				r_laptop();
				break;
			case '2':
				notebook();
				break;
			case '3':
				pet_cat();
				break;
			}
}
}



void notebook(){
	HEAD
	  if(p.inventory[1] != null){}
	printf("You take out your notebook.");
}

void pet_cat(){
	HEAD
	printf("You pet Pantera's head. He purrs.");
}

void r_laptop(){
	HEAD
	printf("You take out your laptop");
}
//=============================PLAYER 2 stages=================================

void p2_start(){
	HEAD
	printf("You are Ira. A cutie!\n\n");
	printf("You are in your room in Boston, just chilling."
		" You have your LAPTOP, your PHONE, and a GUITAR."
		"\n\nWhat do you want to do?\n\n");

	for(int i = 0; i < SPECIAL_SIZE; i++){
	  printf("%d",i);
	  printf("%s", p.special_inventory[i].set);
	  printf(" %d", p.special_inventory[i].held);
	}

	while(1){
		printf("[1]-Open your LAPTOP \t[2]-Check your PHONE \t[3]-Play the GUITAR\n\n");
		PROMPT(c)
			switch (c){
			case '1':
				i_laptop();
				break;
			case '2':
				phone();
				break;
			case '3':
				guitar();
				break;
			}
	}
}

void i_laptop(){
	HEAD
		printf("You open your laptop.");
}

void phone(){
	HEAD
		printf("You check your phone.");
}

void guitar(){
	HEAD
		printf("You take out your guitar. What do you play?");
}




