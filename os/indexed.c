#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void add_student(FILE *data_fp, FILE *index_fp) {
    struct Student student;
    int position;

    printf("Enter Roll No: ");
    scanf("%d", &student.roll_no);
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter Marks: ");
    scanf("%f", &student.marks);

    fseek(data_fp, 0, SEEK_END);
    position = ftell(data_fp);
    fwrite(&student, sizeof(struct Student), 1, data_fp);

    fwrite(&student.roll_no, sizeof(int), 1, index_fp);
    fwrite(&position, sizeof(int), 1, index_fp);

    printf("Student record added successfully.\n");
}

void display_students(FILE *data_fp, FILE *index_fp) {
    struct Student student;
    int roll_no, position;

    rewind(index_fp);
    printf("\nRoll No\tName\tMarks\n");
    while (fread(&roll_no, sizeof(int), 1, index_fp) && fread(&position, sizeof(int), 1, index_fp)) {
        fseek(data_fp, position, SEEK_SET);
        fread(&student, sizeof(struct Student), 1, data_fp);
        printf("%d\t%s\t%.2f\n", student.roll_no, student.name, student.marks);
    }
}

int main() {
    FILE *data_fp, *index_fp;
    int choice;

    data_fp = fopen("index_students.dat", "wb+");
    index_fp = fopen("student_index.dat", "wb+");
    if (data_fp == NULL || index_fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student(data_fp, index_fp);
                break;
            case 2:
                display_students(data_fp, index_fp);
                break;
            case 3:
                fclose(data_fp);
                fclose(index_fp);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
