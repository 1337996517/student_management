#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
} Student;

// 函数声明
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);

#endif