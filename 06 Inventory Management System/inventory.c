#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_PRODUCT 1000
#define MAX_SALE 1000

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
    char date[20];
};

struct Sale
{
    int saleId;
    int productID;
    int quantitySold;
    float totalAmount;
    char date[20];
};


struct Product products[MAX_PRODUCT];
struct Sale sales[MAX_SALE];

int productCount = 0;
int saleCount = 0;

void addProduct();
void viewProducts();
void searchProduct();
void updateProduct();

void recordSale();
void viewSales();

void saveProducts();
void loadProducts();
void saveSales();
void loadSales();



int main()
{
    int choice;
    loadProducts();
    loadSales();

    while (1)
    {
       printf("\n================ Inventory Management System  ====================\n");
       printf("1. Add Product\n");
       printf("2. Display All Product \n");
       printf("3. Search All Product \n");
       printf("4. Update Procuct \n");
       printf("5. Sale Record \n");
       printf("6. View Sales Record \n");
       printf("7. Save & Exit \n");
       printf("========================================================\n"); 

       printf("Enter Choice: ");
       scanf("%d",&choice);

       switch(choice)
       {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: recordSale(); break;
            case 6: viewSales(); break;
            case 7: saveProducts();
                    saveSales();
                    printf("All Data Saved! & Exiting...\n");
                    exit(0);
            default: printf("Invalid Choice! Try Again!");
       }

    }
    return 0;
}


void addProduct()
{
    if(productCount >= MAX_PRODUCT)
    {
        printf("Product Database Full!");
        return;
    }

    struct Product prod;
    prod.id = productCount + 1;
    getchar();
    printf("Enter Product Name: ");
    fgets(prod.name, sizeof(prod.name), stdin);
    prod.name[strcspn(prod.name, "\n")] = '\0';

    printf("Enter Product Quantity: ");
    scanf("%d", &prod.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &prod.price);

    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    strftime(prod.date, sizeof(prod.date), "%d-%m-%Y %H:%M", tm_info);

    products[productCount++] = prod;
    printf("Succesfully Added The Proudct.\n");
}

void viewProducts()
{
    if(productCount == 0)
    {
        printf("No Product Records.");
        return;
    }

    printf("----------------- Product Records -------------------------\n");
    printf("ID\tName\t\tQuantity\tPrice\tDate\n");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i<productCount; i++)
    {
        printf("%d\t%-15s\t%d\t\t%0.2f\t%s\n",products[i].id, products[i].name,
                products[i].quantity, products[i].price, products[i].date);
    }
}

void searchProduct()
{
    if(productCount == 0)
    {
        printf("No Product Records.");
        return;
    }
    int found = 0, id = 0;

    printf("To Search Enter Product Id :");
    scanf("%d", &id);

    for(int i=0; i<productCount; i++)
    {
        if(products[i].id == id)
        {
            printf("------ Found The Product -----\n");
            printf("ID\t: %d\n", products[i].id);
            printf("Name\t: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price\t: %0.2f\n", products[i].price);
            printf("Date\t: %s\n", products[i].date);

            found = 1;
            break;
            
        }
    }

    if(!found)
    {
        printf("No Product found with this Product Id %d.", id);
        return;
    }

}

void updateProduct()
{
    if(productCount == 0)
    {
        printf("No Product Records.");
        return;
    }
    int found = 0, id = 0;

    printf("To Update Enter Product Id :");
    scanf("%d", &id);

    for(int i=0; i<productCount; i++)
    {
        if(products[i].id == id)
        {
            getchar();
            printf("Enter Product Name: ");
            fgets(products[i].name, sizeof(products[i].name), stdin);
            products[i].name[strcspn(products[i].name, "\n")] = '\0';

            printf("Enter Product Quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter Product Price: ");
            scanf("%f", &products[i].price);


            printf("\n------ Successfully Update The Product -----\n");
            printf("ID\t: %d\n", products[i].id);
            printf("Name\t: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price\t: %0.2f\n", products[i].price);
            printf("Date\t: %s\n", products[i].date);

            found = 1;
            break;
            
        }
    }

    if(!found)
    {
        printf("No Product found with this Product Id %d.", id);
        return;
    }

}


