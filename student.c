#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("学生数量已达上限！\n");
        return;
    }
    
    Student newStudent;
    printf("请输入学生ID: ");
    scanf("%d", &newStudent.id);
    
    // 检查ID是否已存在
    for (int i = 0; i < *count; i++) {
        if (students[i].id == newStudent.id) {
            printf("该ID已存在！\n");
            return;
        }
    }
    
    printf("请输入学生姓名: ");
    scanf("%s", newStudent.name);
    printf("请输入学生成绩: ");
    scanf("%f", &newStudent.score);
    
    students[*count] = newStudent;
    (*count)++;
    printf("学生添加成功！\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("没有学生记录！\n");
        return;
    }
    
    printf("\n%-10s %-20s %-10s\n", "ID", "姓名", "成绩");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", 
               students[i].id, students[i].name, students[i].score);
    }
}

void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("没有学生记录！\n");
        return;
    }
    
    int id;
    printf("请输入要查找的学生ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\n找到学生信息:\n");
            printf("ID: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("成绩: %.2f\n", students[i].score);
            return;
        }
    }
    
    printf("未找到ID为%d的学生！\n", id);
}

void updateStudent(Student students[], int count) {
    if (count == 0) {
        printf("没有学生记录！\n");
        return;
    }
    
    int id;
    printf("请输入要修改的学生ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("当前信息: ID=%d, 姓名=%s, 成绩=%.2f\n", 
                   students[i].id, students[i].name, students[i].score);
            
            printf("请输入新的姓名: ");
            scanf("%s", students[i].name);
            printf("请输入新的成绩: ");
            scanf("%f", &students[i].score);
            
            printf("学生信息更新成功！\n");
            return;
        }
    }
    
    printf("未找到ID为%d的学生！\n", id);
}

void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("没有学生记录！\n");
        return;
    }
    
    int id;
    printf("请输入要删除的学生ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            // 将后面的元素前移
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("学生删除成功！\n");
            return;
        }
    }
    
    printf("未找到ID为%d的学生！\n", id);
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("数据保存成功！\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("文件打开失败或不存在！\n");
        return;
    }
    
    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(Student), *count, file);
    fclose(file);
    printf("数据加载成功！\n");
}