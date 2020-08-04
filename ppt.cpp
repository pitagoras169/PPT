/*-----------------------------------------------------------------
Rock Paper Scissors Game

Author : Guillermo PITA GIL
Created : 02 - Aug - 2020

Algorithm : 

	- using 3 markov chains : one different after a win/loose/tie
	- transition probabilities estimated by max likelyhood
	- games logged for further analysis in text files

-----------------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <chrono>
#include <ctime>   
#include "ppt.hpp"



std::string get_user_choice(void){
	//Function to get the human user choice from terminal
	std::string user_c;
	std::cout << "What is your next move ? Rock (r), Paper (p) or Scissors (s) ? Quit (q) ";
	std::cin >> user_c;
	return user_c;
}

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


void init_all_markov(Markov_node *RW, Markov_node *RL, Markov_node *RT,Markov_node *PW, Markov_node *PL, Markov_node *PT,Markov_node *SW, Markov_node *SL, Markov_node *ST){

	//Init all sets of nodes to equal probability
	init_markov(RW);
	init_markov(RL);
	init_markov(RT);
	init_markov(PW);
	init_markov(PL);
	init_markov(PT);
	init_markov(SW);
	init_markov(SL);
	init_markov(ST);

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


void display_result_current (int winner_current){
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

void display_exit_message(void){
	std::cout << "Thanks for playing with me. Hope to see you soon :-)\n";
}



void save_log_file(std::string user_choice_history,std::string machine_choice_history){

	std::string log_file_name;

	//Create the log file name using the date and time
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

	log_file_name = "log_rps_" + std::to_string((now->tm_year + 1900)) + "-";
	log_file_name += std::to_string((now->tm_mon + 1)) + "-";
	log_file_name += std::to_string(now->tm_mday) + "@";
	log_file_name += std::to_string(now->tm_hour) + "h";
	log_file_name += std::to_string(now->tm_min) + "m";
    log_file_name += std::to_string(now->tm_sec) + "s";
	log_file_name += ".txt";

	std::ofstream outfile (log_file_name);

	outfile << "User choice history: " + user_choice_history << std::endl;
	outfile << "Machine choice history: " + machine_choice_history << std::endl;

	//Close the log file
	outfile.close();
}

void add_statistics(int winner_current, int *nb_games_tie, int *nb_games_user_won, int *nb_games_machine_won){

	switch (winner_current){
		case 0 : 
			*nb_games_tie = *nb_games_tie + 1;
			break;
		case 1 :
			*nb_games_user_won = *nb_games_user_won +1;
			break;
		case 2 : 
			*nb_games_machine_won = *nb_games_machine_won +1;
			break;
		default :
			std::cout << "Error who_won\n";
	}
}

void display_machine_choice(std::string machine_choice){
	//Display the machine's choice for the current game
	std::string machine_choice_msg;
	machine_choice_msg = choice_machine_toString(machine_choice);
	std::cout << "Machine Choice = " + machine_choice_msg + "\n";

}



std::string get_machine_next_move(int winner_previous,std::string user_choice_previous,Markov_node *RT,Markov_node *PT,Markov_node *ST,Markov_node *RW,Markov_node *PW,Markov_node *SW,Markov_node *RL,Markov_node *PL,Markov_node *SL){
	std::string machine_choice;
	switch (winner_previous){
		//If the previous game was a tie
		case 0 :
			if (user_choice_previous == "p"){
				machine_choice = markov_choice(PT);
			} else if (user_choice_previous =="r"){
				machine_choice = markov_choice(RT);
			}else if(user_choice_previous == "s"){
				machine_choice = markov_choice(ST);
			}else{
				std::cout << "Error in calculating machine's choice\n";
				machine_choice = random_ppt();
			}
			break;
		//Previous game the user won
		case 1 :
			if (user_choice_previous == "p"){
				machine_choice = markov_choice(PW);
			} else if (user_choice_previous =="r"){
				machine_choice = markov_choice(RW);
			}else if(user_choice_previous == "s"){
				machine_choice = markov_choice(SW);
			}else{
				std::cout << "Error in machine's choice\n";
				machine_choice = random_ppt();
			}
			break;
		//Previous game the user lost
		case 2 :
			if (user_choice_previous == "p"){
				machine_choice = markov_choice(PL);
			} else if (user_choice_previous =="r"){
				machine_choice = markov_choice(RL);
			}else if(user_choice_previous == "s"){
				machine_choice = markov_choice(SL);
			}else{
				std::cout << "Error in machine's choice\n";
				machine_choice = random_ppt();
			}
			break;
		default : 
			std::cout << "Error while calculating machine's choice\n";
	}

	return machine_choice;

}

void update_all_markov(int winner_previous,std::string user_choice, std::string user_choice_previous,Markov_node *RT,Markov_node *PT,Markov_node *ST,Markov_node *RW,Markov_node *PW,Markov_node *SW,Markov_node *RL,Markov_node *PL,Markov_node *SL){
	//Update markov's weights
	switch (winner_previous){
		//If the previous game was a tie
		case 0 :
			if (user_choice_previous == "p"){
				update_markov(PT,user_choice);
			} else if (user_choice_previous =="r"){
				update_markov(RT, user_choice);
			}else if(user_choice_previous == "s"){
				update_markov(ST, user_choice);
			}else{
				std::cout << "Error in markov update\n";
			}
			break;
		//Previous game the user won
		case 1 :
			if (user_choice_previous == "p"){
				update_markov(PW,user_choice);
			} else if (user_choice_previous =="r"){
				update_markov(RW, user_choice);
			}else if(user_choice_previous == "s"){
				update_markov(SW, user_choice);
			}else{
				std::cout << "Error in markov update\n";
			}
			break;
		//Previous game the user lost
		case 2 :
			if (user_choice_previous == "p"){
				update_markov(PL,user_choice);
			} else if (user_choice_previous =="r"){
				update_markov(RL, user_choice);
			}else if(user_choice_previous == "s"){
				update_markov(SL, user_choice);
			}else{
				std::cout << "Error in markov update\n";
			}
			break;
		default : 
			std::cout << "There was an error in the markov update\n";
	}
		
}


