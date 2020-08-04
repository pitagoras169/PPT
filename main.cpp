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
#include "ppt.hpp"


int main(void){

	//variables declaration
	int iter;
	int winner_current;
	int max_nb_games = MAX_GAMES;
	int winner_previous = 1; //Because of psychology
	int nb_games_user_won = 0;
	int nb_games_machine_won = 0;
	int nb_games_tie = 0;
	std::string user_choice_history;
	std::string machine_choice_history;
	std::string user_choice;
	std::string machine_choice;
	std::string machine_choice_msg;
	std::string user_choice_previous = "r";

	//Creating markov nodes
	Markov_node RW, RL, RT;
	Markov_node PW, PL, PT;
	Markov_node SW, SL, ST;



	// Welcome message
	std::cout << "Welcome to Rock Paper Scissors. \n";


	//initialize the markov nodes
	init_all_markov(&RW, &RL, &RT, &PW, &PL, &PT, &SW, &SL, &ST);


	//Loop over game iterations
	for (iter = 0 ; iter < max_nb_games ; iter++){
		
		
		//Choose machine's next move
		machine_choice = get_machine_next_move(winner_previous,user_choice_previous,&RT,&PT,&ST,&RW,&PW,&SW,&RL,&PL,&SL);

		//Get user choice from terminal
		user_choice = get_user_choice();

		//Exit loop if user wants to quit
		if(user_choice == "q"){
			break;
		}

		//Add user and machine's choices to history
		user_choice_history += user_choice;
		machine_choice_history += machine_choice;

		//Display Machine's next move
		display_machine_choice(machine_choice);

		//Update markov's weights
		update_all_markov(winner_previous,user_choice, user_choice_previous,&RT,&PT,&ST,&RW,&PW,&SW,&RL,&PL,&SL);
	
		//Calculate who wins
		winner_current = who_won(user_choice,machine_choice);
		display_result_current(winner_current);

		//Add to statistics
		add_statistics(winner_current, &nb_games_tie, &nb_games_user_won, &nb_games_machine_won);

		//Record data for next iteration
		user_choice_previous = user_choice;
		winner_previous = winner_current;

	}

	
	//Save log files
	save_log_file (user_choice_history,machine_choice_history);
	//Statistics of the games and exit message
	display_statistics(nb_games_user_won,nb_games_machine_won,nb_games_tie);
	//Display exit message
	display_exit_message();

}