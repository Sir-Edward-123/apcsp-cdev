#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 123.45;
  float e = 67.89;

  printf("The value of float d is %f\n", d);
  printf("The address of float d is %p\n", &d);
  printf("The value of float e is %f\n", e);
  printf("The address of float e is %p\n", &e);

  float* ptrd = &d;
  float* ptre = &e;
  float tmp = *ptrd;
  *ptrd = *ptre;
  *ptre = tmp;

  printf("The value of float d is %f\n", *ptrd);
  printf("The value of float e is %f\n", *ptre);
}
