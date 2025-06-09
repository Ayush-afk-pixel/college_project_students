#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "student.h"
#include "fees.h"

int is_domicile(const char *state) {
    for (int i = 0; i < NUM_DOMICILE_STATES; ++i) {
        if (strcasecmp(state, DOMICILE_STATES[i]) == 0) return 1;
    }
    return 0;
}

float get_scholarship(float marks) {
    if (marks >= 90) return 0.5;
    if (marks >= 80) return 0.3;
    if (marks >= 70) return 0.1;
    return 0.0;
}

void calculate_fee() {
    char id[MAX_ID];
    printf("\n--- Calculate Fee ---\n");
    printf("Enter Admission ID: ");
    scanf("%19s", id);
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (strcmp(s.admission_id, id) == 0 && !s.is_deleted) {
            found = 1;
            float fee = BASE_FEE;
            float scholarship = get_scholarship(s.marks_12th);
            float scholarship_amt = fee * scholarship;
            fee -= scholarship_amt;
            float domicile_amt = 0, female_amt = 0;
            if (is_domicile(s.state)) {
                domicile_amt = fee * DOMICILE_DISCOUNT;
                fee -= domicile_amt;
            }
            if (strcasecmp(s.gender, "Female") == 0) {
                female_amt = fee * FEMALE_DISCOUNT;
                fee -= female_amt;
            }
            printf("\nBase Fee: ₹%d\n", BASE_FEE);
            printf("Scholarship (%.0f%%): -₹%.2f\n", scholarship*100, scholarship_amt);
            printf("Domicile Discount (%.0f%%): -₹%.2f\n", is_domicile(s.state)?DOMICILE_DISCOUNT*100:0, domicile_amt);
            printf("Female Discount (%.0f%%): -₹%.2f\n", (strcasecmp(s.gender, "Female") == 0)?FEMALE_DISCOUNT*100:0, female_amt);
            printf("Final Payable Fee: ₹%.2f\n", fee);
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
} 