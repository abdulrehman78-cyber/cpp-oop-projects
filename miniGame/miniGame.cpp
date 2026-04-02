#include<bits/stdc++.h>
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
//Inventory class
class Inventory{
    private:
    Weapon weapons[5];
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
//Player class
class Player :public Character{
    private:
    Inventory inventory;
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
int main(){
    Weapon w1("Ak-47",55);    
    Weapon w2("Uzi",25);    
    Weapon w3("Sniper",90); 

    Player p1("Hero",100.0,25,10);
    Enemy e1("Goblin",100.0,50,50);

    
    p1.pickWeapon(w1);
    p1.pickWeapon(w2);
    p1.pickWeapon(w3);
    p1.display();
    
    while(p1.getHealth()>0 && e1.getHealth()>0){ 
        p1.attack(e1);  
        if(e1.getHealth()<=0) break;
        e1.attack(p1);
    }
    if(p1.getHealth()<=0) cout<<"Goblin won!!"<<endl;
    else if(e1.getHealth()<=0) cout<<"Hero won!!"<<endl;

    p1.addGold(e1.getGoldReward());
    p1.display();

    ofstream save("save.txt");
    save <<"Player Name : "<<p1.getName()<<endl
    <<"Have Gold : " <<p1.haveGold()<<endl
    <<"Health : "<<p1.getHealth()<<endl;
    save.close();
    return 0;
}