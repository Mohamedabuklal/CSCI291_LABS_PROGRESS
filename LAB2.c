#include <stdio.h>
#include <stdlib.h>

void display_Menu();
void purchase_Item();
void admin_Mode();
/*void replenish_Items();
void change_Item_Prices();
void display_Total_Sale();
void display_Item_Availability();*/

const double Min = 8.0; 
const int num_of_product = 3;
const double PRICES[num_of_product]= {1.0, 1.5, 2.0}; 
const char product_names[num_of_product] = {'A', 'B', 'C'};


int pass = 0000; 
double total_amount = 0.0;
int quantities[num_of_product] = {10, 10, 10}; 


int main() {
    int choice;
    
    while (1) {
        display_Menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                purchase_Item();
                break;
            case 2:
                admin_Mode();
                break;
            case 3:
                printf("Exit the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Choose another number.\n");
        }
    }
    
    return 0;
}



void display_Menu() {
    printf("\nVending Machine Menu:\n");
    printf("1. Purchase Item\n");
    printf("2. Admin Mode\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}





void purchase_Item() {
    printf("\nAvailable Items:\n");
    for (int i = 0; i < num_of_product; i++) {
        printf("%d. Buy %c for %.2lf\n", i + 1, product_names[i], PRICES[i]);
    }
    
    int choice;
    printf("Enter your choice, or press 0 to cancel: ");
    scanf("%d", &choice);
    
    if (choice == 0) {
        printf("Purchase canceled.\n");
        return;
    }
    
    if (choice < 1 || choice > num_of_product) {
        printf("Invalid choice. Please try again.\n");
        return;
    }
    
    int selected_product_index = choice - 1;
    double price = PRICES[selected_product_index];
    
    printf("You selected to buy %c for %.2lf\n", product_names[selected_product_index], price);
    printf("Insert coins (1, 0.5, 0.25 Dh) to cover the price:\n");
    
    double amount_inserted = 0.0;
    while (amount_inserted < price) {
        double coin;
        scanf("%lf", &coin);
        
        if (coin == 1.0 || coin == 0.5 || coin == 0.25) {
            amount_inserted += coin;
        } else {
            printf("Invalid coin. Please insert a valid coin or press 0 to cancel: ");
        }
        
        if (amount_inserted >= price) {
            break;
        }
    }
    
    if (amount_inserted < price) {
        printf("Purchase canceled due to insufficient funds.\n");
    } else {
       
        total_amount += price;
        quantities[selected_product_index]--;
        printf("You bought %c for %.2lf. Change: %.2lf Dh\n", product_names[selected_product_index], price, amount_inserted - price);
        
        if (quantities[selected_product_index] <= Min) {
            printf("Alert: Low quantity of product %c in the vending machine!\n", product_names[selected_product_index]);
        }
    }
}



void admin_Mode() {
    int Enter_pass;
    printf("\nEnter admin password: ");
    scanf("%d", &Enter_pass);
    
    if (Enter_pass != pass) {
        printf("Incorrect password.\n");
        return;
    }

    int admin_choice;
    while (1) {
        printf("\nAdmin Mode Menu:\n");
        printf("1. Replenish Items\n");
        printf("2. Change Item Prices\n");
        printf("3. Display Total Sale\n");
        printf("4. Display Item Availability\n");
        printf("5. Exit Admin Mode\n");

        printf("Enter your choice: ");
        scanf("%d", &admin_choice);

        switch (admin_choice) {
            case 1:
               // replenishItems();
                break;
            case 2:
                //changeItemPrices();
                break;
            case 3:
                //displayTotalSale();
                break;
            case 4:
                //displayItemAvailability();
                break;
            case 5:
                printf("Exiting Admin Mode.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

}