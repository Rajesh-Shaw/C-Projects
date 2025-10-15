#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_PATIENTS 1000
#define MAX_DOCTORS 100
#define MAX_APPOINTMENT 5000
#define MAX_BILLS 5000

// ------------------ STRUCTURES ------------------
struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char ailment[100];
};

struct Doctor
{
    int id;
    char name[50];
    char specialization[50];
};

struct Appointment
{
    int id;
    int patientId;
    int doctorId;
    char date[20];
    char time[10];
};

struct Bill
{
    int id;
    int patientId;
    float amount;
    char date[10];
};

// ------------------ Global Arrays ------------------
struct Patient patients[MAX_PATIENTS];
struct Doctor doctors[MAX_DOCTORS];
struct Appointment appointments[MAX_APPOINTMENT];
struct Bill bills[MAX_BILLS];

int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;
int billCount = 0;


// ------------------ FUNCTION DECLARATIONS ------------------
void addPatient();
void displayPatients();
void searchPatient();

void addDoctor();
void displayDoctors();
void searchDoctor();

void scheduleAppointment();
void viewAppointments();

void generateBill();
void viewBills();

// File funtions
void savePatients();
void loadPatients();
void saveDoctors();
void loadDoctors();
void saveAppointments();
void loadAppointments();
void saveBills();
void loadBills();


int main()
{
    int choice;
    loadPatients();
    loadDoctors();
    loadAppointments();
    loadBills();

    while(1)
    {
        printf("\n=========== Hospital Management System ===========\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Add Doctor\n");
        printf("5. Display Doctors\n");
        printf("6. Search Doctor\n");
        printf("7. Schedule Appointment\n");
        printf("8. View Appointments\n");
        printf("9. Generate Bill\n");
        printf("10. View Bills\n");
        printf("11. Save & Exit\n");
        printf("=================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: addDoctor(); break;
            case 5: displayDoctors(); break;
            case 6: searchDoctor(); break;
            case 7: scheduleAppointment(); break;
            case 8: viewAppointments(); break;
            case 9: generateBill(); break;
            case 10: viewBills(); break;
            case 11: printf("Data Saved, Exiting...\n");
                     exit(0);
            default: printf("Invalid Choice! Please Try again.\n");
        }
    }
    return 0;
}


void addPatient()
{
    if(patientCount >= MAX_PATIENTS)
    {
        printf("Patient Database full! Not able to add Data");
        return;
    }

    struct Patient patient;
    printf("Enter Patient Id: ");
    scanf("%d",&patient.id);
    getchar();

    printf("Enter Patient Name: ");
    fgets(patient.name, sizeof(patient.name), stdin);
    patient.name[strcspn(patient.name, "\n")] = '\0';

    printf("Enter Patient age: ");
    scanf("%d",&patient.age);
    getchar();

    printf("Enter Patient Gender: ");
    fgets(patient.gender, sizeof(patient.gender), stdin);
    patient.gender[strcspn(patient.gender, "\n")] = '\0';

    printf("Enter Patient Ailment(disease/issue): ");
    fgets(patient.ailment, sizeof(patient.ailment), stdin);
    patient.ailment[strcspn(patient.ailment, "\n")] = '\0';

    patients[patientCount] = patient;
    savePatients();
    patientCount++;
    printf("Patient Data Added Successfully.\n");
}

void displayPatients()
{
    if(patientCount == 0)
    {
        printf("No Patient Record in Database!");
        return;
    }

    printf("\n---------- Patient Records --------------\n");
    printf("ID\tName\t\tAge\tGender\tAilment\n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i<patientCount; i++)
    {
        printf("%d\t%-15s\t%d\t%-6s\t%s\n",
                    patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].ailment);
        
    }
}

void searchPatient()
{
    if(patientCount == 0)
    {
        printf("No Patient Record in Database!");
        return;
    }

    int id, found=0;
    printf("Enter Patient Id: ");
    scanf("%d",&id);

    for(int i=0; i<patientCount; i++)
    {
        if(patients[i].id == id)
        {
            printf("------------ Patient Record Found --------------\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nAilment: %s\n",
                    patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].ailment);
            
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Data Not Found!\n");
        return;
    }
}



