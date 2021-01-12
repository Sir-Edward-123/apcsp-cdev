#include <stdio.h>



// student structure
//struct Student...
struct Student{
  char firstName[64];
  char lastName [64];
  int age;
  int studentId;
};

void printStudent(struct Student* student)
{
  printf("Student: %s %s\n", student->firstName, student->lastName);
  printf("Age: %d\n", student->age);
  printf("ID: %d\n\n", student->studentId);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; i++)
  {
    printf("Student %d ----------\n", i);
    printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[64];
  int numStudents = 0;

  char input[256];
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      struct Student newStudent;
      printf("First Name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &newStudent.firstName);
      printf("Last Name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &newStudent.lastName);
      printf("Enter Age: ");
      while(1)
      {
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &newStudent.age) == 1 && newStudent.age >= 0) break;
        printf("Enter Age: ");
      }
      printf("Enter ID: ");
      while(1)
      {
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &newStudent.studentId) == 1 && newStudent.studentId >= 0) break;
        printf("Enter ID: ");
      }
      students[numStudents] = newStudent;
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
