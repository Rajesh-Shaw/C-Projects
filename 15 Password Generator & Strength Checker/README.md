🔐 Password Generator & Strength Checker (C Project)
A secure and user-friendly console-based application written in C that allows users to generate strong passwords and evaluate the strength of existing passwords. Designed with robust input validation to prevent crashes and infinite loops.
________________________________________
✅ Features
🔑 Password Generator
•	Custom password length (4 – 100 characters)
•	Option to include:
o	Uppercase letters
o	Lowercase letters
o	Numbers
o	Special symbols
•	Randomized secure generation
•	Valid input handling (prevents invalid entries)

🛡 Password Strength Checker
•	Analyzes user-entered password
•	Classifies strength as:
o	WEAK
o	MEDIUM
o	STRONG
•	Checks for:
o	Length
o	Uppercase
o	Lowercase
o	Digits
o	Symbols
________________________________________
🖥 Sample Interface
===== PASSWORD GENERATOR & STRENGTH CHECKER =====
1. Generate Password
2. Check Password Strength
3. Exit
Enter choice: 1

Enter password length (4 - 100): 12
Include Uppercase? (1 = Yes, 0 = No): 1
Include Lowercase? (1 = Yes, 0 = No): 1
Include Numbers? (1 = Yes, 0 = No): 1
Include Symbols? (1 = Yes, 0 = No): 1

Generated Password: A7@fP2#qLx1!
________________________________________
🛠 Requirements
•	GCC Compiler
•	Windows / Linux / macOS terminal
________________________________________
⚙️ Compilation & Run
Windows / Linux / macOS
gcc main.c -o password_tool
./password_tool
________________________________________
📂 File Structure
15 Password Generator & Strength Checker/
│
├── main.c
└── README.md
________________________________________
🚀 How It Works
1.	User chooses an option from menu.
2.	For password generation:
o	Enters desired length.
o	Selects character types.
o	Program builds a character pool and generates a random password.
3.	For strength checking:
o	Program scans the password and evaluates character diversity.
________________________________________
🔧 Error Handling
•	Prevents invalid characters (e.g., letters when numbers required)
•	Ensures at least one character type is selected
•	Avoids infinite input loops
________________________________________
📈 Strength Criteria
Condition	Strength
< 6 characters	WEAK
≥ 6 with limited variety	MEDIUM
≥ 8 with uppercase, lowercase, numbers & symbols	STRONG
________________________________________
💡 Possible Enhancements
•	Save generated passwords to file
•	GUI-based version
•	Encrypted password vault
•	Password history
•	Clipboard copy feature
________________________________________
👨‍💻 Author
Rajesh Shaw
📧 rkshaw5200@gmail.com
📁 C Projects Series