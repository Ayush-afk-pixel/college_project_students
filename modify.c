#include <stdio.h>
#include <string.h>
#include "student.h"
#include "modify.h"

void modify_student() {
    char id[MAX_ID];
    printf("\n--- Modify Student ---\n");
    printf("Enter Admission ID to modify: ");
    scanf("%19s", id);
    FILE *fp = fopen("students.dat", "rb+");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (strcmp(s.admission_id, id) == 0 && !s.is_deleted) {
            printf("Enter new name: ");
            scanf("%49s", s.name);
            printf("Enter new gender: ");
            scanf("%9s", s.gender);
            printf("Enter new state: ");
            scanf("%29s", s.state);
            printf("Enter new course: ");
            scanf("%29s", s.course);
            printf("Enter new 12th percentage: ");
            scanf("%f", &s.marks_12th);
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            found = 1;
            printf("Student record updated!\n");
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
} 