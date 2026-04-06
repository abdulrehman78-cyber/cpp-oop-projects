#ifndef WEAPON_H
#define WEOPON_H
//Weapon class
class Weapon{
    private:
    string name;
    double damage;
    public:
    Weapon(){
        name = "";
        damage = 0;
    }
    Weapon(string name,double damage){
        this->name = name;
        this->damage = damage;
    }
    void display(){
        cout<<"Name of Weapon : "<<name<<" Damage of this weapon : "<<damage<<endl;
    }

    double getDamage(){
        return damage;
    }
};
#endif