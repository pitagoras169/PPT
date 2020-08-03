#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ppt.hpp"


int main(void){

	int nb_partidas = 0;
	int iter;
	std::string user_choice;
	std::string machine_choice;
	std::string machine_choice_msg;
	int winner_current;
	int max_nb_games = MAX_GAMES;
	std::string user_choice_previous;
	int winner_previous;
	int nb_games_user_won = 0;
	int nb_games_machine_won = 0;
	int nb_games_tie = 0;
	std::string user_choice_history;
	std::string machine_choice_history;

	//Creating markov nodes
	Markov_node RW;
	Markov_node RL;
	Markov_node RT;
	Markov_node PW;
	Markov_node PL;
	Markov_node PT;	
	Markov_node SW;
	Markov_node SL;
	Markov_node ST;


	// Mensaje de bienvenida
	std::cout << "Welcome to Rock Paper Scissors. \n";


	//initialize the markov nodes
	init_markov(&RW);
	init_markov(&RL);
	init_markov(&RT);
	init_markov(&PW);
	init_markov(&PL);
	init_markov(&PT);
	init_markov(&SW);
	init_markov(&SL);
	init_markov(&ST);

	//Initialize user choice for first iteration
	user_choice_previous = "r";
	winner_previous = 1;


	//Loop over game iterations
	for (iter = 0 ; iter < max_nb_games ; iter++){
		//Next user move message
		std::cout << "What is your next move ? Rock (r), Paper (p) or Scissors (s) ? Quit (q) ";
		std::cin >> user_choice;

		//Reccord user choice for log file
		user_choice_history += user_choice;

		if(user_choice == "q"){
			break;
		}

		//Chose Move & Update markov weights
		switch (winner_previous){
			//If the previous game was a tie
			case 0 :
				if (user_choice_previous == "p"){
					machine_choice = markov_choice(&PT);
					update_markov(&PT,user_choice);
				} else if (user_choice_previous =="r"){
					machine_choice = markov_choice(&RT);
					update_markov(&RT, user_choice);
				}else if(user_choice_previous == "s"){
					machine_choice = markov_choice(&ST);
					update_markov(&ST, user_choice);
				}else{
					std::cout << "Error in markov update\n";
					machine_choice = random_ppt();
				}
				break;
			//Previous game the user won
			case 1 :
				if (user_choice_previous == "p"){
					machine_choice = markov_choice(&PW);
					update_markov(&PW,user_choice);
				} else if (user_choice_previous =="r"){
					machine_choice = markov_choice(&RW);
					update_markov(&RW, user_choice);
				}else if(user_choice_previous == "s"){
					machine_choice = markov_choice(&SW);
					update_markov(&SW, user_choice);
				}else{
					std::cout << "Error in markov update\n";
					machine_choice = random_ppt();
				}
				break;
			//Previous game the user lost
			case 2 :
				if (user_choice_previous == "p"){
					machine_choice = markov_choice(&PL);
					update_markov(&PL,user_choice);
				} else if (user_choice_previous =="r"){
					machine_choice = markov_choice(&RL);
					update_markov(&RL, user_choice);
				}else if(user_choice_previous == "s"){
					machine_choice = markov_choice(&SL);
					update_markov(&SL, user_choice);
				}else{
					std::cout << "Error in markov update\n";
					machine_choice = random_ppt();
				}
				break;
			default : 
				std::cout << "There was an error in the markov update\n";
		}

		//Next Machine move
		//machine_choice = random_ppt();

		machine_choice_history += machine_choice;
		machine_choice_msg = choice_machine_toString(machine_choice);
		std::cout << "Machine Choice = " + machine_choice_msg + "\n";

		//Calculate who wins
		winner_current = who_won(user_choice,machine_choice);
		
		//Add to statistics
		switch (winner_current){
			case 0 : 
				nb_games_tie++;
				break;
			case 1 :
				nb_games_user_won++;
			case 2 : 
				nb_games_machine_won++;
		}
		//Output the result
		output_result_current(winner_current);

		//Record data for next iteration
		user_choice_previous = user_choice;
		winner_previous = winner_current;

	}

	
	//Statistics of the games
	display_statistics(nb_games_user_won,nb_games_machine_won,nb_games_tie);
	
	//Save log files
	save_log_file (user_choice_history,machine_choice_history);

	//Exit message
	std::cout << "Thanks for playing with me. Hope to see you soon :-)\n";





}