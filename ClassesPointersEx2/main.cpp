/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: wiiga
 *
 * Created on August 6, 2020, 7:13 AM
 */

#include <cstdlib>
#include <iostream>
#include "Character.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {   
    string n;
    
    cout << "What is your name?" << endl;
    cout << "Name: ";
    getline(cin, n);
    //cin.ignore();
    
    Character* player = new Character(n);
    
    string item;
    
    cout << "What items do you want to add to your inventory?" << endl;
    while(item != "-1"){
        getline(cin, item);
        
        player->AddItem(item);
    }
    
    cout << "Items in inventory" << endl;
    player->PrintItems();
    
    cout << "Player Name" << endl;
    cout << player->GetName() << endl;
    
    delete player;
    
    return 0;
}