#include "library.hpp"
using namespace std;
int main()
{

    Book b1("CPP", "ABUD00");
    Book b2("RR", "ABUD00");
    Book b3("Harry Potter", "ABUD00");

    Library l;
    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);

    Book search("RR", "ABUD00");

    if (l.isAvailable(search))
        cout << "Available" << endl;
    else
        cout << "Not available" << endl;

    Member m1("Sunny Malton", 1);
    l.addMember(m1);
    l.issuebook(m1, b1);

    Member m2("Shoiab", 2);
    l.addMember(m2);
    cout << endl;
    l.displayMembers();
    l.issuebook(m2, b2);

    l.saveToFiles();

    return 0;
}