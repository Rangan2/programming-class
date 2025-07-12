#include<string>
using namespace std;

class Transaction
{
private:
  // add member variables
  int transactionID;
  int memberID;
  int bookID;
  string type;  // "borrow" or "return"
  string date;
public:
  // add member function declaration
  Transaction(int transactionID, int memberID, int bookID, string type, string date);
  int getTransactionID();
  int getMemberID();
  int getBookID();
  string getType();
  string getDate();
  
};