#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for student
struct Student {
    char name[100];
    int id;
    float mark;
};

// Function to add student
void addStudent(struct Student students[], int *count) {

    printf("\nEnter Student Name: ");
    getchar(); // clear newline
    fgets(students[*count].name, sizeof(students[*count].name), stdin);

    // remove newline from fgets
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Student Mark: ");
    scanf("%f", &students[*count].mark);

    (*count)++;

    printf("\nStudent Added Successfully!\n");
}

// Function to display one student
void displayStudent(struct Student s) {

    printf("\n====================");
    printf("\nName : %s", s.name);
    printf("\nID   : %d", s.id);
    printf("\nMark : %.2f", s.mark);

    if(s.mark >= 90)
        printf("\nGrade: A");

    else if(s.mark >= 75)
        printf("\nGrade: B");

    else if(s.mark >= 50)
        printf("\nGrade: C");

    else
        printf("\nGrade: F");

    printf("\n====================\n");
}

// Display all students
void displayAll(struct Student students[], int count) {

    if(count == 0) {
        printf("\nNo students found.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        displayStudent(students[i]);
    }
}

// Search by ID
void searchStudent(struct Student students[], int count) {

    int searchId;
    int found = 0;

    printf("\nEnter ID to search: ");
    scanf("%d", &searchId);

    for(int i = 0; i < count; i++) {

        if(students[i].id == searchId) {

            displayStudent(students[i]);

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nStudent not found.\n");
    }
}

int main() {

    struct Student students[MAX];

    int count = 0;
    int choice;

    while(1) {

        printf("\n========= STUDENT MANAGEMENT SYSTEM =========\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            addStudent(students, &count);

        }

        else if(choice == 2) {

            displayAll(students, count);

        }

        else if(choice == 3) {

            searchStudent(students, count);

        }

        else if(choice == 4) {

            printf("\nProgram terminated.\n");
            break;

        }

        else {

            printf("\nInvalid choice.\n");

        }

    }

    return 0;
}