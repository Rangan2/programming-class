#include "member.h"

#include <iostream>
using namespace std;
 
int Member::getID() const {
    return id;
 }
 
 string Member::getName() const {
    return name;
 }

 void Member::display() const {
    cout << "Member ID: " << id << "\nName: " << name << endl;
 }