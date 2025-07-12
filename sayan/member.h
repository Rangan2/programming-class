#include <string>
using namespace std;

class Member {
 private:
   // add member variables
   int id;
   string name;
 public:
    // add member function declaration
    int getID() const;
    string getName() const;
    void display() const;
    
};