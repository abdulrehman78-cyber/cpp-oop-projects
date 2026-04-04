#ifndef WAITER_H
#define WAITER_h

#include "order.hpp"
#include "menu.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <memory>
using namespace std;

// Controller
class Waiter
{
private:
    Menu menu;

public:
    string toLower(string s)
    {

        for (int i = 0; i < s.length(); i++)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    }
    void takeOrder()
    {
        menu.display();
        string name;
        int quantity, choice;
        cout << "Please Enter Item You like!!!" << endl;
        cin >> name;

        name = toLower(name);
        double itemPrice = menu.getPrice(name);

        if (menu.isExists(name) == 0)
        {
            cout << "Sorry this Item is Not Available right now !!!" << endl;
            return;
        }

        cout << "Enter the Quantity!!!" << endl;
        cin >> quantity;

        cout << "1. Dine-In" << endl
             << "2. Delivery" << endl
             << "Choice :" << endl;
        cin >> choice;

        std::unique_ptr<Order> current = nullptr;
        if (choice == 1)
        {
            int tableNum = 0;
            cout << "On which Table ??" << endl;
            cin >> tableNum;
            current = std::make_unique<DineInOrder>(name, quantity, itemPrice, tableNum);
        }
        else
        {
            string address;
            cout << "Please Enter the Your Address" << endl;
            cin.ignore();
            getline(cin, address);
            current = std::make_unique<DeliveryOrder>(name, quantity, address, itemPrice);
        }

        if (current)
        {
            current->order();
            double billAmount = current->calculateTotal();
            cout << "Your Bill: $" << billAmount << endl;

            ofstream file("order.txt", ios::app);
            if (file.is_open())
            {
                file << name << " | Quantity: " << quantity << " | Bill: " << billAmount << endl;
                file << "-----------------------------" << endl;
                file.close();
                cout << "Order saved to order.txt successfully!" << endl;
            }
        }
    }
    void getTotalRev()
    {
        Order ::showTotalRevenue();
    }
};

#endif