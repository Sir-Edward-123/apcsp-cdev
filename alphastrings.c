#include <stdio.h>
#include <string.h>

char loopAlphabet[27];
char constInitAlphabet[] = "abcdefghijklmnopqrstuvwxyz";

void testStrings()
{
  if(strcmp(loopAlphabet, constInitAlphabet) == 0)
    printf("The strings are identical\n");
  else
    printf("The strings are different\n");
}

int main()
{
  char incrementChar = 97;
  for(int i = 0; i < 26; i++)
  {
    loopAlphabet[i] = incrementChar;
    incrementChar++;
  }

  testStrings();

  for(int i = 0; i < 26; i++)
  {
    loopAlphabet[i] -= 32;
  }

  testStrings();

  char combinedString[52];
  strcat(combinedString, loopAlphabet);
  strcat(combinedString, constInitAlphabet);
  printf("String created using a loop: %s\n", loopAlphabet);
  printf("String created using a string constant initalizer: %s\n", constInitAlphabet);
  printf("String created by concatenating the other two strings: %s\n", combinedString);
}
