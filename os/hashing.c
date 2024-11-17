#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int hash_function(int roll_no) {
    return roll_no % TABLE_SIZE;
}

void add_student(FILE *fp) {
    struct Student student;
    int index;

    printf("Enter Roll No: ");
    scanf("%d", &student.roll_no);
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter Marks: ");
    scanf("%f", &student.marks);

    index = hash_function(student.roll_no);
    fseek(fp, index * sizeof(struct Student), SEEK_SET);
    fwrite(&student, sizeof(struct Student), 1, fp);
    printf("Student record added successfully at index %d.\n", index);
}

void display_students(FILE *fp) {
    struct Student student;
    rewind(fp);
    printf("\nRoll No\tName\tMarks\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        fseek(fp, i * sizeof(struct Student), SEEK_SET);
        fread(&student, sizeof(struct Student), 1, fp);
        if (student.roll_no != 0) {  // Assuming 0 means empty slot
            printf("%d\t%s\t%.2f\n", student.roll_no, student.name, student.marks);
        }
    }
}

int main() {
    FILE *fp;
    int choice;

    fp = fopen("hash_students.dat", "wb+");
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
