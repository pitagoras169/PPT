#include <iostream>
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
// Rock Paper Sscissors game
std::string random_ppt (void);
int who_won(std::string user_choice,std::string machine_choice);
void output_result_current (int winner_current);
std::string choice_machine_toString(std::string machine_choice);
void init_markov(struct Markov_node *node);
void update_markov(struct Markov_node *node, std::string obs_choice);
std::string markov_choice(struct Markov_node *node);
void print_markov_node(struct Markov_node *node);
void display_statistics(int nb_games_user_won,int nb_games_machine_won,int nb_games_tie);


