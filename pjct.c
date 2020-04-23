/*Simplified billing system*/
/*the customer accounts are maintained as an external array*/

#include<stdio.h>
#include<string.h>

void readinput(int i);
void writeoutput(int i);

struct date
{
    int month;
    int day;
    int year;
};

struct account
{
    char name[100];
    char street[100];
    char city[100];
    int acc_no;
    char acc_type;
    float oldbalance;
    float newbalance;
    float payment;
    struct date lastpayment;
} customer[100];

void main()
{
    int i,n;
    printf(" CUSTOMER BILLING SYSTEM\n");
  
    printf("==========================");
      printf("\n\nNUMBER OF CUSTOMERS: ");
    scanf("%d",&n);

    for(i=0; i<n ; i++)
    {
        readinput(i);

        if(customer[i].payment > 0)
        customer[i].acc_type = (customer[i].payment < 0.1 * customer[i].oldbalance) ? '0' : 'C';
        else
        customer[i].acc_type =( customer[i] . oldbalance > 0) ? 'D' : 'C' ;

        customer[i].newbalance = customer[i].oldbalance - customer[i].payment;
    }
    for(i=0; i<n ; i++)
    writeoutput(i);
}

void readinput(int i)
/*read input data and update record for each customer*/
{
    printf("\nCustomer no. %d\n", i+1);
    printf("   Name:  ");
    scanf(" %[^\n]",customer[i].name);
    printf("   Street:  ");
    scanf(" %[^\n]", customer[i].street);
    printf("   City:  ");
    scanf(" %[^\n]", customer[i].city);
    printf("   Account number:  ");
    scanf("%d",&customer[i].acc_no);
    printf("   Previous Blance:  ");
    scanf("%f",&customer[i].oldbalance);
    printf("   Curent Payment:  ");
    scanf("%f",&customer[i].payment);
    printf("   Payment date:  "); /* dd/mm/yy */
    scanf("%d/%d/%d",&customer[i].lastpayment.day ,&customer[i].lastpayment.month ,&customer[i].lastpayment.year);
}

void writeoutput(int i)
 
/* display information of each customer*/
{
    printf("\nName: %s",customer[i].name);
    printf("     Account Number: %d\n", customer[i].acc_no);
    printf("Street: %s\n",customer[i].street);
    printf("City:   %s\n\n",customer[i].city);
    printf("Old Balance: %7.2f",customer[i].oldbalance);
    printf("     Current Payment: %7.2f",customer[i].payment);
    printf("     New Balance: %7.2f\n\n", customer[i].newbalance);
    printf("Account Status: ");
     switch(customer[i].acc_type)
     {
         case 'C' :
         printf("CURRENT\n\n");
         break;

         case 'O' :
         printf("OVERDUE\n\n");
         break;

         case 'D' :
         printf("DQNT\n\n");

         default :
         printf("ERROR\n\n");

     }
     
 }
 
