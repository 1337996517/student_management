#include <stdio.h>
#include "student.h"

void displayMenu() {
    printf("\n===== 学生成绩管理系统 =====\n");
    printf("1. 添加学生\n");
    printf("2. 显示所有学生\n");
    printf("3. 查找学生\n");
    printf("4. 修改学生信息\n");
    printf("5. 删除学生\n");
    printf("6. 保存数据到文件\n");
    printf("7. 从文件加载数据\n");
    printf("0. 退出\n");
    printf("请选择操作: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    
    printf("欢迎使用学生成绩管理系统！\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 6:
                saveToFile(students, count);
                break;
            case 7:
                loadFromFile(students, &count);
                break;
            case 0:
                printf("感谢使用！再见！\n");
                break;
            default:
                printf("无效的选择，请重新输入！\n");
        }
    } while (choice != 0);
    
    return 0;
}