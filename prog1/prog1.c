#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
};

void addRecords() {
    FILE *fp;
    struct Student s;
    int n, i;

    fp = fopen("student.dat", "wb");

    printf("Enter number of records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter ID: ");
        scanf("%d", &s.id);

        printf("Enter Name: ");
        scanf("%s", s.name);

        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);
}

void displayMthRecord() {
    FILE *fp;
    struct Student s;
    int m;

    fp = fopen("student.dat", "rb");

    printf("Enter record number: ");
    scanf("%d", &m);

    fseek(fp, (m-1) * sizeof(s), SEEK_SET);

    fread(&s, sizeof(s), 1, fp);

    printf("\nRecord Found:\n");
    printf("ID = %d\n", s.id);
    printf("Name = %s\n", s.name);

    fclose(fp);
}

void deleteRecord() {
    FILE *fp, *temp;
    struct Student s;
    int id;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    printf("Record deleted successfully.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Add Records\n");
        printf("2. Display Mth Record\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecords();
                break;

            case 2:
                displayMthRecord();
                break;

            case 3:
                deleteRecord();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
