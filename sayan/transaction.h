#include "book.h"
#include "member.h"
#include <string>
using namespace std;

class Transaction {
 private:
   // add member variables
   Book book;
   Member member;
   string date;
   bool isReturned;

 public:
    // add member function declaration
    void markReturned();
    void display() const;
};