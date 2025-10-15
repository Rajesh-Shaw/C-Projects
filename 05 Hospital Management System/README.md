🏥 Hospital Management System (C Project)

📘 Overview
    The Hospital Management System is a console-based C language project.
    It allows hospital staff to manage patients, doctors, appointments, and billing efficiently.
    All data can be stored permanently in files (patients.txt, doctors.txt, appointments.txt, bills.txt) to maintain records.

⚙️ Features
    ✅ Add new patients
    ✅ Display all patients
    ✅ Search patient by ID
    ✅ Add new doctors
    ✅ Display all doctors
    ✅ Search doctor by ID
    ✅ Schedule appointments (patient + doctor + date + time)
    ✅ View all appointments
    ✅ Generate bills for patients
    ✅ View all bills
    ✅ File-based storage for data persistence
    ✅ Beginner-friendly text interface

🧱 Project Structure
    hospital_management.c → main source code
    patients.txt → stores patient records
    doctors.txt → stores doctor records
    appointments.txt → stores scheduled appointments
    bills.txt → stores billing records


💡 Functionalities Explained

    Function	            Description
    addPatient()	        Adds a new patient with details like name, age, gender, and ailment.
    displayPatients()	    Displays all saved patient records.
    searchPatient()	        Searches a patient using their ID.
    addDoctor()	            Adds a new doctor with name and specialization.
    displayDoctors()	    Displays all doctors.
    searchDoctor()	        Searches a doctor using their ID.
    scheduleAppointment()	Schedules an appointment linking patient and doctor with date/time.
    viewAppointments()	    Displays all appointments.
    generateBill()	        Generates a bill for a patient with amount and date.
    viewBills()	            Displays all billing records.
    save/load Files()	    Saves or loads data from files for persistence.


🧰 Technologies Used
    Language: C
    Compiler: GCC / Turbo C / Code::Blocks
    Concepts Used: Structures, Arrays, Loops, Conditional Statements, File Handling, Date/Time (time.h)


▶️ How to Run
    1. Open a C compiler (Code::Blocks, Dev C++, Turbo C, or GCC).
    2. Create a new project and add hospital_management.c.
    3. Compile the program:
            gcc hospital_management.c -o hospital
    4. Run the program:
            ./hospital


Interact with the menu:
    1. Add Patient
    2. Display Patients
    3. Search Patient
    4. Add Doctor
    5. Display Doctors
    6. Search Doctor
    7. Schedule Appointment
    8. View Appointments
    9. Generate Bill
    10. View Bills
    11. Save & Exit


🧩 Sample Data Files

    patients.txt
        101,Arjun Mehta,35,Male,Cold & Fever
        102,Neha Sharma,28,Female,Headache

    doctors.txt
        201,Dr. Ravi Kumar,General Physician
        202,Dr. Pooja Reddy,Cardiologist

    appointments.txt
        301,101,201,15-10-2025,10:30
        302,102,202,16-10-2025,11:00

    bills.txt
        401,101,500.00,15-10-2025
        402,102,1200.00,16-10-2025



👨‍💻 Author
    Rajesh Shaw
    🎓 B.Tech (Computer Science) Student
    📍 India
    📧 rkshaw5200@gmail.com
    💻 GitHub: https://github.com/Rajesh-Shaw



🏁 Future Enhancements 
    💳 Integrate UPI/Payment support
    🧾 Automatic prescription generation
    🔐 Password-protected access for staff
    📊 Appointment calendar
    🖥️ GUI version using C++/Python/Tkinter