#include <stdio.h>
#include <stdlib.h>
#define Min 5
#define num_of_product 3

/*These are all function prototypes that have been used in this code*/
void display_Menu(); 
void purchase_Item();
void admin_Mode();
void change_Item_Prices();
void replenish_Items();
void display_Total_Sale();
void display_Item_Availability();

/*The main idea of these global variables is to be able to use it in multiple functions without any error*/
float total_amount = 0.0;
float COSTS[num_of_product]= {1.5, 2.0, 2.5}; 
int quantities[num_of_product] = {10, 10, 10}; 
char product_names[num_of_product] = {'A', 'B', 'C'};


int main() {
    int choice;
    
    /*The do-while loop have been used to keep repeating the display menu of the vending machine.*/
   do {
        display_Menu();
        scanf("%d", &choice);
        
        if (choice == 1) {
            purchase_Item();
        } else if (choice == 2) {
            admin_Mode();
        } else if (choice == 3) {
            printf("Exiting program.\n");
            return 0;
        } else {
            printf("Invalid choice. Try a different number.\n");
        }
    } while (1);
    
    return 0;
}

/*The main purpose of this function is to display all the needed options of the vending machine.*/

void display_Menu() {
    printf("\nVending Machine Menu:\n");
    printf("1. Purchase Item for the consumer\n");
    printf("2. Admin Mode to control the vending machine\n");
    printf("3. Exit the vending machine\n");
    printf("Enter your choice: ");
}

/*The purpose of the purchase_Item function is to allow the user to purchase any of the three products available, and once the user choose the needed product,
the machine will ask the user to put 0.25 AED, 0.5 AED or 1 AED, and in the same time, the machine will return any remaining change for the user.*/

void purchase_Item() {
    printf("\nAvailable products:\n");
    for (int i = 0; i < num_of_product; i++) {
        printf("%d. Buy product %c for %.2f\n", i + 1, product_names[i], COSTS[i]);
    }
    
    /*The machine is asking the user to choose a product.*/
    int choice;
    printf("Enter your choice, or press 0 to cancel the operation : ");
    scanf("%d", &choice);
    

    if (choice == 0) {
        printf("Purchase canceled.\n");
        return;
    }
    /*The machine will ask the user to input a valid number between 0 and 4.*/
    if (choice < 1 || choice > num_of_product) {
        printf("Invalid choice. Please choose a product.\n");
        return;
    }
    
    int selected_product = choice - 1;
    float price = COSTS[selected_product];
    
    printf("You selected to buy %c for %.2f AED\n", product_names[selected_product], price);
    printf("Insert coins (1, 0.5, 0.25 AED): \n");
    
    double Entered_Amount = 0.0;
    while (Entered_Amount < price) {
        float coin;
        scanf("%f", &coin);
        
 /*If the coin choice was not (1.0, 0.5 or 0.25), the machine will let the user know that the inserted coin is invalid, 
 and it will ask the user to insert a valid coin number */

        if (coin == 1.0 || coin == 0.5 || coin == 0.25) {
            Entered_Amount += coin;
        } else {
            printf("Invalid coin. Please insert an Available coin or press 0 to Exit: ");
        }
        
        if (Entered_Amount >= price) {
            break;
        }
    }


    
    if (Entered_Amount < price) {
        printf("There is no enough fund to complete this Purchase.\n");
    } else {
       
        total_amount += price;
        quantities[selected_product]--;
        printf("You bought product %c for %.2f AED.\nThe remaining Change is: %.2f AED\n", product_names[selected_product], price, Entered_Amount - price);
        
        /*If the quantity of one product goes below 5, the machine will print a massege to the user saying that the specific product has a LOW quantity in the machine.*/
        if (quantities[selected_product] <= Min) {
            printf("Alert: The quantity of product %c is LOW!\n", product_names[selected_product]);
        }
    }
}

/*The main idea of this function is to control the vending machine by being able to change the products prices, and see the total sale amount,
 as well as seeing the availability of each product in the machine.*/

void admin_Mode(int pass) {
    pass = 0000; /*This is the password used for the admin mode.*/
    int Enter_pass;
    printf("\nEnter the admin password: ");
    scanf("%d", &Enter_pass);
    
    if (Enter_pass != pass) {
        printf("Wrong password.\n");
        return;
    }

    int admin_decision;
    do {
        printf("Admin Menu:\n");
        printf("1. Replenish Items\n");
        printf("2. Change Item Prices\n");
        printf("3. Display Total Sale\n");
        printf("4. Display Item Availability\n");
        printf("5. Exit Admin Mode\n");
        printf("Enter your choice: ");
        
        scanf("%d", &admin_decision);
        
        if (admin_decision == 1) {
            replenish_Items();
        } else if (admin_decision == 2) {
            change_Item_Prices();
        } else if (admin_decision == 3) {
            display_Total_Sale();
        } else if (admin_decision == 4) {
            display_Item_Availability();
        } else if (admin_decision == 5) {
            printf("Exit the Admin mode.\n");
            return;
        } else {
            printf("Invalid choice. Try a different number.\n");
        }
    } while (1);
}

/*The purpose of this function is to randomly */

void replenish_Items() {
    for (int i = 0; i < num_of_product; i++) {
        quantities[i] = rand() % 20 + 1;
    }
    printf("Items are replenished successfully.\n");
}
/*This function changes the cost of all displayed products in the machine.*/

void change_Item_Prices() {
    for (int i = 0; i < num_of_product; i++) {
        printf("Enter new COST for product %c: ", product_names[i]);
        scanf("%f", &COSTS[i]);
    }
    printf("Product cost has been changed.\n");
}

/*The idea of this function is to display the total cost collected by a requiest from the admin after the user purchase any product.
And it gives the admin a choice to reset the total sale amount to zero or not.*/
void display_Total_Sale() {
    printf("Total Sale Amount: %.2f AED\n", total_amount);
    char reset;
    printf("Do you want to reset the total sale amount to zero?\nIf yes, please write Y. If No, please write N: ");
    scanf(" %c", &reset);
    
    if (reset == 'Y' || reset == 'y') {
        total_amount = 0.0;
        printf("Amount has been reset to zero. Please collect the remaining money.\n\n");
    }
}
/*This function displays the remaing quantity of each product, after the user purchase any product.*/
void display_Item_Availability() {
    printf("Item Availability:\n");

    for (int i = 0; i < num_of_product; i++) {
        printf("%c: %d\n", product_names[i], quantities[i]);
    }

}