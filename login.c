#include <stdio.h>
#include <string.h>
#include "login.h"

int login() {
    char username[20], password[20];
    printf("\n--- Login ---\n");
    printf("Username: ");
    scanf("%19s", username);
    printf("Password: ");
    scanf("%19s", password);
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials!\n");
        return 0;
    }
} 