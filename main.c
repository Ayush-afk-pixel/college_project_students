#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "add.h"
#include "modify.h"
#include "delete.h"
#include "search.h"
#include "view.h"
#include "fees.h"

int main() {
    printf("\n=== Admission Management System ===\n");
    if (!login()) return 0;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Modify Student\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. View All Students\n");
        printf("6. Calculate Fee\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_student(); break;
            case 2: modify_student(); break;
            case 3: delete_student(); break;
            case 4: search_student(); break;
            case 5: view_students(); break;
            case 6: calculate_fee(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
