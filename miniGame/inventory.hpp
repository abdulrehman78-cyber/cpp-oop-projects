#ifndef INVENTORY_
#define INVENTORY_H
#include <iostream>
#include "weapon.hpp"
using namespace std;
//Inventory class
class Inventory{
    private:
    Weapon weapons[5]; //Composition
    int count = 0;
    public:
    
    void addWeapon(Weapon w){
        if(count<5){
            weapons[count] = w;
            count++;           
        }
    }

    void display(){
        cout<<"List of Weapons : "<<endl;
        for(int i = 0;i<count;i++){
            weapons[i].display();
            cout<<endl;
        }
    }
};
#endif