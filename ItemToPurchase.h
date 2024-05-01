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
      
      void SetName(string name);
      void SetDescription(string description);
      void SetPrice(int price);
      void SetQuantity(int quantity);

      string GetName() const;
      string GetDescription() const;
      int GetPrice() const;
      int GetQuantity() const;
      
      void PrintItemCost();
      void PrintItemDescription();
   
   private:
      string itemName;
      string itemDescription;
      int itemPrice;
      int itemQuantity;
};


#endif