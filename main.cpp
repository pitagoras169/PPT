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
	int max_nb_games = 100;


	// Mensaje de bienvenida
	std::cout << "Wellcome to Rock Paper Scissors. \n";

	for (iter = 0 ; iter < max_nb_games ; iter++){
		//Next user move message
		std::cout << "What is your next move ? Rock (r), Paper (p) or Scissors (s) ? Quit (q) ";
		std::cin >> user_choice;

		if(user_choice == "q"){
			break;
		}

		//Next Machine move
		machine_choice = random_ppt();
		machine_choice_msg = choice_machine_toString(machine_choice);
		std::cout << "Machine Choice = " + machine_choice_msg + "\n";

		//Calculate who wins
		winner_current = who_won(user_choice,machine_choice);

		//Output the result
		output_result_current(winner_current);
	}

	


	//Exit message
	std::cout << "Thanks for playing with me. Hope to see you soon :-)\n";





}