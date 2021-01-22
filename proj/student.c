//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* newStudent = (Student*)malloc(sizeof(Student));
  newStudent->firstName = (char*)malloc(strlen(fname) * sizeof(char));
  newStudent->lastName = (char*)malloc(strlen(lname) * sizeof(char));
  strcpy(newStudent->firstName, fname);
  strcpy(newStudent->lastName, lname);
  newStudent->age = age;
  newStudent->id = id;

  students[numStudents] = newStudent;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for(int i = 0; i < numStudents; i++)
  {
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  FILE* studentDataF;
  studentDataF = fopen(STUFILE, "w");

  if(studentDataF)
  {
    char fullStr[600];
    for(int i = 0; i < numStudents; i++)
    {
      sprintf(fullStr, "%s %s %d %ld",
       students[i]->firstName,
       students[i]->lastName,
       students[i]->age,
       students[i]->id);
       caesarEncrypt(fullStr, key);
      fprintf(studentDataF, "%s\n", fullStr);
      printf("saving: %s\n", fullStr);
    }
    fclose(studentDataF);
  }
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  deleteStudents();
  FILE* studentDataF;
  studentDataF = fopen(STUFILE, "r");

  while(1)
  {
    char fullStr[600];
    char firstName[256];
    char lastName[256];
    char ageBeforeDecrypt[32];
    char idBeforeDecrypt[32];
    int age;
    long int id;

    if(fscanf(studentDataF, "%s %s %s %s\n", firstName, lastName, ageBeforeDecrypt, idBeforeDecrypt) == 4)
    {
      sprintf(fullStr, "%s %s %s %s", firstName, lastName, ageBeforeDecrypt, idBeforeDecrypt);
      caesarDecrypt(fullStr, key);
      if(sscanf(fullStr, "%s %s %d %ld", firstName, lastName, &age, &id) != 4)
        printf("There was a problem formatting a student, and numerical values may not match what is on file. Check encryption/decryption key.\n");
      createStudent(firstName, lastName, age, id);
    }
    else
    {
      break;
    }
  }
  fclose(studentDataF);
  printf("loaded %d students\n", numStudents);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




