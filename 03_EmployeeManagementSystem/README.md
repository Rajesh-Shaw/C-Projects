# 🧑‍💼 Employee Management System (C Project)

A simple **Employee Management System** built in **C language** that allows users to manage employee records — including adding, searching, displaying, deleting, and saving employee data to a file (`employees.txt`).

---

## 📋 Features

- ➕ **Add Employee** — Add new employee details such as ID, name, age, salary, and department.  
- 📄 **Display All Employees** — View all employee records stored in the system.  
- 🔍 **Search Employee by ID** — Find a specific employee using their unique ID.  
- ❌ **Delete Employee by ID** — Remove an employee record permanently.  
- 💾 **File Handling** — Data is automatically saved to and loaded from `employees.txt`.  
- 🚀 **Persistent Storage** — Your records remain even after you close the program.

---

## 🧠 Concepts Used

- Structures (`struct`)
- Arrays
- Functions
- File Handling (`fopen`, `fscanf`, `fprintf`)
- Loops and Conditional Statements
- String Manipulation (`fgets`, `strcspn`)

---

## 🧾 File Structure

| File Name         | Description |
|--------------------|-------------|
| `employee_management.c` | Main source code |
| `employees.txt`         | Stores employee records persistently |
| `README.md`             | Project documentation |

---

## ⚙️ How to Compile and Run

### 🖥️ Using GCC (Command Line)
```bash
gcc employee_management.c -o employee_management
./employee_management