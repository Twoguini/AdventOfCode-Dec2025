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
/// invalid IDs by looking for any ID which is made only of some sequence of digits repeated twice.

/// @brief checks if a number is made only of some sequence of digits repeated twice
/// @param number 
/// @return 1 for is made only of some sequence of digits repeated twice or 0 if that is not true
int hasRepeatedSeq(char *number) {

}

/// @brief Returns the number of numbers that repeat the sequence of digits in the range
/// @param minRange 
/// @param maxRange 
/// @return Number of numbers that repeat the sequence of digits in the range
int repeatedSequences(char *minRange, char *maxRange) {

}

int main() {
  
  // Getting file size
  FILE *input = fopen(INPUT_FILE, "rb"); //read in Binary
  if (!input) {
      printf("File Do Not Exists");
      return 1;
  }
  fseek(input, 0L, SEEK_END);
  long lineSize = ftell(input);
  fseek(input, 0L, SEEK_SET);
  
  // Alocating Mem fro the file
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

  while (currentRange != NULL) {
    printf("CURRENT RANGE: %s\n", currentRange);

    InsiCurrentRange = strtok_r(currentRange, "-", &insiRangeDelimiter);
    while(InsiCurrentRange != NULL) {
      strcpy(rangeMin, InsiCurrentRange);
      printf("MIN: %s - ", rangeMin);
      InsiCurrentRange = strtok_r(NULL, "-", &insiRangeDelimiter);
      strcpy(rangeMax, InsiCurrentRange);
      printf("MAX: %s\n", rangeMax);
      InsiCurrentRange = strtok_r(NULL, "-", &insiRangeDelimiter);
    }

    currentRange = strtok_r(NULL, ",", &rangeDelimiter);
  }

  fclose(input);
  free(inputLine);
  return 0;
}