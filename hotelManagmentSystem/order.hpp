#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

using namespace std;

class Order
{
protected:
  static double totalRevenue;
  string itemName;
  double price;
  int quantity;

public:
  Order(string itemName, int quantity, double price)
  {
    this->itemName = itemName;
    this->quantity = quantity;
    this->price = price;
  }

  void display()
  {
    cout << quantity << " : " << itemName << " have ordered " << endl;
  }
  virtual void order() = 0;
  virtual double calculateTotal() = 0;
  virtual ~Order() {}

  static void showTotalRevenue()
  {
    cout << "--------------------------" << endl;
    cout << "TOTAL HOTEL REVENUE TODAY: $" << totalRevenue << endl;
    cout << "--------------------------" << endl;
  }
};

class DineInOrder : public Order
{
private:
  int tableNum;

public:
  DineInOrder(string itemName, int quantity, double price, int tableNum)
      : Order(itemName, quantity, price)
  {
    this->tableNum = tableNum;
  }
  void order()
  {
    cout << itemName << " is Placed at table :" << tableNum << endl;
  }

  double calculateTotal() override
  {
    double total = price * quantity;
    totalRevenue = totalRevenue + total;
    return total;
  }
};
class DeliveryOrder : public Order
{
private:
  string address;
  const double FIXED_SHIPPING_FEE = 3.50;

public:
  DeliveryOrder(string itemName, int quantity, string address, double price)
      : Order(itemName, quantity, price)
  {
    this->address = address;
  }

  void order()
  {
    cout << itemName << " is Placed at address :" << address << endl;
  }

  double calculateTotal() override
  {
    double total = price * quantity + FIXED_SHIPPING_FEE;
    totalRevenue = totalRevenue + total;
    return total;
  }
};

#endif