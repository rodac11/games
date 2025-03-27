#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>

/* A proof of concept, meant to compile on my terminal and that's all.

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
#define MISC_NAMELIST_SIZE 3
#define LEVEL_COUNT 1


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
  bool level_beat[LEVEL_COUNT];
};

//========GLOBALS======
char x;
char c;
char s[PROMPT_STRING_SIZE];
int currentlevel;
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
# define CLEAR "cls"

//keeping sleeptime as different just in case
//apparently windows sleep is in ms?
# define SLEEPTIME 1
#else
# define CLEAR "clear"
# define SLEEPTIME 1
#endif

// prompts single char, mainly for number prompts

// prompts PROMPT_STRING_SIZE string, for items and special items
#define PROMPTSTRING(s) {printf("\n\nYour choice (write it in ALL-CAPS!): "); scanf("%s", &s);}
#define PROMPT(c) {printf("\n\nYour choice: "); scanf(" %c", &c);}


//========PROTOTYPES=======

//P1 methods
void p1_start();
void p1_level0();
void p1_level1();
void r_laptop();
void notebook();
void pet_cat();

//P2 methods
void p2_start();
void p2_level0();
void p2_level1();
void i_laptop();
void phone();
void guitar();

// shared methods
void player_init(int pnum);
void level_complete();

// helper methods
void dsleep();
void ellipsis();

//======METHODS=======

void complete_level(){
  p.level_beat[currentlevel] = 1;
}

int level_is_completed(){
  int d = p.level_beat[currentlevel];
  return d;
}

void dsleep(int i){
  sleep(SLEEPTIME * i);
}

void ellipsis(){
  printf("\n");
  for (int i=0;i<3;i++){
    printf(".");
    dsleep(1);
  }
}

void head(){
  system(CLEAR);
  printf("\n ~~~RODRIGO AND IRA'S ADVENTURE~~~  \n\n");
}

void prompt(char *p){
  //I think this works?
  //You give a pointer to global c char, and here it scans a value into that pointer
  //thus changing the value of c.
  //(right?)
  printf("\n\nYour choice: ");
  scanf(" %c", p);
}

void promptstring(char (*p)[20]){
  // printf();
    printf("\n\nYour choice (WRITE IT IN ALL CAPS!): ");
    scanf("%s", p);
}

 int main () {
	while(c != 1 || c != 2){
	  head();
	
		printf("Choose your player: \n [1]-Rodrigo\n [2]-Ira\n\n");
	        //PROMPT(c)
		prompt(&c);
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
  head();
  printf("You are %s. Heyo!\n", p.name);
  printf("You are in your room in Tegucigalpa, just chilling.\n");
  dsleep(2);
  p1_level0();
}

void p1_level1(){
  printf("Thanks for playing babo!!! <333");
  dsleep(10);
  exit(0);
}

void p1_level0(){
printf("You have your NOTEBOOK and your LAPTOP. PANTERA is sleeping on your BED."
		"\n\nWhat do you want to do?\n\n");

	while(1){
		printf("[1]-Check your NOTEBOOK \t[2]-Open your LAPTOP \n[3]-Pet PANTERA\n\n");
		if(level_is_completed()==1) printf("\t[4]-Go downstairs");
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
			case '4':
			  if(level_is_completed()==1){
			    p1_level1();
			  }
			}
}
}



void notebook(){
  head();
  //check if cat has been pet.
  //hacky check, Pantera is "in" the inventory.
  //oh well. works for now.
  if(p.inventory[2].held==false){
    printf("\nYou take out your notebook.");
    dsleep(2);
    printf("\nHmm...where did you leave it?");
    ellipsis();
    printf("\nYou looked everywhere for it."
	   "\nYou couldn't find it!");
    dsleep(2);
    return;
  }
	printf("\nYou take out your notebook. What to do?");
	printf("\n\n[1]-Check previous notes\t[2]-Write a new note");
	prompt(c);
	
	  //notes provide ideas that work out in the real world.
	  //on zero level, these will provide some coding ideas.
	  //
}

  void pet_cat(){
    head();
  printf("You pet Pantera's head. He purrs.");
  //add inventory check = true
  //that way notebook can check.
  //after that, have normal loop.
}

void r_laptop(){
  head();
  //check if idea 1 is had.
  //if not, block.

  //otherwise, allow coding prompt.
  printf("You take out your laptop."
	 "\nWhat to code?");
	//MUSIC IS GOLDEN KEY, given by superhint.
	//
	PROMPTSTRING(s)
}
//=============================PLAYER 2 stages=================================

void p2_start(){
  head();
	printf("You are Ira. A cutie!\n\n");
	dsleep(1);
	p2_level0();
}

void p2_level1(){
  head();
  printf("Thanks for playing babo!!!!!!!\n");
  dsleep(10);
  exit(0);
}


void p2_level0() {
  printf("Ira: Oh man, oh jeez... I feel so lazy...\n");
  dsleep(1);
  printf("I don't wanna get up...\n");
  dsleep(3);
	while(1){
	  currentlevel = 0;
	  head();
	  printf("\n\nYou are in your room in Boston."
		 "\nYou have your LAPTOP, your PHONE, and a GUITAR.");
	  printf("\n\nWhat do you want to do?\n\n");
	  printf("[1]-Open your Laptop \t[2]-Check your PHONE \n[3]-Play the Guitar");
	  if(level_is_completed() == 1){printf("\t[4]-Go downstairs");}
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
			case '4':
			  if(level_is_completed()){
			    p2_level1();
			  }
			  break;
			}
	}
}



void phone(){
	  if (p.inventory[0].name != NULL){
	    strncpy(p.inventory[0].name, NAMELIST_INVENTORY[1][0], COLLECTIBLE_NAME_LENGTH);
	  }
	 while(1){
	   head();
	   printf("\nThis is your phone. It has a clear cover, and a cute drawing of you!\n");
	   printf("\n\nWhat do you want to do?\n" 
		  "\n[1]-Browse on Instagram \t[2]-Check your Whatsapp\n[3]-Listen to some music \t[4]-Put the phone away\n");
	   PROMPT(c)
	     switch(c) {
	     case '1':
	       printf("\nYou scroll for a while.\n");
	       ellipsis();
	       printf("\nOkay, time to stop!\n");
	       dsleep(1);
	       break;
	       
	     case '2':
	       printf("\nNew message from RODRIGO:\n");
	       dsleep(2);

	       if(p.special_inventory[0].used == false){
		 printf("\n\tHi love! Hope you're doing okay today!\n");
		 dsleep(2);
		 printf("\n\tI'm here to give you a hint or two."
			"\n\tHave you played on your GUITAR lately?"
			"\n\tYou keep telling me it's so great for your mood!");
		 dsleep(3);
		 printf("\n\tLet me know if you end up playing something!");
		 dsleep(3);
		 printf("\n\tThat's all from me, bye!!!");
	       }
	       else {
		 printf("\n\tHi love! What's up?");
		 ellipsis();
		 printf("\n\tOh, cool! You played a song on your guitar!");
		 dsleep(2);
		 printf("\n\tYou must feel really relaxed now!");
		 dsleep(1);
		 
		 printf("\n\tI think I'll do a similar thing...");
		 dsleep(2);
		 printf("\n\tYou gave me a cool idea!");
		 dsleep(2);
		 printf("\n\tI'll try programming a MUSIC application...");
		 dsleep(2);
		 printf("\n\tThanks a lot, baby! Byeee <333");
		 dsleep(5);
	       }
	       dsleep(4);
	       break;
	       
	     case '3':
	       printf("\nYou play a song from your eurovision playlist."
		      "\nI'm in loooooove... with a fairy taleeeee....."		     );
	       ellipsis();
	       dsleep(2);
	       printf("\n\nThat was fun!\n");
	       dsleep(2);
	       if(strncmp(p.special_inventory[0].name, "FAIRYTALE", COLLECTIBLE_NAME_LENGTH)!=0){
		 printf("I love that song, fairytale...\n");
		 dsleep(2);
		 strncpy(p.special_inventory[0].name, "FAIRYTALE", COLLECTIBLE_NAME_LENGTH);
		 p.special_inventory[0].held = true;	       
	       }
	       dsleep(1);
	       break;
	       
	     case '4':
	       printf("\n You put your phone down.");
	       dsleep(3);
	       return;
	     }
	 }
	 
}

void guitar(){
  head();
  printf("\nYou take out your guitar to practice."
		       "\nWhat do you wanna play?");
  promptstring(&s);	  
  int tmp = -1;
	  for(int i = 0; i < SPECIAL_SIZE; i++) {
	    if((strcmp(s, p.special_inventory[i].name) == 0) && p.special_inventory[i].held == true){
	      tmp = i;
	    }
	  }
	  
	  if(tmp >= 0) {
	    printf("\nYou played %s!", p.special_inventory[tmp].name);
	    p.special_inventory[tmp].used = true;
	  }
	  switch(tmp){
	  case 0:
	    printf("\nI feel so relaxed and optimistic...that was fun!");
	    dsleep(2);
	    printf("\n\nYou feel ENERGIZED!");
	    break;
	  default:
	    printf("\nEh...what's that song again? I think I forgot!"
		   "\nHmm...I should go listen to some music...");
	    dsleep(2);
	    printf("\nYou put away your guitar for now.");
	    break;
	  }
	  dsleep(2);
	
}

void i_laptop() {
  head();
	  printf("\nHere's my Macbook. I'm keeping it in a nice pink leather cover!");
	dsleep(0.5);
	printf("\nSuch good taste!");

	dsleep(3);
	//Check to see if FAIRYTALE was played
	if (!p.special_inventory[0].used){
	  printf("\nBut...");
	  dsleep(3);
	  printf("I don't really feel like it...\n"
		 "if only I felt a bit more energized...");
	  dsleep(3);
	}
	else{
	  printf("\nI'm feeling energized enough! Let's see what we can do...");
	  printf("\nWhat website will you visit?");
	//prompt what to look up
	PROMPTSTRING(s)
	  
	  //compare given string with NAMELIST_WEBSITES
	  //store matching index on tmp
	  int tmp = -1;
	  for(int i = 0; i < MISC_NAMELIST_SIZE; i++){
	    if(strcmp(s, NAMELIST_WEBSITES[i]) == 0){
	      tmp = i;
	    }
	  }
	  
	  //switch on tmp
	  switch(tmp){
	    //if calendar, unlocks win exit
	  case 0:
	    printf("\nYou open up the calendar app that Rodrigo programmed for you.");
	    ellipsis();
	    printf("\n\nOh! I have an interview today!");
	    dsleep(1);
	    printf("\nI completely forgot! I better get ready...");
	    dsleep(3);
	    complete_level();
	    break;
	    //if netflix, dialogue
	  case 1:
	    printf("\nHmm... could watch a K-drama...");
	    ellipsis();
	    printf("\nHmm... I don't know...");
	    ellipsis();
	    printf("\nI can't decide what to watch!");
	    dsleep(2);
	    break;
	  //if youtube, dialogue
	  case 2:
	    printf("\nI could watch something on YouTube!");
	    ellipsis();
	    printf("\nBut...maybe later!");
	    dsleep(2);
	    break;
	  //default, random dialogue
	  default:
	    printf("\nNo time for that right now!");
	    dsleep(2);
	    break;
	  }
	  }
	dsleep(1);
}
