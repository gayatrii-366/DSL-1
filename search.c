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
    printf("\n--- Student Details ---\n");
    for (i = 0; i < n; i++) {
        printf("Student %d | Name: %s | Roll Number: %d\n", i + 1, s[i].name, s[i].roll);
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

// Bubble sort
void sortByRollNumber(Student s[10], int n) {
    int i, j;
    Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(Student s[10], int n) {
    int i, j, minIndex;
    Student temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (s[j].roll < s[minIndex].roll) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = s[i];
            s[i] = s[minIndex];
            s[minIndex] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(Student s[10], int n) {
    int i, j;
    Student key;
    for (i = 1; i < n; i++) {
        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j].roll > key.roll) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

// Binary search
int binarySearch(Student s[10], int n, int searchRoll) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (s[mid].roll == searchRoll) {
            return mid;
        }
        if (s[mid].roll < searchRoll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = 0, searchRoll, resultIndex, choice;
    Student s[10];

    do {
        printf("1. Accept Student Data\n");
        printf("2. Display All Students\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search (Auto-Bubble Sort)\n");
        printf("5. Selection Sort (By Roll Number)\n");
        printf("6. Insertion Sort (By Roll Number)\n");
        printf("7. Exit\n");
        printf("Enter your choice from 1 to 7: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students (max 10): ");
                scanf("%d", &n);
                if (n > 0 && n <= 10) {
                    accept(s, n);
                } else {
                    printf("Invalid number of students. Please try again.\n");
                    n = 0;
                }
                break;
            case 2:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    display(s, n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                    break;
                }
                printf("Enter the roll number to search for: ");
                scanf("%d", &searchRoll);
                resultIndex = linearSearch(s, n, searchRoll);
                if (resultIndex != -1) {
                    printf("\n[Linear Search] Student Found at index %d!\n", resultIndex);
                    printf("Name: %s | Roll Number: %d\n", s[resultIndex].name, s[resultIndex].roll);
                } else {
                    printf("\nStudent with roll number %d not found.\n", searchRoll);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                    break;
                }
                printf("\nSorting student records by roll number using Bubble Sort for binary search...\n");
                sortByRollNumber(s, n);
                display(s, n);
                printf("Enter the roll number to search for: ");
                scanf("%d", &searchRoll);
                resultIndex = binarySearch(s, n, searchRoll);
                if (resultIndex != -1) {
                    printf("\n[Binary Search] Student Found at index %d!\n", resultIndex);
                    printf("Name: %s | Roll Number: %d\n", s[resultIndex].name, s[resultIndex].roll);
                } else {
                    printf("\nStudent with roll number %d not found.\n", searchRoll);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printf("\nSorting student records using Selection Sort...\n");
                    selectionSort(s, n);
                    display(s, n);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printf("\nSorting student records using Insertion Sort...\n");
                    insertionSort(s, n);
                    display(s, n);
                }
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}
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
    printf("\n--- Student Details ---\n");
    for (i = 0; i < n; i++) {
        printf("Student %d | Name: %s | Roll Number: %d\n", i + 1, s[i].name, s[i].roll);
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

// Bubble sort
void sortByRollNumber(Student s[10], int n) {
    int i, j;
    Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(Student s[10], int n) {
    int i, j, minIndex;
    Student temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (s[j].roll < s[minIndex].roll) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = s[i];
            s[i] = s[minIndex];
            s[minIndex] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(Student s[10], int n) {
    int i, j;
    Student key;
    for (i = 1; i < n; i++) {
        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j].roll > key.roll) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

// Binary search
int binarySearch(Student s[10], int n, int searchRoll) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (s[mid].roll == searchRoll) {
            return mid;
        }
        if (s[mid].roll < searchRoll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = 0, searchRoll, resultIndex, choice;
    Student s[10];

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Accept Student Data\n");
        printf("2. Display All Students\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search (Auto-Bubble Sort)\n");
        printf("5. Selection Sort (By Roll Number)\n");
        printf("6. Insertion Sort (By Roll Number)\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students (max 10): ");
                scanf("%d", &n);
                if (n > 0 && n <= 10) {
                    accept(s, n);
                } else {
                    printf("Invalid number of students. Please try again.\n");
                    n = 0;
                }
                break;
            case 2:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    display(s, n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                    break;
                }
                printf("Enter the roll number to search for: ");
                scanf("%d", &searchRoll);
                resultIndex = linearSearch(s, n, searchRoll);
                if (resultIndex != -1) {
                    printf("\n[Linear Search] Student Found at index %d!\n", resultIndex);
                    printf("Name: %s | Roll Number: %d\n", s[resultIndex].name, s[resultIndex].roll);
                } else {
                    printf("\nStudent with roll number %d not found.\n", searchRoll);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                    break;
                }
                printf("\nSorting student records by roll number using Bubble Sort for binary search...\n");
                sortByRollNumber(s, n);
                display(s, n);
                printf("Enter the roll number to search for: ");
                scanf("%d", &searchRoll);
                resultIndex = binarySearch(s, n, searchRoll);
                if (resultIndex != -1) {
                    printf("\n[Binary Search] Student Found at index %d!\n", resultIndex);
                    printf("Name: %s | Roll Number: %d\n", s[resultIndex].name, s[resultIndex].roll);
                } else {
                    printf("\nStudent with roll number %d not found.\n", searchRoll);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printf("\nSorting student records using Selection Sort...\n");
                    selectionSort(s, n);
                    display(s, n);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("\nNo student records available. Please accept data first.\n");
                } else {
                    printf("\nSorting student records using Insertion Sort...\n");
                    insertionSort(s, n);
                    display(s, n);
                }
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}

