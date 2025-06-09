#include <stdio.h>
#include <string.h>
#include "student.h"
#include "search.h"

void search_student() {
    int choice;
    char query[MAX_NAME];
    printf("\n--- Search Student ---\n");
    printf("1. By Name\n2. By Course\n3. By Admission ID\nChoose option: ");
    scanf("%d", &choice);
    printf("Enter search value: ");
    scanf("%49s", query);
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.is_deleted) continue;
        if ((choice == 1 && strcmp(s.name, query) == 0) ||
            (choice == 2 && strcmp(s.course, query) == 0) ||
            (choice == 3 && strcmp(s.admission_id, query) == 0)) {
            printf("\nID: %s\nName: %s\nGender: %s\nState: %s\nCourse: %s\n12th %%: %.2f\n",
                s.admission_id, s.name, s.gender, s.state, s.course, s.marks_12th);
            found = 1;
        }
    }
    if (!found) printf("No matching student found!\n");
    fclose(fp);
} 