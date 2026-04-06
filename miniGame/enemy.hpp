#ifndef ENEMY_H
#define ENEMY_H
#include "character.hpp"
//Enemy class
class Enemy : public Character{
    private:
    double goldReward;
    public:
    Enemy(string name,float health,double attackPower,double goldReward)
    :Character(name,health,attackPower)
    {
        this->goldReward = goldReward;
    }

    void display(){
        Character::display();
        cout<<" Reward : "<<goldReward<<endl;
    }

    void attack(Character &target){
        target.takeDamage(attackPower);
        cout << name << " attacks and deals " << attackPower << " damage!" << endl;
    }

    double getGoldReward(){
        return goldReward;
    }
};
#endif