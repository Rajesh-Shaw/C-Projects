Online Examination System in C with MySQL
    A simple Online Examination System implemented in C with MySQL as the backend database.
Supports both Admin and Student roles with a console-based, menu-driven interface.
________________________________________
Features
    User Authentication
    •	Login system for Admins and Students
    Admin Features
    •	Add questions
    •	View all questions
    Student Features
    •	Take exams
    •	View previous results
    MySQL Integration
    •	Stores users, questions, and results
    •	Menu-driven CLI interface for easy interaction
________________________________________
Requirements
    •	GCC Compiler
    •	MySQL Server installed and running
    •	MySQL C Connector installed
    •	Windows / Linux / macOS terminal
________________________________________
Setup
    1. Start MySQL Server
    Make sure your MySQL server is running.
    Windows:
    net start MySQL
    Linux:
    sudo service mysql start
    ________________________________________
    2. Create Database and Tables
    CREATE DATABASE IF NOT EXISTS exam_db;
    USE exam_db;

    -- Users table
    CREATE TABLE IF NOT EXISTS users (
        user_id INT AUTO_INCREMENT PRIMARY KEY,
        username VARCHAR(50) UNIQUE NOT NULL,
        password VARCHAR(50) NOT NULL,
        role VARCHAR(10) NOT NULL  -- 'admin' or 'student'
    );

    -- Questions table
    CREATE TABLE IF NOT EXISTS questions (
        question_id INT AUTO_INCREMENT PRIMARY KEY,
        question_text VARCHAR(500) NOT NULL,
        option1 VARCHAR(200),
        option2 VARCHAR(200),
        option3 VARCHAR(200),
        option4 VARCHAR(200),
        correct_option INT
    );

    -- Results table
    CREATE TABLE IF NOT EXISTS results (
        result_id INT AUTO_INCREMENT PRIMARY KEY,
        user_id INT NOT NULL,
        score INT,
        total INT,
        taken_on TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY(user_id) REFERENCES users(user_id)
    );

    -- Add an admin user
    INSERT INTO users (username, password, role) VALUES ('admin', 'admin123', 'admin');
________________________________________
3. Update Database Credentials
    Edit db.c:
    #define DB_HOST "localhost"
    #define DB_USER "root"
    #define DB_PASS "Password"
    #define DB_NAME "exam_db"
    Disable SSL if needed:
    mysql_options(conn, MYSQL_OPT_SSL_MODE, (void *)0);
________________________________________
4. Compilation (Windows Example)
    gcc main.c db.c admin.c student.c -o exam_system ^
    -I"C:\Program Files\MySQL\MySQL Connector C 6.1\include" ^
    -L"C:\Program Files\MySQL\MySQL Connector C 6.1\lib" -lmysql
    Adjust include/lib paths according to your system.
________________________________________
5. Running the Program
    ./exam_system.exe
    Expected Output:
    Connected to MySQL database!

    ===== Online Examination System =====
    1. Login
    2. Exit
    Enter choice:
________________________________________
Usage
    •	Login as Admin
    o	Add or view questions
    •	Login as Student
    o	Take exams
    o	View previous results
________________________________________
Troubleshooting
    •	SSL connection error:
    Add this line in connect_db():
    •	mysql_options(conn, MYSQL_OPT_SSL_MODE, (void *)0);
    •	Library errors:
    Ensure libmysql.dll is in your project folder or system PATH.
    •	Database connection fails:
    Check credentials and confirm MySQL server is running.
________________________________________
Author
    Rajesh Shaw
    Email: rkshaw5200@gmail.com