#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure definition
struct Student {
    int id;
    char name[50];
    float marks;
};

// Function to store records in file (ASCII)
void writeToFile(struct Student s[], int n, FILE *fp) {
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %f\n", s[i].id, s[i].name, s[i].marks);
    }
}

// Function to store positions of each record
int createIndex(FILE *fp, long pos[]) {
    int count = 0;
    rewind(fp);

    while (!feof(fp)) {
        pos[count] = ftell(fp);   // store position
        int id;
        char name[50];
        float marks;

        if (fscanf(fp, "%d %s %f\n", &id, name, &marks) == 3) {
            count++;
        }
    }
    return count;
}

// Function to display record using position
void displayRecord(FILE *fp, long pos[], int index) {
    struct Student s;

    fseek(fp, pos[index], SEEK_SET); // go to position

    fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks);

    printf("\nRecord at position %d:\n", index);
    printf("ID: %d\nName: %s\nMarks: %.2f\n", s.id, s.name, s.marks);
}

int main() {
    struct Student s[MAX];
    int n;
    long pos[MAX];

    FILE *fp = fopen("students.txt", "w+");

    if (fp == NULL) {
        printf("File error!\n");
        return 1;
    }

    // Input
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter ID, Name, Marks: ");
        scanf("%d %s %f", &s[i].id, s[i].name, &s[i].marks);
    }

    // Write to file
    writeToFile(s, n, fp);

    // Create index (positions)
    int count = createIndex(fp, pos);

    printf("\nTotal records indexed: %d\n", count);

    // Display record using position
    int index;
    printf("Enter record index to display (0 to %d): ", count - 1);
    scanf("%d", &index);

    if (index >= 0 && index < count) {
        displayRecord(fp, pos, index);
    } else {
        printf("Invalid index!\n");
