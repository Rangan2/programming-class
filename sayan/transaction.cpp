#include "book.h"
#include "transaction.h"
#include <iostream>
using namespace std;

void Transaction::markReturned() {
    isReturned = true;
    book.returnBook();
}

void Transaction::display() const {
    cout << "Transaction Details:\n";
    book.display();
    member.display();
    cout << "Date: " << date << "\nReturned: " << (isReturned ? "Yes" : "No") << endl;
}