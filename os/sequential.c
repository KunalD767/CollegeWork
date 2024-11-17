#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void add_student(FILE *fp) {
    struct Student student;
    printf("Enter Roll No: ");
    scanf("%d", &student.roll_no);
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter Marks: ");
    scanf("%f", &student.marks);

    fwrite(&student, sizeof(struct Student), 1, fp);
    printf("Student record added successfully.\n");
}

void display_students(FILE *fp) {
    struct Student student;
    rewind(fp);  // Move file pointer to the start
    printf("\nRoll No\tName\tMarks\n");
    while (fread(&student, sizeof(struct Student), 1, fp)) {
        printf("%d\t%s\t%.2f\n", student.roll_no, student.name, student.marks);
    }
}

int main() {
    FILE *fp;
    int choice;
    
    fp = fopen("students.dat", "wb+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student(fp);
                break;
            case 2:
                display_students(fp);
                break;
            case 3:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
