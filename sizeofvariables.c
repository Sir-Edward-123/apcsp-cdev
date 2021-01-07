#include<stdio.h>

int main()
{
  int a = 123;
  long int b = 123;
  unsigned int c = 123;
  char d = 'd';
  double e = 123.456;
  float f = 123.45;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("long int b value: %ld and size: %lu bytes\n", b, sizeof(b));
  printf("unsigned int c value: %u and size: %lu bytes\n", c, sizeof(c));
  printf("char d value: %c and size: %lu bytes\n", d, sizeof(d));
  printf("double e value: %lf and size: %lu bytes\n", e, sizeof(e));
  printf("float f value: %f and size: %lu bytes\n", f, sizeof(f));
}

