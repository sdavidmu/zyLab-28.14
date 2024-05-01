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
    bool found = false;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() == name) {
            found = true;

            cartItems[i].SetName("none");
            cartItems[i].SetPrice(0);
            cartItems[i].SetQuantity(0);
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() == item.GetName()) {
            if (cartItems[i].GetDescription() != "none" && cartItems[i].GetPrice()!= 0 && cartItems[i].GetQuantity() != 0) {

                cartItems[i].SetDescription(item.GetDescription());
                cartItems[i].SetName(item.GetName());
                cartItems[i].SetQuantity(item.GetQuantity());

            }
            else {
                cout << "Item not found in cart. Nothing Modified." << endl;
            }
        }
    }
}

int ShoppingCart::GetNumItemsInCart() {
    int count = 0;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() != "none" && cartItems[i].GetPrice()!= 0 && cartItems[i].GetQuantity() != 0) {
            count++;
        }
    }
    return count;
}

double ShoppingCart::GetCostOfCart() {
    double total = 0;
    for (int i = 0; i < cartItems.size(); i++) {
        total += cartItems[i].GetPrice();
    }

    return total;
}

void ShoppingCart::PrintTotal() {
    double total = 0;
    double value = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() != "none" && cartItems[i].GetPrice()!= 0 && cartItems[i].GetQuantity() != 0) {
            total++;
        }
    }
    if (total != 0) {
    cout << "Number of items: " << total << endl;
    cout << endl;
    }
    else {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() != "none" && cartItems[i].GetPrice()!= 0 && cartItems[i].GetQuantity() != 0) {
            double finalProductSpending = 0;
            finalProductSpending = cartItems[i].GetQuantity() * cartItems[i].GetPrice();
            cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = " << finalProductSpending<< endl;
            value += finalProductSpending;
        }
    }

    cout << endl;
    cout << "Total: $" << value << endl;
}

void ShoppingCart::PrintDescriptions() {
    double total = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems[i].GetName() != "none" && cartItems[i].GetPrice()!= 0 && cartItems[i].GetQuantity() != 0) {
            total++;
        }
    }
    if (total == 0) {
    cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (int i = 0; i < cartItems.size(); i++) {
            if (cartItems[i].GetName() != "none") {
                cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
            }
        }
    }
}


