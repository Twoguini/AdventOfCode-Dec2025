#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN 0
#define MAX 99
#define INITIAL_POSITION 50

// LEFT  L -> Lower  Numbers - (Subtract) 
// RIGHT R -> Righer Numbers + (ADD) 

// LEFT  from 0  goes to Finish, Ex.: From 0  L1 -> 99
// RIGHT from 99 starts over   , Ex.: From 99 R1 -> 0

int main() {
    int dialing = INITIAL_POSITION;

    FILE *input = fopen("../inputs/dayOne.txt", "r");
    if (!input) {
        printf("File Do Not Exists");
        return 1;
    }

    char currentStr[256];
    int steps;

    while (fgets(currentStr, sizeof(currentStr), input)) {
        steps = atoi(&currentStr[1]);
        
        if(strncmp(currentStr, "R", 1)) { // Right
            printf("R - %d\n", steps);
        } else  { // Left
            printf("L - %d\n", steps);
        }
    }
    
    fclose(input);
    return 0;
}