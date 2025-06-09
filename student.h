#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 50
#define MAX_COURSE 30
#define MAX_GENDER 10
#define MAX_STATE 30
#define MAX_ID 20

// Scholarship and discount constants
#define BASE_FEE 100000
#define DOMICILE_DISCOUNT 0.25
#define FEMALE_DISCOUNT 0.10

// States eligible for domicile discount
static const char* DOMICILE_STATES[] = {"Uttarakhand", "Himachal Pradesh", "Sikkim", "Arunachal Pradesh"};
static const int NUM_DOMICILE_STATES = 4;

typedef struct {
    char admission_id[MAX_ID];
    char name[MAX_NAME];
    char gender[MAX_GENDER];
    char state[MAX_STATE];
    char course[MAX_COURSE];
    float marks_12th;
    int is_deleted; // 0 = active, 1 = deleted
} Student;

#endif // STUDENT_H 