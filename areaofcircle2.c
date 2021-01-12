#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], int* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%d", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float radius)
{
  return M_PI * radius * radius;
}

void askForUserInput(int* startPtr, int* endPtr)
{
  char input[256];
  printf("Please enter a positive integer to act as a starting point ");
  while(1)
  {
    fgets(input, 256, stdin);
    if(sscanf(input, "%d", startPtr) == 1 && *startPtr > 0) break;
    printf("Not a valid input, please enter a positive integer ");
  }
  printf("Starting point: %d\n", *startPtr);

  printf("Please enter a positive integer greater than the starting point to act as an ending point ");
  while(1)
  {
    fgets(input, 256, stdin);
    if(sscanf(input, "%d", endPtr) == 1 && *endPtr > *startPtr) break;
    printf("Not a valid input, please enter a positive integer ");
  }
  printf("Ending Point: %d\n", *endPtr);
}

int main(int argc, char* argv[]) 
{

  // the two variables which control the number of times areaOfCircle is called
  int start;
  int end;

  if(argc == 3)
  {
      if(sscanf(argv[1], "%d", &start) == 0 || sscanf(argv[2], "%d", &end) == 0 || start <= 0 || start >= end)
        askForUserInput(&start, &end);
  }
  else
  {
    askForUserInput(&start, &end);
  }

  // for testing only - do not change
  // getTestInput(argc, argv, &start, &end);

  printf("calculating area of circle starting at %d, and ending at %d\n", start, end);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
  for(int i = start; i <= end; i++){
    printf("The area of a circle with a radius of %d is %f\n", i, areaOfCircle(i));
  }
  
}
