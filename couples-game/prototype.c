#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A proof of concept, meant to compile on my terminal and that's it.

   TODO add functionality for MAC
 */

//TODO add a prompt Macro

char x;

void p1_start();
void r_laptop();
void notebook();
void pet_cat();

void p2_start();
void i_laptop();
void phone();
void guitar();

char c;
#define HEAD {system("clear"); 	printf("\n ~~~RODRIGO AND IRA'S ADVENTURE~~~  \n\n");}
#define PROMPT(c) {printf("Your choice: "); scanf(" %c", &c);}




int main () {
	while(c != 1 || c != 2){
		HEAD
		printf("Choose your player: \n [1]-Rodrigo\n [2]-Ira\n\n");
	        PROMPT(c)
		if(c == '1') {
			p1_start();
			break;
		}
		if(c == '2') {
			p2_start();
			break;
		}
		else {
			printf("\nYou have to choose 1 or 2.\n");
			sleep(1);
		}
	}
}

void p1_start(){
	HEAD
	printf("You are Rodrigo. A hottie!\n");
	printf("You are in your room in Tegucigalpa, just chilling."
		"You have your NOTEBOOK and your LAPTOP. PANTERA is sleeping on your BED."
		"\n\nWhat do you want to do?\n\n");

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

void r_laptop(){
	HEAD
	printf("You take out your laptop");
}

void notebook(){
	HEAD
	printf("You take out your notebook.");
}

void pet_cat(){
	HEAD
	printf("You pet Pantera's head. He purrs.");
}


//=============================PLAYER 2 stages=================================

void p2_start(){
	HEAD
	printf("You are Ira. A cutie!\n\n");
	printf("You are in your room in Boston, just chilling."
		"You have your LAPTOP, your PHONE, and a GUITAR."
		"\n\nWhat do you want to do?\n\n");

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
