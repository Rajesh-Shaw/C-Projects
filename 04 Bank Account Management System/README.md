# 🏦 Bank Account Management System (C Project)

## 📘 Overview
The **Bank Account Management System** is a console-based project in **C language**.

It allows users to manage **multiple bank accounts** — create new accounts, deposit or withdraw money, and view transaction history per account.  
All data (including transaction records) is **permanently stored** in files — even after the program exits.

---

## ⚙️ Features
✅ Create a new bank account  
✅ Display all existing accounts  
✅ Search account by account number  
✅ Deposit or withdraw money  
✅ Maintain **transaction history** for every account  
✅ Automatically save data in `accounts.txt` and `transactions.txt`  
✅ Simple and beginner-friendly text interface  

---

## 🧱 Project Structure
bank_management.c → Main source code
accounts.txt → Stores account details
transactions.txt → Stores deposit & withdrawal history
README.md → Project documentation


---

## 💡 Functionalities Explained

| Function | Description |
|-----------|--------------|
| `createAccount()` | Creates a new customer account with basic details. |
| `displayAccounts()` | Displays all accounts with balances and types. |
| `searchAccount()` | Finds account details by account number. |
| `depositMoney()` | Adds money and records the transaction in `transactions.txt`. |
| `withdrawMoney()` | Deducts money and records the transaction in `transactions.txt`. |
| `viewTransactions()` | Displays deposit & withdrawal history for a given account. |
| `saveToFile()` | Saves all accounts to `accounts.txt`. |
| `loadFromFile()` | Loads saved accounts at startup. |

---

## 🧾 Transaction Record Format
Each transaction (deposit or withdrawal) is stored in **`transactions.txt`** like this:


### Example:
1001,Deposit,2000.00,7000.00,13-10-2025 10:35
1001,Withdraw,1000.00,6000.00,13-10-2025 11:20
1002,Deposit,5000.00,17500.00,13-10-2025 14:02



---

## 🧰 Technologies Used
- **Language:** C  
- **Compiler:** GCC / Turbo C / Code::Blocks  
- **Concepts:** Structures, File Handling, Arrays, Loops, Conditional Statements, Date & Time  

---

## ▶️ How to Run (Step-by-Step)
1. Open any **C compiler** (GCC, Turbo C, Code::Blocks, or Dev C++).  
2. Create a new file named `bank_management.c` and copy the code.  
3. Compile:  
4. Run:  
5. Use the on-screen menu:

========= Bank Account Management =========
1. Create Account
2. Display All Accounts
3. Search Account
4. Deposit Money
5. Withdraw Money
6. View Transaction History
7. Save & Exit


---

## 📂 Sample Files

### 📁 `accounts.txt`
1001,Arjun Mehta,Savings,6000.00
1002,Neha Sharma,Current,12500.75
1003,Ravi Patel,Savings,8200.00


### 📁 `transactions.txt`
1001,Deposit,2000.00,7000.00,13-10-2025 10:35
1001,Withdraw,1000.00,6000.00,13-10-2025 11:20
1002,Deposit,5000.00,17500.00,13-10-2025 14:02




👨‍💻 Author
Rajesh Shaw
🎓 B.Tech (Computer Science)
📍 India
📧 rkshaw5200@gmail.com
💻 GitHub: Rajesh-Shaw


🏁 Future Enhancements (Indian Banking Features)
💳 Add IFSC/UPI number for every account
🔐 Add password security for user login
🧾 Generate printable account statement (PDF/text)
💰 Add interest & tax calculation system
🖥️ Create GUI using C++/Python