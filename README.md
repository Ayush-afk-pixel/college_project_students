# Admission Management System (C Project)

## Features
- Login system (admin/admin123)
- Add, modify, delete, search, and view student records
- File handling for secure data storage
- Scholarship and fee calculation:
  - State-based domicile discount (25%)
  - Gender-based discount (10% for females)
  - 12th percentage-based scholarship (50%, 30%, 10%)

## Files
- main.c
- student.h
- login.c / login.h
- add.c / add.h
- modify.c / modify.h
- delete.c / delete.h
- search.c / search.h
- view.c / view.h
- fees.c / fees.h

## How to Compile (Windows, GCC)

1. Open Command Prompt in the project folder.
2. Run:

```
gcc main.c login.c add.c modify.c delete.c search.c view.c fees.c -o admission.exe
```

3. Run the program:

```
admission.exe
```

## Usage
- Login with username: `admin` and password: `admin123`
- Use the menu to manage student records and calculate fees. 