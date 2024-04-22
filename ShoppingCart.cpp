#include <iostream>
using namespace std;
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() == name) {
            // remove element and maybe shift array 
        }
    }
}
