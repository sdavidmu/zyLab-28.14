#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu(); 
void ExecuteMenu(char option, ShoppingCart& theCart);

int main() {
    string customerName, todayDate;
    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, todayDate);
    cout << endl << "Customer name: " << customerName << endl;
    cout << "Today's date: " << todayDate << endl;
    cout << endl;

    ShoppingCart cart(customerName, todayDate);
    char option;

   
    
    
    do {
      option = 'y';
      PrintMenu();
      while (option != 'a' && option != 'd' && option != 'c' && option != 'i' && option != 'o' && option != 'q') {
      cout << "Choose an option:" << endl;
      cin >> option;
      cin.ignore(); 
    }
    if (option != 'q') {
        ExecuteMenu(option, cart);
    }
        

    } while (option != 'q');

    return 0;
}

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    string name, description;
    double price;
    int quantity;

    switch(option) {
        case 'a':
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            cin >> price;
            cin.ignore();
            cout << "Enter the item quantity:" << endl;
            cin >> quantity;
            cin.ignore();
            cout << endl;
            theCart.AddItem(ItemToPurchase(name, description, price, quantity));
            break;
        case 'd':
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, name);
            theCart.RemoveItem(name);
            break;
        case 'c':
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the new quantity:" << endl;
            cin >> quantity;
            cin.ignore();
            theCart.ModifyItem(ItemToPurchase(name, "", 0, quantity));
            break;
        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
            cout << "\nItem Descriptions" << endl;
            theCart.PrintDescriptions();
            break;
         case 'o':
            cout << "OUTPUT SHOPPING CART" << endl;
            cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
            cout << "Number of Items: " << theCart.GetNumItemsInCart() << endl;
            cout << endl;
            theCart.PrintDescriptions();
            cout << endl;
            cout << "Total: $" << theCart.GetCostOfCart() << endl;
            cout << endl;
            break;
    }
}
