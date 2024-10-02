#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SCHEDULES 5

typedef struct {
    char day[20];
    char time[20];
    char course[50];
    char instructor[50];
}
Schedule;

typedef struct {
    char name[50];
    char email[20];
    int mobile;
    char id[10];
    Schedule schedules[MAX_SCHEDULES];
    int scheduleCount;
}
Student;
void addStudent(Student* students, int* count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student newStudent;

    printf("Enter student name: ");
    scanf("%s", newStudent.name);

    printf("Enter student email: ");
    scanf("%s", newStudent.email);

    printf("Enter student mobile: ");
    scanf("%d", &newStudent.mobile);

    printf("Enter student id: ");
    scanf("%s", newStudent.id);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully.\n");
}

void displayStudents(Student* students, int count)
{
    if (count == 0)
    {
        printf("No students in the classroom.\n");
        return;
    }

    printf("\n");
    printf("|==============================|\n");
    printf("|    CLASSROOM STUDENTS        |\n");
    printf("|==============================|\n");
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s \nEmail: %s \nMobile: %d \nId: %s\n", students[i].name, students[i].email, students[i].mobile, students[i].id);
        printf("==============================\n");
    }
    printf("\n");
}

void addSchedule(Student* students, int count)
{
    if (count == 0)
    {
        printf("No students in the classroom.\n");
        return;
    }

    int studentIndex;
    printf("Enter the index of the student: ");
    scanf("%d", &studentIndex);

    if (studentIndex < 0 || studentIndex >= count)
    {
        printf("Invalid student index.\n");
        return;
    }

    Student* student = &students[studentIndex];

    if (student->scheduleCount >= MAX_SCHEDULES)
    {
        printf("Maximum number of schedules reached for this student.\n");
        return;
    }

    Schedule newSchedule;
    printf("Enter class day: ");
    scanf("%s", newSchedule.day);

    printf("Enter class time: ");
    scanf("%s", newSchedule.time);

    printf("Enter course name: ");
    scanf("%s", newSchedule.course);

    printf("Enter instructor name: ");
    scanf("%s", newSchedule.instructor);

    student->schedules[student->scheduleCount] = newSchedule;
    student->scheduleCount++;

    printf("Schedule added successfully.\n");
}

void displaySchedules(Student* students, int count)
{
    if (count == 0)
    {
        printf("No students in the classroom.\n");
        return;
    }

    int studentIndex;
    printf("Enter the index of the student: ");
    scanf("%d", &studentIndex);

    if (studentIndex < 0 || studentIndex >= count)
    {
        printf("Invalid student index.\n");
        return;
    }

    Student* student = &students[studentIndex];

    if (student->scheduleCount == 0)
    {
        printf("No schedules found for this student.\n");
        return;
    }

    printf("\n");
    printf("|==============================|\n");
    printf("|     CLASS SCHEDULE           |\n");
    printf("|==============================|\n");
    printf("\n");

    printf("Schedules for student %s:\n", student->name);
    for (int i = 0; i < student->scheduleCount; i++)
    {
        printf("Day: %s\n", student->schedules[i].day);
        printf("Time: %s\n", student->schedules[i].time);
        printf("Course: %s\n", student->schedules[i].course);
        printf("Instructor: %s\n", student->schedules[i].instructor);
        printf("==============================\n");
    }

    printf("\n");
}

void deleteStudent(Student* students, int* count)
{
    if (*count == 0)
    {
        printf("No students in the classroom.\n");
        return;
    }

    char idToDelete[10];
    printf("Enter the ID of the student to delete: ");
    scanf("%s", idToDelete);

    int foundIndex = -1;

    for (int i = 0; i < *count; i++)
    {
        if (strcmp(students[i].id, idToDelete) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        for (int i = foundIndex; i < (*count) - 1; i++)
        {
            students[i] = students[i + 1];
        }
        (*count)--;
        printf("Student with ID %s deleted successfully.\n", idToDelete);
    }
    else
    {
        printf("Student with ID %s not found.\n", idToDelete);
    }
}

int main()
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int score = 0;

    printf("...........INTERNATIONAL ISLAMIC UNIVERSITY CHATTOGRAM............\n\n");
    printf("\n\t____Faculty of Science And Engineering____\n\n");
    printf("\n\t\t____Department of CSE____\n\n");
    printf("\n\tHOME PAGE");
    printf("\n=========================\n\n");

    do
    {
        printf("   [1] Add Student.\n");
        printf("   [2] Display Students.\n");
        printf("   [3] Add Schedule.\n");
        printf("   [4] Display Schedule.\n");
        printf("   [5] Delete Student.\n");
        printf("   [6] Quiz.\n");
        printf("   [7] Exit.\n");
        printf("=========================\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                addSchedule(students, count);
                break;
            case 4:
                displaySchedules(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
        }
    }
    while (choice != 6);
    printf("\n");
    printf("Welcome to the Quiz!\n");
    printf("\nQ1: Which of the following is not a valid C variable name?\n");
    printf("a) int number;\n");
    printf("b) float rate;\n");
    printf("c) int $main;\n");
    printf("Your answer: ");
    char answer1;
    scanf(" %c", &answer1);
    if (answer1 == 'c' || answer1 == 'C')
    {
         printf("Correct answer!\n");
         score++;
    }
    else
    {
         printf("Wrong answer!\n");
    }
    printf("\nQ2: Which is valid C expression?\n");
    printf("a) int my_num = 100000;\n");
    printf("b) int my_num = 100,000;\n");
    printf("c) int my num = 1000;\n");
    printf("Your answer: ");
    char answer2;
    scanf(" %c", &answer2);
    if (answer2 == 'a' || answer2 == 'A')
    {
         printf("Correct answer!\n");
         score++;
    }
    else
    {
         printf("Wrong answer!\n");
    }
    printf("\nQ3: What is #include<stdio.h>?\n");
    printf("a) inclusion directive\n");
    printf("b) preprocessor directive\n");
    printf("c) none of them\n");
    printf("Your answer: ");
    char answer3;
    scanf(" %c", &answer3);
    if (answer3 == 'b' || answer3 == 'B')
    {
         printf("Correct answer!\n");
         score++;
    }
    else
    {
          printf("Wrong answer!\n");
    }
    printf("\nQuiz complete!\n");
    printf("Your score: %d out of 3\n", score);
    return 0;
}