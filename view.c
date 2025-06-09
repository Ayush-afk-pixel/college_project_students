#include <stdio.h>
#include "student.h"
#include "view.h"

void view_students() {
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("\n--- All Students ---\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.is_deleted) continue;
        printf("ID: %s | Name: %s | Gender: %s | State: %s | Course: %s | 12th %%: %.2f\n",
            s.admission_id, s.name, s.gender, s.state, s.course, s.marks_12th);
    }
    fclose(fp);
} 