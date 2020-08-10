//
//  RPS_calc.c
//  RPS
//
//  Created by guillermo pita on 10/08/2020.
//  Copyright © 2020 guillermo pita. All rights reserved.
//

#include "RPS_calc.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char random_ppt (void){
    //Function to determine a random choice of Rock Paper Scissors
    int random_choice;
    char random_choice_char;
    srand (time(NULL));
    random_choice = rand()%3 +1;
    switch (random_choice){
        case 1 :
            //In the case of Rock
            random_choice_char = 'r';
            break;
        case 2 :
            //In the case of Paper
            random_choice_char = 'p';
            break;
        case 3 :
            //In the case of Scissors
            random_choice_char = 's';
            break;
        default :
            //In case the is a error outputs E to track it
            random_choice_char = 'e';
    }
    return random_choice_char;
}
