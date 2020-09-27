/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: wiiga
 * 
 * Created on September 26, 2020, 6:19 PM
 */

#include "Character.h"

Character::Character() {
}

Character::Character(string newName) {
    this->name = newName;
}

Character::~Character() {
}

void Character::LevelUp() {
    this->level += 1;
}

void Character::SetName(string newName) {
    this->name = newName;
}

void Character::AddItem(string ItemName){
    inventory.push_back(ItemName);
}

void Character::PrintItems(){
    for(int i = 0; i < inventory.size(); i++) {
        cout << inventory[i] << endl;
    }
}
