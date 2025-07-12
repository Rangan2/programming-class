#include<string>

using namespace std;
class Member
{
private:
  // add member variables

  int memberID;
  string name;

  int borrowedCount;

public:
  // add member function declaration

  Member (int memberID, string name, int borrowedCount)
    int getMemberID();
    string getName();

    int getBorrowedCount();

};