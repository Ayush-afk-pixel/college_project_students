# 📘 Admission Management System in C (Student Record Project with File Handling)

**⭐ A Complete C Project for College Students | With Source Code + Fee Calculation + Login System**

This is a **basic C language project** made for a friend’s **college assessment**, focusing on student record management using file handling. The project helps manage admission records efficiently with features like login, data storage, searching, and scholarship-based fee calculation.

---

## 🔐 Features

- ✅ **Login System** (Username: `admin`, Password: `admin123`)
- ➕ Add New Student Records
- ✏️ Modify Existing Student Records
- ❌ Delete Student Records
- 🔍 Search Students by Name, Course, or Admission ID
- 👁️ View All Student Data
- 💰 **Scholarship & Fee Calculation**:
  - 25% State Domicile Discount
  - 10% Gender-based Discount (for Female Students)
  - 12th Grade Percentage Scholarship:
    - 50% (≥ 90%)
    - 30% (80% - 89%)
    - 10% (70% - 79%)

---

## 💾 File Handling in C

Student data is stored securely using **C file I/O functions**, ensuring persistent and structured record-keeping across sessions.

---

## 🗂 Project Structure

📁 Project Files:
├── main.c
├── student.h
├── login.c / login.h
├── add.c / add.h
├── modify.c / modify.h
├── delete.c / delete.h
├── search.c / search.h
├── view.c / view.h
└── fees.c / fees.h

---

## 🛠️ How to Compile and Run (Windows using GCC)

1. Open **Command Prompt** in your project directory.
2. Compile all `.c` files:

```bash
gcc main.c login.c add.c modify.c delete.c search.c view.c fees.c -o admission.exe
```
3. Run the executable:
```bash
admission.exe
```
