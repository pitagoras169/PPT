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
#include <fstream> 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX_GAMES 100


//Data structure for the markov chain
struct Markov_node {
	//Number of updates to the probabilities
	int nb_times;
	//Number of times transition from current to Rock
	int nb_times_toR;
	//Number of times transition from current to Paper
	int nb_times_toP;
	//Number of times transition from current to Scissors
	int nb_times_toS;
	//Probability next move is Rock
	float proba_R;
	//Probability next move is Paper
	float proba_P;
	//Probability next move is Scissors
	float proba_S;
};

// Funtions to play Rock Paper Scissors
std::string random_ppt (void);
int who_won(std::string user_choice,std::string machine_choice);
void display_result_current (int winner_current);
std::string choice_machine_toString(std::string machine_choice);
void init_markov(struct Markov_node *node);
void update_markov(struct Markov_node *node, std::string obs_choice);
std::string markov_choice(struct Markov_node *node);
void print_markov_node(struct Markov_node *node);
void display_statistics(int nb_games_user_won,int nb_games_machine_won,int nb_games_tie);
void save_log_file(std::string user_choice_history,std::string machine_choice_history);
std::string get_user_choice(void);
void display_exit_message(void);
void add_statistics(int winner_current, int *nb_games_tie, int *nb_games_user_won, int *nb_games_machine_won);
void display_machine_choice(std::string machine_choice);
std::string get_machine_next_move(int winner_previous,std::string user_choice_previous,Markov_node *RT,Markov_node *PT,Markov_node *ST,Markov_node *RW,Markov_node *PW,Markov_node *SW,Markov_node *RL,Markov_node *PL,Markov_node *SL);
void update_all_markov(int winner_previous, std::string user_choice, std::string user_choice_previous,Markov_node *RT,Markov_node *PT,Markov_node *ST,Markov_node *RW,Markov_node *PW,Markov_node *SW,Markov_node *RL,Markov_node *PL,Markov_node *SL);
void init_all_markov(Markov_node *RW, Markov_node *RL, Markov_node *RT,Markov_node *PW, Markov_node *PL, Markov_node *PT,Markov_node *SW, Markov_node *SL, Markov_node *ST);
std::string get_second_guessing_choice(std::string user_choice_previous);
void save_log_file_batch(std::string user_choice_history,std::string machine_choice_history);

void display_statistics_batch(int nb_games_user_won,int nb_games_machine_won,int nb_games_tie);