void recordSale()
{
    if(saleCount >= MAX_SALE)
    {
        printf("Sales Database Full!");
        return;
    }

    int found= 0;
    struct Sale sale;
    sale.saleId = saleCount + 1;
    printf("Enter Product Id: ");
    scanf("%d", &sale.productID);

    for(int i=0; i<productCount; i++)
    {
        if(products[i].id == sale.productID)
        {
            printf("------ Found The Product -----\n");
            printf("ID: %d | ", products[i].id);
            printf("Name: %s | ", products[i].name);
            printf("Available Quantity: %d  | ", products[i].quantity);
            printf("Price: %0.2f | ", products[i].price);
            printf("Date: %s \n", products[i].date);



            printf("\nEnter Quantity to Sell: ");
            scanf("%d", &sale.quantitySold);

            if (sale.quantitySold > products[i].quantity)
            {
                printf("Error: Not enough stock available! Only %d left.\n", products[i].quantity);
                return;
            }


            sale.totalAmount = sale.quantitySold * products[i].price;

            time_t t;
            struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);
            strftime(sale.date, sizeof(sale.date), "%d-%m-%Y %H:%M", tm_info);

            products[i].quantity = products[i].quantity - sale.quantitySold;

            printf("\nSale Recorded Successfully!\n");
            printf("Total Amount: Rs%.2f\n", sale.totalAmount);
            printf("Remaining Stock: %d\n", products[i].quantity);

            found = 1;
            break;
            
        }
    }

    if(!found)
    {
        printf("Product not found with this Id %d\n",sale.productID);
        return;
    }

    sales[saleCount++] = sale;
}

void viewSales()
{
    if(saleCount == 0)
    {
        printf("No Sales Records.");
        return;
    }

    printf("------------------- Sales Records ---------------------------\n");
    printf("Sale ID\tProduct ID\tQuantity Sold\tTotal Amount\tDate\n");
    printf("-------------------------------------------------------------\n");
    for(int i=0; i<saleCount; i++)
    {
        printf("%d\t%d\t\t%d\t\t%0.2f\t%s\n",sales[i].saleId, sales[i].productID,
                sales[i].quantitySold, sales[i].totalAmount, sales[i].date);
    }
}


void saveProducts()
{
    FILE *fp = fopen("products.txt","w");
    if(fp==NULL)
    {
        printf("Error saveing the file!");
        return;
    }
    
    for(int i=0; i<productCount; i++)
    {
        fprintf(fp, "%d,%s,%d,%f,%s\n",products[i].id, products[i].name,
                    products[i].quantity, products[i].price, products[i].date);
    }
    fclose(fp);
}


void loadProducts()
{
    FILE *fp = fopen("products.txt","r");
    if(fp==NULL)
    {
        printf("No previous product data found.\n");
        return;
    }
    while(fscanf(fp, "%d,%49[^,],%d,%f,%19[^\n]\n", &products[productCount].id, products[productCount].name,
                    &products[productCount].quantity, &products[productCount].price, products[productCount].date)==5)
    {
        productCount++;
    }
    fclose(fp);
}

void saveSales()
{
    FILE *fp = fopen("sales.txt","w");
    if(fp==NULL)
    {
        printf("Error saveing the file!");
        return;
    }
    
    for(int i=0; i<saleCount; i++)
    {
        fprintf(fp, "%d,%d,%d,%f,%s\n",sales[i].saleId, sales[i].productID,
                    sales[i].quantitySold, sales[i].totalAmount, sales[i].date);
    }
    fclose(fp);
}

void loadSales()
{
    FILE *fp = fopen("sales.txt","r");
    if(fp==NULL)
    {
        printf("No previous product data found.\n");
        return;
    }
    while(fscanf(fp, "%d,%d,%d,%f,%19[^\n]\n",&sales[saleCount].saleId, &sales[saleCount].productID,
                    &sales[saleCount].quantitySold, &sales[saleCount].totalAmount, sales[saleCount].date)==5)
    {
        saleCount++;
    }
    fclose(fp);
}
