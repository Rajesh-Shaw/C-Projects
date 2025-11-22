💳 ATM Simulator System in C
A console-based ATM Simulator built in C that allows users to create bank accounts, login securely using a PIN, and perform basic banking operations such as deposit, withdrawal, balance inquiry, and PIN change. All data is stored persistently using file handling.
________________________________________
📌 Features
•	Create new bank account
•	Secure login with Account Number & PIN
•	Check account balance
•	Deposit money
•	Withdraw money
•	Change PIN
•	Persistent storage using accounts.dat file
•	Menu-driven user interface
________________________________________
🛠 Technologies Used
•	C Programming Language
•	File Handling
•	Structures
•	Standard Input/Output
________________________________________
📂 Project Structure
ATM Simulator System
│
├── atm.c
├── accounts.dat   (generated automatically)
└── README.md
________________________________________
🚀 How to Compile & Run
✅ Windows (GCC)
gcc atm.c -o atm
./atm.exe
✅ Linux / macOS
gcc atm.c -o atm
./atm
________________________________________
📖 How It Works
1.	Run the program
2.	Choose:
o	Create Account
o	Login
o	Exit
3.	After login, access ATM features:
o	Balance Check
o	Deposit
o	Withdraw
o	Change PIN
o	Logout
All account details are saved in a binary file so data remains after program restart.
________________________________________
💾 Default File
•	accounts.dat
This file stores all account records automatically when you create accounts.
________________________________________
🧪 Sample Output
===== ATM SYSTEM =====
1. Create Account
2. Login
3. Exit
Enter choice: 2

--- Login ---
Enter Account Number: 1001
Enter PIN: ****

✅ Login Successful!
________________________________________
⚠️ Notes
•	Use numeric PIN only.
•	Do not delete accounts.dat unless you want to reset all accounts.
•	Account numbers should be unique.
________________________________________
🔧 Future Enhancements
•	Transaction history
•	Admin panel
•	Account deletion
•	GUI version
•	Data encryption
________________________________________
👨‍💻 Author
Rajesh Shaw
📧 rkshaw5200@gmail.com