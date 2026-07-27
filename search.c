#include <stdio.h>
#include <string.h>

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

// Linear search 
int linearSearch(Student s[10], int n, int searchRoll) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == searchRoll) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n, searchRoll, resultIndex;
    Student s[10];
    
    printf("Enter number of students (max 10): ");
    scanf("%d", &n);
    
    accept(s, n);
    display(s, n);
 
    printf("Enter the roll number to search for: ");
    scanf("%d", &searchRoll);
    
    resultIndex = linearSearch(s, n, searchRoll);
    
    if (resultIndex != -1) {
        printf("\nStudent Found!\n");
        printf("Name: %s\n", s[resultIndex].name);
        printf("Roll Number: %d\n", s[resultIndex].roll);
    } else {
        printf("\nStudent with roll number %d not found.\n", searchRoll);
    }
    
    return 0;
}

