#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;
class Book
{
protected:
    string name;
    string author;

public:
    Book()
    {
        name = "";
        author = "";
    };
    Book(string name, string author)
    {
        this->name = name;
        this->author = author;
    }

    void display()
    {
        cout << "Name : " << name << endl
             << "Author : " << author << endl;
    }

    string getName()
    {
        return name;
    }

    bool operator==(Book &obj)
    {
        return (obj.name == name && obj.author == author);
    }

    bool Issued = false;

    void issue()
    {
        Issued = true;
    }

    bool getIsIssued()
    {
        return Issued;
    }
    string getAuthor()
    {
        return author;
    }
    string getBook()
    {
        return name;
    }

    string issuedTo = "";

    void setIssuedTo(string memberName)
    {
        issuedTo = memberName;
    }

    string getIssuedTo()
    {
        return issuedTo;
    }
};
#endif