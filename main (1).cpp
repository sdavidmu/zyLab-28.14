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


