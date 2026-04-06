#ifndef PLAYER_H
#define PLAYER_H
#include "character.hpp"
#include "inventory.hpp"
//Player class
class Player :public Character{
    private:
    Inventory inventory; //Composition
    double gold;
    public:
    Player(string name,float health,double attackPower,double gold)
    :Character (name,health,attackPower)
    {
        this->gold =gold;
    }

    void pickWeapon(Weapon w){
        inventory.addWeapon(w);
        if(w.getDamage()>attackPower){
            attackPower = w.getDamage();
        }
    }

    void display(){
        Character::display();
        cout << "Gold : "<<gold<<endl; 
        inventory.display();
    }

    void attack(Character &target){
        target.takeDamage(attackPower);
        cout << name << " attacks and deals " << attackPower << " damage!" << endl;
    } 

    double addGold(double amount){
        return gold = gold + amount;
    }

    double haveGold(){
        return gold;
    }
};
#endif