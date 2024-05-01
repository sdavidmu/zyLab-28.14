#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu()
void ExecuteMenu(char option, ShoppingCart& theCart);
int main() {
   string customerName, todayDate;
   cout<<"Enter Customer Name:"<<endl;
   getline(cin, customerName);
   cout<<"enter todays date"<<endl;
   getline(cin, todayDate);
      //output customer name and date
      cout<<endl<<"Customer Name:" <<customerName<<endl;
      cout<<"Todays Date:"<<todayDate<<endl;
   //create and object type of shopping cart
   ShoppingCart cart (customerName, todayDate);
   char option;

   do{
      cout<<"Choose an option:"<<endl;
      cin>>option
      cin.ignore();
      //execute the chosen option 
      ExecuteMenu(option, cart);
      cout<<endl;
   }while (option !='q');
   
   return 0;
}
void PrintMenu(){
   //print the menu
cout<<"n/Menu"<<endl;
cout<<"a- add item to cart"<<endl;
cout<<"d- remove item from cart"<<endl;
cout<<"c-change item quanity"<<endl;
cout<<"i-output items from descriptions"<<endl;
cout<<"o-output shopping cart"<<endl;
cout<<"q- quit"<<endl;
}
void ExecuteMenu(char option, ShoppingCart& theCart) {
    string name, description;
    double price;
    int quantity;
    
    switch(option) {
        case 'a':
            // Add item to cart
            cout << "\nADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            cin >> price;
            cout << "Enter the item quantity:" << endl;
            cin >> quantity;
            theCart.AddItem(ItemToPurchase(name, description, price, quantity));
            break;
        
        case 'd':
            // Remove item from cart
            cout << "\nREMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            cin.ignore(); // Ignore the newline character
            getline(cin, name);
            theCart.RemoveItem(name);
            break;
        
        case 'c':
            // Change item quantity
            cout << "\nCHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the new quantity:" << endl;
            cin >> quantity;
            theCart.ModifyItem(ItemToPurchase(name, "", 0, quantity));
            break;
        
        case 'i':
            // Output items' descriptions
            cout << "\nOUTPUT ITEMS' DESCRIPTIONS" << endl;
            cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
            cout << "\nItem Descriptions" << endl;
            theCart.PrintDescriptions();
            break;


