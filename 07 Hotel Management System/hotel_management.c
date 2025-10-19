#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROOMS 500
#define MAX_CUSTOMERS 1000

struct Room
{
    int roomNumber;
    char type[20];      // Single, Double, Suite
    int isBooked;       // 0 = Available, 1 = Booked
    float pricePerNight;
};

struct Customer
{
    int id;
    char name[50];
    char phone[15];
    int roomNumber;
    int daysStayed;
    float totalBill;
    char checkInDate[20];
    char checkOutDate[20];
};

struct Room rooms[MAX_ROOMS];
struct Customer customers[MAX_CUSTOMERS];

int roomCount = 0;
int customerCount = 0;


void addRoom();
void viewRooms();
void searchRoom();

void bookRoom();
void checkOutRoom();
void viewBookings();

void saveRooms();
void loadRooms();
void saveCustomers();
void loadCustomers();


int main()
{
    int choice;
    loadRooms();
    loadCustomers();

    while (1)
    {
        printf("\n=========== Hotel Management System ===========\n");
        printf("1. Add Room\n");
        printf("2. View All Rooms\n");
        printf("3. Search Room\n");
        printf("4. Book Room\n");
        printf("5. Check-Out Room\n");
        printf("6. View All Bookings\n");
        printf("7. Save & Exit\n");
        printf("==============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addRoom(); break;
            case 2: viewRooms(); break;
            case 3: searchRoom(); break;
            case 4: bookRoom(); break;
            case 5: checkOutRoom(); break;
            case 6: viewBookings(); break;
            case 7: saveRooms();
                    saveCustomers();
                    printf("Data Saved! Exiting...\n");
                    exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}



void addRoom()
{
    if(roomCount >= MAX_ROOMS)
    {
        printf("Database Full");
        return;
    }
    struct Room room;
    printf("Enter Room Number: ");
    scanf("%d",&room.roomNumber);
    getchar();

    printf("Enter Room Type: ");
    fgets(room.type, sizeof(room.type), stdin);
    room.type[strcspn(room.type, "\n")] = '\0';

    room.isBooked = 0;            // 0 = Available
    printf("Enter Room Price Per Night: ");
    scanf("%f",&room.pricePerNight);

    rooms[roomCount++] = room;
    printf("Successfully Added the Room.");
}

void viewRooms()
{
    if(roomCount == 0)
    {
        printf("No Room In Hotel\n");
        return;
    }

    printf("--------------------------- Rooms Details ------------------------\n");
    printf("SL.\tRoom Number\tType\t\tIsBooked\tPrice/Night\n");
    printf("------------------------------------------------------------------\n");
    for(int i=0; i<roomCount; i++)
    {
        printf("%d\t%d\t%15s\t\t%d\t%0.2f\n", i+1, rooms[i].roomNumber, rooms[i].type, 
                    rooms[i].isBooked, rooms[i].pricePerNight );
    }
}

void searchRoom()
{
    if(roomCount == 0)
    {
        printf("No Room In Hotel\n");
        return;
    }
    int roomNum, found=0;
    printf("Enter Room Number to search: ");
    scanf("%d", &roomNum);
   
    for(int i=0; i<roomCount; i++)
    {
        if(rooms[i].roomNumber == roomNum)
        {
            printf("Found the Rooms, Here the Details  \n");
            printf("Room Number:\t%d\nRoom Type:\t%s\nRoom Avaible:\t%d\nRoom Price:\t%0.2f\n", 
                                        rooms[i].roomNumber, rooms[i].type, 
                                        rooms[i].isBooked, 
                                        rooms[i].pricePerNight );
            
            found =1;
            break;
        }
        
    }
    if(!found)
    printf("No room found with number %d\n", roomNum);
}


void bookRoom()
{
    if(customerCount >= MAX_CUSTOMERS)
    {
        printf("Database Full");
        return;
    }
    struct Customer customer;
    int found =0;

    customer.id = customerCount + 1;
    printf("Enter Customer Name: ");
    fgets(customer.name, sizeof(customer.name), stdin);
    customer.name[strcspn(customer.name, "\n")] = '\0';

    printf("Enter Customer Phone Number: ");
    fgets(customer.phone, sizeof(customer.phone), stdin);
    customer.phone[strcspn(customer.phone, "\n")] = '\0';

    printf("Enter Room Number: ");
    scanf("%d",&customer.roomNumber);
    {
        for(int i=0; i<roomCount; i++)
        {
            if(rooms[i].roomNumber == customer.roomNumber)
            {
                if(rooms[i].isBooked == 1)
                {
                    printf("Room already booked. Try another room.\n");
                    return;
                }
                else
                {
                    printf("Enter How Many day You Stay: ");
                    scanf("%d",&customer.daysStayed);

                    customer.totalBill = customer.daysStayed * rooms[i].pricePerNight;
                    rooms[i].isBooked = 1;
                }
                
                found =1;
                break;
            }
        }
        
    }
    getchar();
    printf("Enter checkIn Date: ");
    fgets(customer.checkInDate, sizeof(customer.checkInDate), stdin);
    customer.checkInDate[strcspn(customer.checkInDate, "\n")] = '\0';

    printf("Enter checkOut Date: ");
    fgets(customer.checkOutDate, sizeof(customer.checkOutDate), stdin);
    customer.checkOutDate[strcspn(customer.checkOutDate, "\n")] = '\0';

    customers[customerCount++] = customer;
    printf("Successfully Added the Room.");
}

void checkOutRoom()
{
    if(customerCount == 0)
    {
        printf("No Booking In Hotel\n");
        return;
    }
    int roomNum, found=0;
    int custIndex = -1;
    printf("Enter Room Number to Checkout: ");
    scanf("%d", &roomNum);
   
    for(int i=0; i<roomCount; i++)
    {
        if(rooms[i].roomNumber == roomNum)
        {
            if(rooms[i].isBooked)
            printf("Found the Booking, Here the Details  \n");
            rooms[i].isBooked =0;
            
            for(int i=0; i<customerCount; i++)
            {
                if(customers[i].roomNumber == roomNum)
                {
                    printf("Total Bill %0.2f\n",customers[i].totalBill);
                    custIndex = i;
                    break;
                }
            }

            if(custIndex != -1) {
                for(int j=custIndex; j<customerCount-1; j++) 
                    customers[j] = customers[j+1];
                customerCount--;
            }

            found =1;
            break;
        }
        
    }
    if(!found)
    printf("No Booking found with number %d\n", roomNum);
}


void viewBookings()
{
    if(customerCount == 0)
    {
        printf("No Booking In Hotel\n");
        return;
    }

    printf("-------------------------------- Booking Details ----------------------------------------\n");
    printf("SL.\tCustomer Name\tPhone Number\tRoom Number\tDays Stayed\tTotal Bill\tcheckInDate\t checkOutDate\n");
    printf("------------------------------------------------------------------------------------------\n");
    for(int i=0; i<customerCount; i++)
    {
        printf("%d\t%-15s\t%-15s\t%d\t\t\t%d\t%0.2f\t%s\t\t%s\n", 
        i+1, customers[i].name, customers[i].phone,
        customers[i].roomNumber, customers[i].daysStayed, 
        customers[i].totalBill, customers[i].checkInDate, 
        customers[i].checkOutDate);
    }
}



void saveRooms()
{
    FILE *fp = fopen("rooms.txt", "w");
    if(fp==NULL)
    {
        printf("Error of Saving Data");
        return;
    }
    for(int i=0; i<roomCount; i++)
    {
        fprintf(fp, "%d,%s,%d,%f\n", rooms[i].roomNumber, rooms[i].type, rooms[i].isBooked, rooms[i].pricePerNight);
    }
    fclose(fp);
}

void loadRooms()
{
    FILE *fp = fopen("rooms.txt", "r");
    if(fp==NULL)
    {
        printf("Error of Loading Data");
        return;
    }
    while(fscanf(fp, "%d,%19[^,],%d,%f\n",
             &rooms[roomCount].roomNumber,
             rooms[roomCount].type,
             &rooms[roomCount].isBooked,
             &rooms[roomCount].pricePerNight) == 4)
    {
        roomCount++;
    }
    fclose(fp);
}

void saveCustomers()
{
    FILE *fp = fopen("booking.txt", "w");
    if(fp==NULL)
    {
        printf("Error of Saving Data");
        return;
    }
    for(int i=0; i<customerCount; i++)
    {
        fprintf(fp, "%d,%s,%s,%d,%d,%f,%s,%s\n", 
                customers[i].id, 
                customers[i].name, 
                customers[i].phone, 
                customers[i].roomNumber, 
                customers[i].daysStayed, 
                customers[i].totalBill, 
                customers[i].checkInDate, 
                customers[i].checkOutDate);
    }
    fclose(fp);
}

void loadCustomers()
{
    FILE *fp = fopen("booking.txt", "r");
    if(fp==NULL)
    {
        printf("Error of Loading Data");
        return;
    }
    while(fscanf(fp, "%d,%49[^,],%14[^,],%d,%d,%f,%19[^,],%19[^\n]\n",
             &customers[customerCount].id,
             customers[customerCount].name,
             customers[customerCount].phone,
             &customers[customerCount].roomNumber,
             &customers[customerCount].daysStayed,
             &customers[customerCount].totalBill,
             customers[customerCount].checkInDate,
             customers[customerCount].checkOutDate) == 8)
    {
        customerCount++;
    }
    fclose(fp);
}