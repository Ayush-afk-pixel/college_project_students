#include <stdio.h>
#include <string.h>
#include "student.h"
#include "add.h"

void add_student() {
    FILE *fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("\n--- Add Student ---\n");
    printf("Admission ID: ");
    scanf("%19s", s.admission_id);
    printf("Name: ");
    scanf("%49s", s.name);
    printf("Gender (Male/Female): ");
    scanf("%9s", s.gender);
    printf("State: ");
    scanf("%29s", s.state);
    printf("Course: ");
    scanf("%29s", s.course);
    printf("12th Percentage: ");
    scanf("%f", &s.marks_12th);
    s.is_deleted = 0;
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
} 