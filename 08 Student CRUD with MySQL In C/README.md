# Student CRUD with MySQL in C

A simple **CRUD (Create, Read, Update, Delete)** program in C that interacts with a MySQL database to manage student records.

---

## Features

- Connects to a MySQL database
- Create new student records
- Read/view all students
- Update existing student records
- Delete student records
- Simple menu-driven console interface

---

## Requirements

- GCC Compiler
- MySQL Server installed and running
- MySQL C Connector installed
- Windows / Linux / macOS terminal

---

## Setup

### 1. MySQL Database

Start your MySQL server and create the database:

```sql
CREATE DATABASE IF NOT EXISTS student_db;
USE student_db;

CREATE TABLE IF NOT EXISTS students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    age INT NOT NULL
);
2. MySQL C Connector
Download and install MySQL Connector/C:
MySQL Connector/C Downloads

Make note of the include and lib paths (needed for compilation).

3. Update db.c Credentials
Edit db.c to match your MySQL credentials:

c
Copy code
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"      // Your MySQL password
#define DB_NAME "student_db"
Compilation
Open your terminal in the project folder and compile:

bash
Copy code
gcc main.c db.c -o student_crud -I"C:\Program Files\MySQL\MySQL Connector C 6.1\include" -L"C:\Program Files\MySQL\MySQL Connector C 6.1\lib" -lmysql
Adjust the include and lib paths according to your system.

Running the Program
bash
Copy code
./student_crud.exe
You should see:

markdown
Copy code
Program started!
✅ Connected to MySQL database!

====== Student CRUD Menu ======
1. Create Student
2. View Students
3. Update Student
4. Delete Student
5. Exit
Enter your choice:
Usage
Create Student: Add a new student record.

View Students: Display all students in the database.

Update Student: Modify an existing student's name and age.

Delete Student: Remove a student by ID.

Exit: Quit the program.

Troubleshooting
Connection failed / SSL errors: Add this line in connect_db() before connecting:

c
Copy code
mysql_options(conn, MYSQL_OPT_SSL_MODE, (void *)0);
Library not found errors: Make sure libmysql.dll (Windows) is in the project folder or in your system PATH.

Database not found: Ensure student_db exists and students table is created.