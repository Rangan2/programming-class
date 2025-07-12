/*Source file (.cpp)
Defines the functions declares in the header files what they do.*/
#include "book.h"

// constructor definition for book class
Book::Book(int id, string name, string author, string ISBN, string category) {
  this->id = id;
  this->name = name;
  this->author = author;
  this->ISBN = ISBN;
  this->isAvailable = true;
  this->category = category;
}
 /*what is Book:: means ?
 It is the scope resolution operator ::
 when we write  Book::function name it means This function is a member of the Book class.*/


int Book::getID() {      // int Book::getID() means getID() function is inside in the Book class  
  return id;
}

string Book::getTitle() {
  return name;
}

string Book::getAuthor() {
  return author;
}

string Book::getISBN() {
  return ISBN;
}

bool Book::getAvailability() {
  return isAvailable;
}

string Book::searchCategory() {
  return category;
}

void Book::borrowBook() {
  isAvailable = false;
}

void Book::returnBook() {
  isAvailable = true;
}
