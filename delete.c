#include <stdio.h>
#include <string.h>
#include "student.h"
#include "delete.h"

void delete_student() {
    char id[MAX_ID];
    printf("\n--- Delete Student ---\n");
    printf("Enter Admission ID to delete: ");
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
            s.is_deleted = 1;
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            found = 1;
            printf("Student record deleted!\n");
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
} 