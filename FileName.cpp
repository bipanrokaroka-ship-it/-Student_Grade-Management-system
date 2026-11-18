#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_STUDENT 100

// Student structure
typedef struct {
    int id;
    char name[20];
    int score;
    char grade;
} Student;

// Function declarations
void showMenu();
void addStudent(Student list[], int* count);
void printStudents(Student list[], int count);
char Grade(int score);
void printTotalAverage(Student list[], int count);
void searchStudent(Student list[], int count);
void updateScore(Student list[], int count);

int main() {

    Student students[MAX_STUDENT];
    int count = 0;
    int choice;

    while (1) {

        showMenu();

        printf("Select menu: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            continue;
        }

        switch (choice) {

        case 1:
            addStudent(students, &count);
            break;

        case 2:
            printStudents(students, count);
            break;

        case 3:
            printTotalAverage(students, count);
            break;

        case 4:
            searchStudent(students, count);
            break;

        case 5:
            updateScore(students, count);
            break;

        case 0:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid menu. Try again.\n");
        }
    }

    return 0;
}

// Display menu
void showMenu() {

    printf("\n===== Grade Management System =====\n");
    printf("1. Add student\n");
    printf("2. Print all students\n");
    printf("3. Print total and average\n");
    printf("4. Search student by ID\n");
    printf("5. Update score by ID\n");
    printf("0. Exit\n");
}

// Add student
void addStudent(Student list[], int* count) {

    if (*count >= MAX_STUDENT) {
        printf("Maximum student limit reached (%d).\n", MAX_STUDENT);
        return;
    }

    printf("Enter student ID: ");
    if (scanf("%d", &list[*count].id) != 1) {
        printf("Invalid ID.\n");
        return;
    }

    printf("Enter name (no spaces): ");
    if (scanf("%19s", list[*count].name) != 1) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter score (0-100): ");
    if (scanf("%d", &list[*count].score) != 1 ||
        list[*count].score < 0 ||
        list[*count].score > 100) {
        printf("Invalid score. Enter a score from 0 to 100.\n");
        return;
    }

    list[*count].grade = Grade(list[*count].score);

    (*count)++;

    printf("Student added successfully!\n");
}

// Print all students
void printStudents(Student list[], int count) {

    if (count == 0) {
        printf("No students registered.\n");
        return;
    }

    printf("\nNo   ID       Name       Score   Grade\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {

        printf("%-4d %-8d %-10s %-7d %c\n",
            i + 1,
            list[i].id,
            list[i].name,
            list[i].score,
            list[i].grade);
    }
}

// Calculate grade
char Grade(int score) {

    if (score >= 90)
        return 'A';

    else if (score >= 80)
        return 'B';

    else if (score >= 70)
        return 'C';

    else if (score >= 60)
        return 'D';

    else
        return 'F';
}

// Calculate total and average
void printTotalAverage(Student list[], int count) {

    if (count == 0) {
        printf("No students registered.\n");
        return;
    }

    int total = 0;

    for (int i = 0; i < count; i++) {
        total += list[i].score;
    }

    double avg = (double)total / count;

    printf("Total score: %d\n", total);
    printf("Average score: %.2f\n", avg);
}

// Search student by ID
void searchStudent(Student list[], int count) {

    int sid;

    printf("Enter student ID to search: ");
    if (scanf("%d", &sid) != 1) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = 0; i < count; i++) {

        if (list[i].id == sid) {

            printf("\nStudent found!\n");
            printf("ID: %d\n", list[i].id);
            printf("Name: %s\n", list[i].name);
            printf("Score: %d\n", list[i].score);
            printf("Grade: %c\n", list[i].grade);

            return;
        }
    }

    printf("Student not found.\n");
}

// Update student score
void updateScore(Student list[], int count) {

    int sid;

    printf("Enter student ID to update: ");
    if (scanf("%d", &sid) != 1) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = 0; i < count; i++) {

        if (list[i].id == sid) {

            int newScore;

            printf("Enter new score (0-100): ");

            if (scanf("%d", &newScore) != 1 ||
                newScore < 0 || newScore > 100) {
                printf("Invalid score.\n");
                return;
            }

            list[i].score = newScore;
            list[i].grade = Grade(newScore);

            printf("Score updated successfully!\n");

            return;
        }
    }

    printf("Student not found.\n");
}