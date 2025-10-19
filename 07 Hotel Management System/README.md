# 🏨 Hotel Management System (C Project)

A simple **Hotel Management System** written in C language that allows managing rooms, customers, and bookings efficiently.  
The system supports basic CRUD operations like adding rooms, booking, checking out, and viewing records — all with data persistence using text files.

---

## 📋 Features

✅ Add new rooms with type and price  
✅ View all available rooms  
✅ Search for a room by room number  
✅ Book a room for a customer  
✅ Check out and calculate the total bill  
✅ View all current bookings  
✅ Auto save and load room and booking data from text files  

---

## 🧠 How It Works

- **Room Data** is stored in `rooms.txt`  
- **Customer Booking Data** is stored in `booking.txt`  
- When the program starts, it automatically loads saved data.  
- When exiting, it automatically saves all current data.

---

## ⚙️ File Structure

Hotel Management System/
├── hotel.c # Main program source code
├── rooms.txt # Room details storage
├── booking.txt # Customer booking data
├── README.md # Project documentation


---

## 🚀 Compilation & Execution

### 🪟 For Windows (using GCC)
```bash
gcc hotel.c -o hotel.exe
hotel.exe

🐧 For Linux / macOS
gcc hotel.c -o hotel
./hotel


💾 Data Format
    rooms.txt
    <RoomNumber>,<RoomType>,<IsBooked>,<PricePerNight>

    booking.txt
    <ID>,<Name>,<Phone>,<RoomNumber>,<DaysStayed>,<TotalBill>,<CheckInDate>,<CheckOutDate>


📸 Sample Menu
=========== Hotel Management System ===========
1. Add Room
2. View All Rooms
3. Search Room
4. Book Room
5. Check-Out Room
6. View All Bookings
7. Save & Exit
==============================================
Enter your choice:


🏁 Future Enhancements
Add date/time validation
Add admin login system
Generate bills automatically in PDF format
Add sorting/filtering of bookings


👨‍💻 Author
Rajesh Shaw
📧 rkshaw5200@gmail.com