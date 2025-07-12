#include "member.h"

Member::Member(int memberID, string name){
    this->memberID = memberID;
    this->name = name;
    this->borrowedCount = borrowedCount;

}

int Member::getMemberID() {
    return memberID;
}

string Member::getName() {
    return name;
}

int member::getBorrowedCount() {
    return borrowedCount;
}





