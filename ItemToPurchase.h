#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H


#include <string>
using namespace std;

class ItemToPurchase {
   
   public:
      ItemToPurchase();
      ItemToPurchase(string name="none", string description="none", int price=0, int quantity=0) {
         itemName = name;
         itemPrice = price;
         itemQuantity = quantity;
      }
      
      void SetName(string name) {
         itemName = name;
      }
      void SetDescription(string description) {
         itemDescription = description;
      }
      void SetPrice(int price) {
         itemPrice = price;
      }
      void SetQuantity(int quantity) {
         itemQuantity = quantity;
      }
      
      string GetName() const {
         return itemName;
      }
      string GetDescription() const {
         return itemDescription;
      }
      int GetPrice() const {
         return itemPrice;
      }
      int GetQuantity() const {
         return itemQuantity;
      }
      
      void PrintItemCost() {
         cout << itemName << ": $" << itemPrice << endl;
      }
      void PrintItemDescription(){
         cout << itemName << ": $" << itemDescription << endl;
      }
   
   private:
      string itemName;
      string itemDescription;
      int itemPrice;
      int itemQuantity;
};


#endif