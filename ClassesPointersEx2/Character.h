/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: wiiga
 *
 * Created on September 26, 2020, 6:19 PM
 */
#include <iostream>
#include <cstdlib> 
#include <vector>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
    string name = "Sebastian";
    string job = "Mage";
    int health = 700;
    int mana = 90000;
    int level = 0;
    int exp = 0;
    vector<string> inventory;
        
public:
    Character();
    Character(string newName);
    
    // Get Functions
    string GetName()  {return name;}
    string GetJob()   {return job;}
    int    GetHealth(){return health;}
    int    GetMana()  {return mana;}
    int    GetLevel() {return level;}
    int    GetEXP()   {return exp;}
    
    // Set Function
    void SetName(string newName);
    void AddItem(string ItemName);
    void PrintItems();
    
    // Function
    void LevelUp();
    virtual ~Character();

};

#endif /* CHARACTER_H */