void addDoctor()
{
    if(doctorCount >= MAX_DOCTORS)
    {
        printf("Doctor Database full! Not able to add Data");
        return;
    }

    struct Doctor doctor;
    printf("Enter Doctor Id: ");
    scanf("%d",&doctor.id);
    getchar();

    printf("Enter doctor Name: ");
    fgets(doctor.name, sizeof(doctor.name), stdin);
    doctor.name[strcspn(doctor.name, "\n")] = '\0';

    printf("Enter doctor specialization: ");
    fgets(doctor.specialization, sizeof(doctor.specialization), stdin);
    doctor.specialization[strcspn(doctor.specialization, "\n")] = '\0';

    doctors[doctorCount] = doctor;
    saveDoctors();
    doctorCount++;
    printf("Doctor Data Added Successfully.\n");
}

void displayDoctors()
{
    if(doctorCount == 0)
    {
        printf("No Doctor Record in Database!");
        return;
    }

    printf("\n---------- Doctor Records --------------\n");
    printf("ID\tName\t\tspecialization\n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i<doctorCount; i++)
    {
        printf("%d\t%-15s\t%s\n",
                    doctors[i].id, doctors[i].name, doctors[i].specialization);
        
    }
}

void searchDoctor()
{
    if(doctorCount == 0)
    {
        printf("No Doctor Record in Database!");
        return;
    }

    int id, found=0;
    printf("Enter Doctor Id: ");
    scanf("%d",&id);

    for(int i=0; i<doctorCount; i++)
    {
        if(doctors[i].id == id)
        {
            printf("------------ Doctor Record Found --------------\n");
            printf("ID: %d\nName: %s\nspecialization: %s\n",
                    doctors[i].id, doctors[i].name, doctors[i].specialization);
            
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Data Not Found!\n");
        return;
    }
}



void scheduleAppointment()
{
    if(appointmentCount >= MAX_APPOINTMENT)
    {
        printf("Appointment Database full! Not able to add Data");
        return;
    }

    struct Appointment appointment;
    printf("Enter Appointment Id: ");
    scanf("%d",&appointment.id);

    printf("Enter Patient Id: ");
    scanf("%d",&appointment.patientId);

    printf("Enter Doctor Id: ");
    scanf("%d",&appointment.doctorId);
    getchar();

    printf("Enter Appointment Date: ");
    fgets(appointment.date, sizeof(appointment.date), stdin);
    appointment.date[strcspn(appointment.date, "\n")] = '\0';

    printf("Enter Appointment Time: ");
    fgets(appointment.time, sizeof(appointment.time), stdin);
    appointment.time[strcspn(appointment.time, "\n")] = '\0';

    appointments[appointmentCount] = appointment;
    saveAppointments();
    appointmentCount++;

    printf("Appointment Scheduled Successfully.\n");
}


void viewAppointments()
{
    if(appointmentCount == 0)
    {
        printf("No Appointment Record Found in Database!");
        return;
    }

    printf("\n---------- Appointment Records --------------\n");
    printf("ID\tPatient Id\tDoctor Id\tDate\tTime\n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i<appointmentCount; i++)
    {
        printf("%d\t%d\t\t%d\t\t%-6s\t%s\n",
                    appointments[i].id, appointments[i].patientId, appointments[i].doctorId, appointments[i].date, appointments[i].time);
        
    }
}



void generateBill()
{
    if(billCount >= MAX_BILLS)
    {
        printf("Bills Database full! Not able to add Data");
        return;
    }

    struct Bill bill;
    printf("Enter Bill Id: ");
    scanf("%d",&bill.id);

    printf("Enter Patient Id: ");
    scanf("%d",&bill.patientId);

    printf("Enter Bill Amount: ");
    scanf("%f",&bill.amount);
    getchar();

    // printf("Enter Bill Date: ");
    // fgets(bill.date, sizeof(bill.date), stdin);
    // bill.date[strcspn(bill.date, "\n")] = '\0';

    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    strftime(bill.date, sizeof(bill.date), "%d-%m-%Y", tm_info);

    
    bills[billCount] = bill;
    saveBills();
    billCount++;
    printf("Bill Generate Successfully.\n");
}


void viewBills()
{
    if(billCount == 0)
    {
        printf("No Bill Record Found in Database!");
        return;
    }

    printf("\n---------- Bill Records --------------\n");
    printf("ID\tPatient Id\tAmount\tDate\n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i<billCount; i++)
    {
        printf("%d\t%d\t\t%0.2f\t%s\n",
                    bills[i].id, bills[i].patientId, bills[i].amount, bills[i].date);
        
    }
}



void savePatients()
{
    FILE *fp = fopen("patients.txt", "a");
    if(fp == NULL)
    {
        printf("Error saving patients file!\n");
        return;
    }

    fprintf(fp,"%d,%s,%d,%s,%s\n",patients[patientCount].id, patients[patientCount].name,
                patients[patientCount].age, patients[patientCount].gender, patients[patientCount].ailment);

    fclose(fp);
}

void loadPatients()
{
    FILE *fp=fopen("patients.txt","r");
    if(fp==NULL)
    {
        printf("No previous patient data found.\n");
        return;
    }

    while( fscanf(fp,"%d,%49[^,],%d,%9[^,],%99[^\n]\n",
                    &patients[patientCount].id, patients[patientCount].name, &patients[patientCount].age, 
                    patients[patientCount].gender, patients[patientCount].ailment) == 5)
    {
        patientCount++;
    }

    fclose(fp);
    printf("Loaded %d Patients.\n", patientCount);
}

void saveDoctors()
{
    FILE *fp = fopen("doctors.txt", "a");
    if(fp == NULL)
    {
        printf("Error saving doctor file!\n");
        return;
    }

    fprintf(fp,"%d,%s,%s\n",doctors[doctorCount].id, doctors[doctorCount].name, doctors[doctorCount].specialization);

    fclose(fp);
}

void loadDoctors()
{
    FILE *fp=fopen("doctors.txt","r");
    if(fp==NULL)
    {
        printf("No previous Doctor data found.\n");
        return;
    }

    while( fscanf(fp,"%d,%49[^,],%49[^\n]\n",
                    &doctors[doctorCount].id, doctors[doctorCount].name, doctors[doctorCount].specialization) == 3)
    {
        doctorCount++;
    }

    fclose(fp);
    printf("Loaded %d Doctors.\n", doctorCount);
}

void saveAppointments()
{
    FILE *fp = fopen("appointments.txt", "a");
    if(fp == NULL)
    {
        printf("Error saving appointment file!\n");
        return;
    }

    fprintf(fp,"%d,%d,%d,%s,%s\n",appointments[appointmentCount].id, appointments[appointmentCount].patientId, appointments[appointmentCount].doctorId, appointments[appointmentCount].date, appointments[appointmentCount].time);

    fclose(fp);
}

void loadAppointments()
{
    FILE *fp=fopen("appointments.txt","r");
    if(fp==NULL)
    {
        printf("No previous Appointment data found.\n");
        return;
    }

    while( fscanf(fp,"%d,%d,%d,%19[^,],%9[^\n]\n",
                    &appointments[appointmentCount].id, &appointments[appointmentCount].patientId, &appointments[appointmentCount].doctorId, 
                    appointments[appointmentCount].date, appointments[appointmentCount].time) == 5)
    {
        appointmentCount++;
    }

    fclose(fp);
    printf("Loaded %d Appointments.\n", appointmentCount);
}

void saveBills()
{
    FILE *fp = fopen("bills.txt", "a");
    if(fp == NULL)
    {
        printf("Error saving bills file!\n");
        return;
    }

    fprintf(fp,"%d,%d,%f,%s\n",bills[billCount].id, bills[billCount].patientId, bills[billCount].amount, bills[billCount].date);

    fclose(fp);
}

void loadBills()
{
    FILE *fp=fopen("bills.txt","r");
    if(fp==NULL)
    {
        printf("No previous Bill data found.\n");
        return;
    }

    while( fscanf(fp,"%d,%d,%f,%19[^\n]\n",
                    &bills[billCount].id, &bills[billCount].patientId, 
                    &bills[billCount].amount, bills[billCount].date) == 4)
    {
        billCount++;
    }

    fclose(fp);
    printf("Loaded %d Bill.\n", billCount);
}
