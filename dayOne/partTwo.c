#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN 0
#define MAX 99
#define INITIAL_POSITION 50

// Wrong Answers = 6829 6847 (NEAR)

///      _____
///     _|___|_
///      (°~°)    
///   --(  :  )--
///    (   :   )
/// __(    :    )_

/// DOC: "Due to newer security protocols, please use password method 0x434C49434B until further notice."
/// you're actually supposed to count the number of times any click causes the dial to point at 0, regardless of whether it happens during a rotation or at the end of one.

/// REGEX FOR CORRECTION: \b[LR][1-9]\d{2,}\b.*

int main() {

    int dialing = INITIAL_POSITION;

    FILE *input = fopen("../inputs/dayOne.txt", "r");
    if (!input) {
        printf("File Do Not Exists");
        return 1;
    }

    char currentStr[256];
    int steps;
    int zeros = 0;
    int lastZeros = 0;
    int lastDial = 0;

    while (fgets(currentStr, sizeof(currentStr), input)) {
        steps = atoi(&currentStr[1]);
        lastZeros = zeros;
        lastDial = dialing;

        printf("CURRENT POSIT: %d\n", dialing);
        zeros += steps / 100;
        if(strncmp(currentStr, "R", 1) == 0) { // Right
            printf("R%d -> ", steps);
            if((dialing + steps) > 99) {
                dialing = (dialing + steps) % 100;
            } else dialing += steps;
            printf("%d\n", dialing);
        } else  { // Left
            printf("L%d -> ", steps);
            dialing = dialing - (steps % 100);
            if (dialing < 0) {
                dialing += 100;
            }
            printf("%d\n", dialing);
        }
        if(dialing == 0) zeros++; 
        if(zeros != lastZeros)printf("Zeros %d\n", zeros);
        
    }
    
    printf("Recorrência de Zeros: %d\n", zeros);

    fclose(input);
    return 0;

}