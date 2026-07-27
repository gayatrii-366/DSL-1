#include <stdio.h>

typedef struct Student {
    char name[10];
    int roll;
} Student;

void accept(Student s[10], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
    }
}

void display(Student s[10], int n) {
    int i;
    printf("\n Student Details \n");
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n\n", s[i].roll);
    }
}

int main() {
    int n;
    Student s[10];
    
    printf("Enter number of students (max 10): ");
    scanf("%d", &n);
    
    
    accept(s, n);
    display(s, n);
    
    return 0;
}
