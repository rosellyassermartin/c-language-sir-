#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

// Structure to represent a student
struct Student {
    char name[MAX_NAME_LENGTH];
    int attendance;
};

// Function to add a new student
void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents < MAX_STUDENTS) {
        printf("Enter the name of the student: ");
        scanf("%s", students[*numStudents].name);
        students[*numStudents].attendance = 0; // Initialize attendance to 0
        (*numStudents)++;
        printf("******Student added successfully******.\n");
    } else {
        printf("Cannot add more students. Maximum limit reached.\n");
    }
}

// Function to mark attendance for a student
void markAttendance(struct Student students[], int numStudents) {
    char studentName[MAX_NAME_LENGTH];
    printf("Enter the name of the student: ");
    scanf("%s", studentName);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, studentName) == 0) {
            students[i].attendance++;
            found = 1;
            printf("******Attendance marked for %s******.\n", studentName);
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to display attendance for a student
void displayAttendance(struct Student students[], int numStudents) {
    char studentName[MAX_NAME_LENGTH];
    printf("Enter the name of the student: ");
    scanf("%s", studentName);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, studentName) == 0) {
            printf("Attendance for %s: %d\n", studentName, students[i].attendance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        printf("\n *******Attendance System Menu********:\n");
        printf("      *1. Add Student:\n");
        printf("     **2. Mark Attendance:\n");
        printf("    ***3. Display Attendance:\n");
        printf("   ****4. Exit:\n");
        printf("*****Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                markAttendance(students, numStudents);
                break;
            case 3:
                displayAttendance(students, numStudents);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}