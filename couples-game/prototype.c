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
  bool used;
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
char *s;
struct player p;
const char *NAMELIST_PLAYERS[] = {"Rod", "Ira"};
const char *NAMELIST_SPECIAL[] = {"NOTE","SONG"};
const char *NAMELIST_INVENTORY[][3] = {
  {"NOTEBOOK","LAPTOP","PANTERA"},
  {"PHONE","GUITAR","LAPTOP"}
};

//=========MACROS==========
#define HEAD {system("clear"); 	printf("\n ~~~RODRIGO AND IRA'S ADVENTURE~~~  \n\n");}
#define PROMPT(c) {printf("\n\nYour choice: "); scanf(" %c", &c);}
//TODO add define PROMPTSTRING(s)

//========PROTOTYPES=======

//P1 methods

void p1_start();
void p1_level1();
void r_laptop();
void notebook();
void pet_cat();

//P2 methods
void p2_start();
void p2_level1();
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
    p.special_inventory[i].used = false;
  }
  //loops through inventory, assigning false to all.
  for(int i = 0; i < INVENTORY_SIZE; i++){
    p.inventory[i].held = false;
    p.inventory[i].used = false;
  }
}

void p1_start(){
	HEAD
	  printf("You are %s. A hottie!\n", p.name);
	printf("You are in your room in Tegucigalpa, just chilling.");
	sleep(1);
	p1_level1();
}

void p1_level1(){
printf(" You have your NOTEBOOK and your LAPTOP. PANTERA is sleeping on your BED."
		"\n\nWhat do you want to do?\n\n");

	while(1){
		printf("[1]-Check your NOTEBOOK \t[2]-Open your LAPTOP \t[3]-Pet PANTERA\n\n");
		PROMPT(c)
			switch(c) {
			case '1':
			  notebook();
			  break;
			case '2':
			  r_laptop();
			  break;
			case '3':
			  pet_cat();
			  break;
			}
}
}



void notebook(){
	HEAD
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
	sleep(1);
	p2_level1();
}

/*
  Level 1 layout:
  Ira has a PHONE, GUITAR, and LAPTOP.
  Her objective is to get herself to leave the room.
  Super basic logic:
  Checking her phone will give her SONG 1.
  Playing SONG 1 will change her mood to HAPPY, unlocking her laptop.

  Using her laptop will give no special use.
  However, getting the SUPERHINT from P1 will reveal what to do.
  If Ira accesses her calendar, she'll realize she has a pending appt.
  
 */

void p2_level1() {
  printf("Ira: Oh man, oh jeez... I feel so lazy... ");
  sleep(1);
  printf("I don't wanna get up...");
	while(1){
	  HEAD
	  printf("\n\n You are in your room in Boston."
		 "\nYou have your LAPTOP, your PHONE, and a GUITAR."
		"\n\nWhat do you want to do?\n\n");
		printf("[1]-Check your PHONE \t[2]-Play the GUITAR \t[3]-Open your LAPTOP\n");
		PROMPT(c)
			switch (c){
			case '1':
			  phone();
			  break;
			case '2':
			  guitar();
			  break;
			case '3':
			  i_laptop();
			  break;
			}
	}
}


// P2 INVENTORY 0
void phone(){
	HEAD
	  if (p.inventory[0].name != NULL){
	    strncpy(p.inventory[0].name, NAMELIST_INVENTORY[1][0], COLLECTIBLE_NAME_LENGTH);
	  }
	 printf("This is your phone. It has a clear cover, and a cute drawing of you! \n\nWhat do you want to do?\n"   
		   "\n[1]-Browse on Instagram [2]-Listen to some music [3]-Check Whatsapp");
	    PROMPT(c)
	    switch(c) {
	    case '1':
	      printf("\nYou scroll for a while."
		     "\n.");
	      sleep(1);
	      printf(".");
	      sleep(1);
	      printf(".");
	      sleep(1);
	      printf("\nOkay, time to stop!\n");
	      sleep(1);
	      break;
	      
	    case '2':
	      printf("\nYou play your Eurovision soundtrack."
		     "I'm in loooooove... with a fairy taaaail....."
		     );
	      sleep(1);
	      printf("That was fun!\n");
	      sleep(1);
	      if(p.special_inventory[0].name != NULL){
	      printf("YOU LEARNED A NEW SONG: FAIRYTALE\n");
	      strncpy(p.inventory[0].name, "FAIRYTALE", COLLECTIBLE_NAME_LENGTH);
		}
	      sleep(1);
	      break;
	      
	    case '3':
	      printf("\nNo new messages. Sad!\n");
	      sleep(1);
	      break;
	    }
	
}

void guitar(){
	HEAD
		printf("\nYou take out your guitar to practice.\n");

	//check if there are known songs
	// elegant solution: prompt a string.
	// if string matches a name inside of the held, then accepts.
	//if not, exit
	//GIVES HINT FOR P1
	// 
	
}

void i_laptop(){
	HEAD
		printf("You open your laptop.");
	//prompt what to look up

	//idk about how to place it but EVENTUALLY should have
	// the final prompt for calendar.
	//CALENDAR unlocks going outside, completing the level.
}


