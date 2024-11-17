#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int id;
    char name[50];
    char department[50];
} Record;

void writeSequential(FILE *file, Record record) {
    fwrite(&record, sizeof(Record), 1, file);
}

void displaySequential(FILE *file) {
    Record record;
    rewind(file);
    printf("\nSequential File Organization:\n");
    while (fread(&record, sizeof(Record), 1, file)) {
        printf("ID: %d, Name: %s, Department: %s\n", record.id, record.name, record.department);
    }
}

void writeDirect(FILE *file, Record record) {
    int position = record.id % MAX;
    fseek(file, position * sizeof(Record), SEEK_SET);
    fwrite(&record, sizeof(Record), 1, file);
}

void displayDirect(FILE *file) {
    Record record;
    printf("\nDirect File Organization:\n");
    for (int i = 0; i < MAX; i++) {
        fseek(file, i * sizeof(Record), SEEK_SET);
        if (fread(&record, sizeof(Record), 1, file) && record.id != 0) {
            printf("ID: %d, Name: %s, Department: %s\n", record.id, record.name, record.department);
        }
    }
}

void writeIndexed(FILE *file, Record record, FILE *indexFile) {
    fseek(file, 0, SEEK_END);
    long position = ftell(file);
    fwrite(&record, sizeof(Record), 1, file);
    fwrite(&record.id, sizeof(int), 1, indexFile);
    fwrite(&position, sizeof(long), 1, indexFile);
}

void displayIndexed(FILE *file, FILE *indexFile) {
    int id;
    long position;
    Record record;
    rewind(indexFile);
    printf("\nIndexed File Organization:\n");
    while (fread(&id, sizeof(int), 1, indexFile) && fread(&position, sizeof(long), 1, indexFile)) {
        fseek(file, position, SEEK_SET);
        fread(&record, sizeof(Record), 1, file);
        printf("ID: %d, Name: %s, Department: %s\n", record.id, record.name, record.department);
    }
}

int main() {
    FILE *sequentialFile = fopen("sequential.dat", "wb+");
    FILE *directFile = fopen("direct.dat", "wb+");
    FILE *indexedFile = fopen("indexed.dat", "wb+");
    FILE *indexFile = fopen("index.dat", "wb+");

    if (!sequentialFile || !directFile || !indexedFile || !indexFile) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Reset all blocks in the direct file to zero
    Record emptyRecord = {0, "", ""};
    for (int i = 0; i < MAX; i++) {
        fwrite(&emptyRecord, sizeof(Record), 1, directFile);
    }

    Record records[] = {
        {1, "Alice", "HR"},
        {11, "Bob", "Engineering"},
        {21, "Charlie", "Sales"},
        {2, "David", "Marketing"},
        {12, "Eve", "Finance"},
    };

    for (int i = 0; i < 5; i++) {
        writeSequential(sequentialFile, records[i]);
        writeDirect(directFile, records[i]);
        writeIndexed(indexedFile, records[i], indexFile);
    }

    displaySequential(sequentialFile);
    displayDirect(directFile);
    displayIndexed(indexedFile, indexFile);

    fclose(sequentialFile);
    fclose(directFile);
    fclose(indexedFile);
    fclose(indexFile);

    return 0;
}
