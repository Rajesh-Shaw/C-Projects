# 🏪 Inventory Management System (C Language)

A simple yet powerful **Inventory Management System** built in **C**.  
This project demonstrates the use of key C programming concepts such as:
- Structures
- Arrays
- File Handling
- Functions
- Date and Time
- Control Statements

It allows users to **add, view, search, update, and sell products** while keeping a permanent record in text files.

---

## 🚀 Features

✅ **Product Management**
- Add new products with name, price, and quantity  
- View all available products  
- Search products by ID  
- Update product details  
- Data is automatically saved in `products.txt`

✅ **Sales Management**
- Record product sales  
- Auto-updates product stock after each sale  
- Calculates total sale amount  
- Stores sale date and time  
- Sales data is saved in `sales.txt`

✅ **File Handling**
- All records are stored persistently in text files  
- Automatically loads saved data on startup  
- Saves updated data on exit

---

## 🧠 Concepts Covered

This project uses almost every major concept in C programming:

| Category | Concepts Used |
|-----------|----------------|
| **Basics** | Variables, Data Types, Operators |
| **Control Flow** | `if`, `if-else`, `switch`, `for`, `while`, `break`, `continue` |
| **Functions** | Function definitions, declarations, and calls |
| **Arrays & Strings** | One-dimensional arrays, string handling |
| **Structures** | User-defined types for product and sales records |
| **Pointers** | Used indirectly in string and file handling |
| **File Handling** | `fopen()`, `fprintf()`, `fscanf()`, `fclose()` |
| **Date & Time** | `time.h` and `strftime()` for timestamps |

---

## 📂 Project Structure

Inventory-Management-System/
│
├── main.c # Main source code file
├── products.txt # Stores all product data
├── sales.txt # Stores all sales records
└── README.md # Documentation (this file)


---

## 🛠️ How to Compile and Run

### **Using GCC (Linux/Mac/Windows with MinGW):**

```bash
gcc inventory.c -o inventory
./inventory


Using Turbo C/C++ (Windows):
Open inventory.c in Turbo C.
Press Alt + F9 to compile.
Press Ctrl + F9 to run.


🧩 Menu Options
Option	Description
1	Add Product
2	Display All Products
3	Search Product by ID
4	Update Product
5	Record Sale
6	View Sales Record
7	Save and Exit


💾 File Format Example
products.txt
1,Soap,50,25.00,15-Oct-2025 10:30
2,Shampoo,20,120.50,15-Oct-2025 10:35

sales.txt
1,1,5,125.00,15-Oct-2025 11:00
2,2,2,241.00,15-Oct-2025 11:10

🧰 Future Improvements
Add login system for admin and cashier roles
Generate daily sales reports
Support for binary file storage for better data security
Export reports to .csv or .xlsx


👨‍💻 Author

Rajesh Shaw
rkshaw5200@gmail.com

💬 Made with ❤️ using C Language