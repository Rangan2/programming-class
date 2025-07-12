#include "transaction.h"

Transaction::Transaction(int transactionID, int memberID, int bookID, string type, string date) {
    this->transactionID = transactionID;
    this->memberID = memberID;
    this->bookID = bookID;
    this->type = type;
    this->date = date;
}

int Transaction::getTransactionID() {
  return transactionID;
}

int Transaction::getMemberID() {
  return memberID;
}

int Transaction::getBookID() {
  return bookID;
}

string Transaction::getType() {
  return type;
}

string Transaction::getDate() {
  return date;
}