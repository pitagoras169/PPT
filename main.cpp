#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>




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

int main(void){

	int nb_partidas = 0;
	std::string user_choice;


	// Mensaje de bienvenida
	std::cout << "Wellcome to Rock Paper Scissors. \n";

	std::cout << "What is your next move ? Rock (r), Paper (p) or Scissors (s) ? ";
	std::cin >> user_choice;
	std::cout << "\n";
	std::cout << "User choice = " + user_choice + "\n";
	std::cout << random_ppt();

}