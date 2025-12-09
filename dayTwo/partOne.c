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
  int  rangeMin;
  int  rangeMax;

  while (currentRange != NULL) {
    printf("CURRENT RANGE: %s\n", currentRange);

    InsiCurrentRange = strtok_r(currentRange, "-", &insiRangeDelimiter);
    while(insiRangeDelimiter != NULL) {
      rangeMin = atoi(insiRangeDelimiter);
      printf("MIN: %d - ", rangeMin);
      insiRangeDelimiter = strtok_r(NULL, "-", &insiRangeDelimiter);
      rangeMax = atoi(insiRangeDelimiter);
      printf("MAX: %d\n", rangeMax);
    }

    currentRange = strtok_r(NULL, ",", &rangeDelimiter);
  }
  

  fclose(input);
  free(inputLine);
  return 0;
}