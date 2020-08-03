#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ppt.hpp"


void init_markov(struct Markov_node *node){

	node->nb_times = 0;
	//Number of times transition from current to Rock
	node->nb_times_toR = 0;
	//Number of times transition from current to Paper
	node->nb_times_toP = 0;
	//Number of times transition from current to Scissors
	node->nb_times_toS = 0;
	//Probability next move is Rock
	node->proba_R = 1.0/3;
	//Probability next move is Paper
	node->proba_P = 1.0/3;
	//Probability next move is Scissors
	node->proba_S = 1.0/3;
}

void print_markov_node(struct Markov_node *node){
	std::cout << "New Markov Update: \n";
	std::cout << "Nb_times = " + std::to_string(node->nb_times) + " .\n";
	std::cout << "nb_times_toR = " + std::to_string(node->nb_times_toR) + " .\n";
	std::cout << "nb_times_toP = " + std::to_string(node->nb_times_toP) + " .\n";
	std::cout << "nb_times_toS = " + std::to_string(node->nb_times_toS) + " .\n";
	std::cout << "proba_R = " + std::to_string(node->proba_R) + " .\n";
	std::cout << "proba_P = " + std::to_string(node->proba_P) + " .\n";
	std::cout << "proba_S = " + std::to_string(node->proba_S) + " .\n";

}


void update_markov(struct Markov_node *node, std::string obs_choice){
	
	print_markov_node(node);

	node->nb_times = node->nb_times + 1;
	if (obs_choice == "r"){
		node->nb_times_toR = node->nb_times_toR + 1;
	} else if (obs_choice == "p"){
		node->nb_times_toP = node->nb_times_toP + 1;
	} else if(obs_choice == "s"){
		node->nb_times_toS = node->nb_times_toS +1;
	} else {
		std::cout << "Invalid choice";
	}
	
	//Probability next move is Rock
	//Added 1.0 * to avoid int division
	node->proba_R = 1.0 * node->nb_times_toR/node->nb_times;
	//Probability next move is Paper
	node->proba_P = 1.0 * node->nb_times_toP/node->nb_times;
	//Probability next move is Scissors
	node->proba_S = 1.0 * node->nb_times_toS/node->nb_times;

	print_markov_node(node);
}


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

std::string markov_choice(struct Markov_node *node){
	//If the user is more likely to choose Rock --> Let's choose Paper
	if ((node->proba_R >= node->proba_P) && (node->proba_R >= node->proba_S)){
		return "p";
	}
	//If the user is more likely to choose Paper --> Let's choose Scissors
	if ((node->proba_P >= node->proba_R) && (node->proba_P >= node->proba_S)){
		return "s";
	}
	//If the user is more likely to choose Scissors --> Let's choose Rock
	if ((node->proba_S >= node->proba_R) && (node->proba_S >= node->proba_P)){
		return "r";
	}
	return "e";
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

void display_statistics(int nb_games_user_won,int nb_games_machine_won,int nb_games_tie){
	std::cout << "Statistics : you won " + std::to_string(100 * nb_games_user_won/ (nb_games_machine_won + nb_games_user_won + nb_games_tie))+ " percent of the games\n";
	std::cout << "Statistics : you lost " + std::to_string(100 * nb_games_machine_won/ (nb_games_machine_won + nb_games_user_won + nb_games_tie))+ " percent of the games\n";
	std::cout << "Statistics : you tied " + std::to_string(100 * nb_games_tie/ (nb_games_machine_won + nb_games_user_won + nb_games_tie))+ " percent of the games\n";

}

