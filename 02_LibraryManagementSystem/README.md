# 📚 Library Management System (C Project)

## 🧩 Overview
The **Library Management System** is a simple console-based C program that allows users to manage a collection of books.  
It supports adding, searching, displaying, and deleting books, and also saves data to a text file (`books.txt`) so records are preserved between runs.

---

## 🚀 Features
✅ Add new books with details such as:
- Book ID  
- Title  
- Author  
- Price  

✅ Display all available books  
✅ Search for a book by its ID  
✅ Delete a book record by its ID  
✅ Save and load book data from `books.txt` file  
✅ Menu-driven interface for easy use  

---

## 🧠 Concepts Used
- **Structures (`struct`)**
- **File Handling (`fopen`, `fprintf`, `fscanf`, `fclose`)**
- **Arrays and Loops**
- **String Handling (`fgets`, `strcspn`)**
- **Conditional Statements and Switch Cases**

---

## 🛠️ How to Run the Program

### 🖥️ On Windows (using GCC or Code::Blocks)
1. Open **Code::Blocks** or any C IDE.
2. Create a new project → “Console Application”.
3. Copy and paste the source code (`library.c`) into the editor.
4. Press **Build and Run (F9)**.

### 🧰 On Linux / macOS (Terminal)
```bash
gcc library.c -o library
./library
