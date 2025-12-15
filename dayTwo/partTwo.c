#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "../inputs/dayTwoTest.txt"

// INPUT
/// in your input, they appear on a single long line.
/// The ranges are separated by commas (,)
/// each range gives its first ID and last ID separated by a dash (-)
/// Ex: 11-22 we have a range between 11 and 22

// WHEN INVALID
/// invalid IDs by looking for any ID which is made only of some sequence of digits repeated at least twice.

/// @brief checks if a number is made only of some sequence of digits repeated twice
/// @param number 
/// @return 1 for is made only of some sequence of digits repeated twice or 0 if that is not true
int hasRepeatedSeq(char *number) {

  long long numberLen = strlen(number);
  char *halfNumber = (number + numberLen/2);
  int pairNum = 0;

  if(strncmp(number, halfNumber, numberLen/2) == 0) {
    return 1;
  } else {
    // Compare i[0] with i[i+1] until it returns false
    for(long long i = 0; i < numberLen; i++) {
      if(strncmp(number, number+(i+1), i+1) != 0) {
        // index of the comparison
        pairNum = i+1;
        break;
      }
    }

   if(pairNum != 0) {
    // i cannot let the pointer to the current pair grow bigger than the last char of number - FIX
     for (long long i = 0; i < numberLen; i++) {
      printf("Current Pair: %s - How many cases? %d\n", number+(pairNum*(i+1)), pairNum);
      strncmp(number, number+(pairNum*(i+1)), pairNum);
    }
   }
    

  }
  return 0; 
}

/// @brief Checks and sums the sequence
/// @param minRange 
/// @param maxRange 
/// @return 0
int repeatedSequences(char *minRange, char *maxRange, long long *totalSum) {

  long long min = atoll(minRange);
  long long max = atoll(maxRange);

  for(long long i = min; i <= max; i++) {
    char compareC[256];
    sprintf(compareC, "%lld", i);
    
    if(hasRepeatedSeq(compareC) == 1) {
      *totalSum += i;
    }
  }

  printf("TOTAL SUM: %lld\n", *totalSum);

  return 0;
}

int main() {
  
  // Getting file size
  FILE *input = fopen(INPUT_FILE, "rb"); //read in Binary
  if (!input) {
      printf("File Do Not Exists");
      return 1;
  }
  fseek(input, 0L, SEEK_END);
  long long lineSize = ftell(input);
  fseek(input, 0L, SEEK_SET);
  
  // Alocating Mem for the file
  char *inputLine = malloc(lineSize+1);
  fgets(inputLine, lineSize + 1, input);

  /// Getting Ranges Vars
  // Pointer that will delimeter where was the last ocurrency of strtok_r
  char *rangeDelimiter;
  char *currentRange = strtok_r(inputLine, ",", &rangeDelimiter);
  
  /// Inside ranges logic Vars
  char *InsiCurrentRange;
  char *insiRangeDelimiter;
  char rangeMin[256];
  char rangeMax[256];

  long long totalSum = 0;

  while (currentRange != NULL) {
    printf("CURRENT RANGE: %s\n", currentRange);

    InsiCurrentRange = strtok_r(currentRange, "-", &insiRangeDelimiter);
    while(InsiCurrentRange != NULL) {
      strcpy(rangeMin, InsiCurrentRange);
      InsiCurrentRange = strtok_r(NULL, "-", &insiRangeDelimiter);
      strcpy(rangeMax, InsiCurrentRange);
      InsiCurrentRange = strtok_r(NULL, "-", &insiRangeDelimiter);
      repeatedSequences(rangeMin, rangeMax, &totalSum);
    }

    currentRange = strtok_r(NULL, ",", &rangeDelimiter);
  }
  printf("MAX COMPARE: %lld\n", totalSum);

  fclose(input);
  free(inputLine);
  return 0;
}