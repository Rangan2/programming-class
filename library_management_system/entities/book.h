/*Header file (.h)
declares what functions exist (signature only).*/
#include <string>

using namespace std;

class Book {
 private:
  int id;
  string name;
  string author;
  string ISBN;
  bool isAvailable;
  string category;

 public:
  // constructor 
  Book(int id, string name, string author, string ISBN, string category);

  int getID();
  string getTitle();
  string getAuthor();
  string getISBN();
  bool getAvailability();

  string searchCategory();

  void borrowBook();
  void returnBook();
};
