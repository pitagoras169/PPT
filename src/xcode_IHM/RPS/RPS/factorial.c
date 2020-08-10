//
//  factorial.c
//  RPS
//
//  Created by guillermo pita on 10/08/2020.
//  Copyright © 2020 guillermo pita. All rights reserved.
//

#include "factorial.h"

long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

