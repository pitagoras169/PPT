#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ppt.hpp"




std::string random_ppt (void){
	//Function to determine a random choice of Rock Paper Scissors
	int random_choice;
	std::string random_choice_string;
	srand (time(NULL));
	random_choice = rand()%3 +1;
	switch (random_choice){
		case 1 : 
			//In the case of Rock
			random_choice_string = "r";
			break;
		case 2 : 			
			//In the case of Paper
			random_choice_string = "p";
			break;
		case 3 : 			
			//In the case of Scissors
			random_choice_string = "s";
			break;
		default : 
			//In case the is a error outputs E to track it
			random_choice_string = "E";
	}
	return random_choice_string;
}

int who_won(std::string user_choice,std::string machine_choice){
	/*This function calculates who won.
	0 : means there is a tie
	1 : means the user won
	2 : means the machine won
	3 : there was an error
	*/

	//start with a tie. 
	int result_who_won = 0;

	//If user chooses Rock
	if (user_choice == "r") { 
		if (machine_choice == "p"){
			result_who_won = 2;
		}
		if (machine_choice == "s"){
			result_who_won = 1;
		}
	
	//If user chooses Paper	
	} else if (user_choice == "p"){
		if (machine_choice == "s"){
			result_who_won = 2;
		}
		if (machine_choice == "r"){
			result_who_won = 1;
		}
	
	//If user chooses Scissors	
	} else if (user_choice == "s"){
		if (machine_choice == "r"){
			result_who_won = 2;
		}
		if (machine_choice == "p"){
		result_who_won = 1;
		}

	//If the user didn't choose a valid input
	} else {
		result_who_won = 3;
	}

	//Return the result of the match
	return result_who_won;
}


void output_result_current (int winner_current){
	switch (winner_current) {
		case 0 :
			std::cout << "There is a tie\n";
			break;
		case 1 : 
			std::cout << "You won!\n";
			break;
		case 2 : 
			std::cout << "You loose!\n";
			break;
		case 3 :
			std::cout << "Invalid Choice\n";
			break;
		default:
			std::cout <<"Error\n";
	}
}

std::string choice_machine_toString(std::string machine_choice){
	if (machine_choice == "r"){
		return "Rock";
	} else if (machine_choice == "p"){
		return "Paper";
	} else if (machine_choice == "s"){
		return "Scissors";
	} else{
		return "Error";
	}
}
