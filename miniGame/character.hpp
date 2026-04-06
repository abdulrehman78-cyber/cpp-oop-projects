#ifndef CHARACTER_H
#define CHARACTE_H
#include <iostream>
using namespace std;
//Base Class
class Character{
    protected:
    string name;
    float health;
    double attackPower;
    public:
    Character(string name,float health,double attackPower){
        this->name = name;
        this->health = health;
        this->attackPower = attackPower;
    }

    void display(){
        cout<<"Name : "<<name<<
        " Attack Power : "<<attackPower<<
        " Health : "<<health<<endl;
    }

    virtual void attack(Character &target) = 0;

    void takeDamage(double damage){
        health = health - damage;
    }

    string getName(){
        return name;
    }

    double getHealth(){
        return health;
    }

};
#endif