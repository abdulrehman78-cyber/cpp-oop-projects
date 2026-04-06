#include <iostream>
#include "weapon.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include <fstream>
using namespace std;
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