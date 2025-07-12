#include "book.h"
#include <iostream>


int Book::getID() const{
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

bool Book::getIssuedStatus() const {
    return isIssued;
}

void Book::issue() {
    isIssued = true;
}

void Book::returnBook() {
    isIssued = false;
}

void Book::display() const {
    cout << "Book ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nStatus: " << (isIssued ? "Issued" : "Avialable") << endl; 
}