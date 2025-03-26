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
#define PROMPT_STRING_SIZE 20


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
char s[PROMPT_STRING_SIZE];
struct player p;
const char *NAMELIST_PLAYERS[] = {"Rod", "Ira"};
const char *NAMELIST_SPECIAL[] = {"NOTE","SONG"};
const char *NAMELIST_INVENTORY[][3] = {
  {"NOTEBOOK","LAPTOP","PANTERA"},
  {"PHONE","GUITAR","LAPTOP"}
};
const char *NAMELIST_WEBSITES[] = {"CALENDAR","NETFLIX","YOUTUBE"};
const char *NAMELIST_PROGRAMS[] = {"ALARM", "CALENDAR","TIMER"};


//=========MACROS==========
//clears screen and adds header for game throughout
#if defined(_WIN64)
# define CLEAR {system("cls");}
#else
# define CLEAR {system("clear");}
#endif
#define HEAD {CLEAR	printf("\n ~~~RODRIGO AND IRA'S ADVENTURE~~~  \n\n");}

// prompts single char, mainly for number prompts
#define PROMPT(c) {printf("\n\nYour choice: "); scanf(" %c", &c);}

// prompts PROMPT_STRING_SIZE string, for items and special items
#define PROMPTSTRING(s) {printf("\n\nYour choice (write it in ALL-CAPS!): "); scanf("%s", &s);}



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
printf("You have your NOTEBOOK and your LAPTOP. PANTERA is sleeping on your BED."
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
	printf("You take out your notebook. What to write?");
	PROMPTSTRING(s)
}

void pet_cat(){
	HEAD
	printf("You pet Pantera's head. He purrs.");
}

void r_laptop(){
	HEAD
	printf("You take out your laptop to write some code."
	       "\nWhat to code?");
	PROMPTSTRING(s)
}
//=============================PLAYER 2 stages=================================

void p2_start(){
	HEAD
	printf("You are Ira. A cutie!\n\n");
	sleep(1);
	p2_level1();
}


void p2_level1() {
  printf("Ira: Oh man, oh jeez... I feel so lazy... ");
  sleep(1);
  printf("I don't wanna get up...");
  sleep(1);
	while(1){
	  HEAD
	  printf("\n\nYou are in your room in Boston."
		 "\nYou have your LAPTOP, your PHONE, and a GUITAR."
		"\n\nWhat do you want to do?\n\n");
		printf("[1]-Open your Laptop \t[2]-Check your PHONE \t[3]-Play the Guitar\n");
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


// P2 INVENTORY 0
void phone(){
	HEAD
	  if (p.inventory[0].name != NULL){
	    strncpy(p.inventory[0].name, NAMELIST_INVENTORY[1][0], COLLECTIBLE_NAME_LENGTH);
	  }
	 printf("This is your phone. It has a clear cover, and a cute drawing of you! \n\nWhat do you want to do?\n"   
		   "\n[1]-Browse on Instagram\t[2]-Check your Whatsapp\n[3]-Listen to some music\t[4]-Put the phone away");
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
	      continue;

	      case '2':
	      printf("\nNew message from RODRIGO:\n");
	      sleep(1);
	      printf("\n\tHi love! Hope you're doing okay today!");
	      sleep(1);
	      printf("\n\tI'm here to give you a hint or two.");
		     "\n\tHave you played on your GUITAR lately? You keep telling me it's so great for your mood!"
		     "\n\tThat's all from me, bye!!!");
	    sleep(3);
	      continue;
	      
	    case '3':
	      printf("\nYou play a song from your eurovision playlist."
		     "\nI'm in loooooove... with a fairy taleeeee....."		     );
	      sleep(1);
	      printf("\nThat was fun!\n");
	      sleep(1);
	      if(p.special_inventory[0].name != NULL){
	      printf("YOU LEARNED A NEW SONG: FAIRYTALE\n");
	      sleep(1);
	      strncpy(p.inventory[0].name, "FAIRYTALE", COLLECTIBLE_NAME_LENGTH);
		}
	      sleep(1);
	      continue;
	      
	    
	    }
	
}

void guitar(){
	HEAD
		printf("\nYou take out your guitar to practice."
		       "\nWhat do you wanna play?");
	PROMPTSTRING(s)	  
	// elegant solution: prompt a string.
	  /* Version one, haven't tested
	  (I think I was going to do a different version? Maybe with a switch statement? Idk.*/
	  int tmp = -1;
	  for(int i = 0; i < SPECIAL_SIZE; i++) {
	    if((strcmp(s, p.special_inventory[i].name) == 0) && p.special_inventory[i].held == true){
	      tmp = i;
	    }
	  }

	  if(tmp >= 0){
	  printf("You played %s!", p.special_inventory[tmp].name);
	  p.special_inventory[tmp].used = true;
	  }
	  switch(tmp){
	  case 0:
	    printf("I feel so relaxed and optimistic...that was fun!");
	    sleep(1);
	    printf("You feel ENERGIZED!");
	    break;
	  default:
	    printf("Eh...what's that song again? I think I forgot!"
		   "\nHmm...I should go listen to some music...");
	    sleep(1);
	    printf("You put away your guitar for now.");
	    break;
	  }
	  sleep(1);
	
}

void i_laptop(){
	HEAD
	printf("Here's my Macbook. I'm keeping it in a nice pink leather cover!"
	       "\nSuch good taste!");

	//Check to see if FAIRYTALE was played
	if (!p.special_inventory[0].used){
	  printf("Man... I don't really feel like it..."
		 "if only I felt a bit more energized...");
	}
	else{
	  printf("I'm feeling energized enough! Let's see what we can do...");
	  printf("What are you checking on the internet?");
	//prompt what to look up
	PROMPTSTRING(s)
	//idk about how to place it but EVENTUALLY should have
	// the final prompt for calendar.
	//CALENDAR unlocks going outside, completing the level.
	  }
	sleep(1);
}


