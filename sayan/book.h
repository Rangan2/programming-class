#include <string>
using namespace std;
class Book {
 private:
   // add member variables
   int id;
   string title;
   string author;
   bool isIssued;

 public:
  
  
    // add member function declaration
    int getID() const;
    string getTitle() const;
    string getAuthor() const;
    bool getIssuedStatus() const;

    void issue();
    void returnBook();
    void display() const;
};