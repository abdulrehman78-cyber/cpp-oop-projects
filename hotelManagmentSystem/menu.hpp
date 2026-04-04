#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <map>

using namespace std;

// For Hotel Price Menu
class Menu
{
private:
    map<string, double> items;

public:
    Menu()
    {
        items = {{"burger", 5.99}, {"pizza", 10}, {"fries", 2.99}};
    }

    bool isExists(string name)
    {
        return items.count(name) > 0;
    }

    double getPrice(string name)
    {
        return items[name];
    }

    void display()
    {
        cout << "\n--- HOTEL MENU ---" << endl;
        for (auto const &[name, price] : items)
        {
            cout << "- " << name << " ($" << price << ")" << endl;
        }
    }
};
#endif