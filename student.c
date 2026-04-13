#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.txt", "ab");
    struct student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student Added Successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.txt", "rb");
    struct student s;

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.txt", "rb");
    struct student s;
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Found -> ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("students.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    struct student s;
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student Deleted Successfully!\n");
    else
        printf("Student not found!\n");
}

void updateStudent() {
    FILE *fp = fopen("students.txt", "rb+");
    struct student s;
    int id, found = 0;

    printf("Enter ID to update: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            break;
        }
    }

    if (found)
        printf("Student Updated Successfully!\n");
    else
        printf("Student not found!\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}