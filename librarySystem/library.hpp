#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <vector>
#include <fstream>
#include "book.hpp"
#include "member.hpp"
using namespace std;
class Library
{
private:
    vector<Member> record; // composition has a relationship
    vector<Book> list; // composition has a relationship

public:
    // ADDING BOOK
    void addBook(Book &obj)
    {
        list.push_back(obj);
    }
    // CHECKING AVAILABILITY
    bool isAvailable(Book obj)
    {
        for (int i = 0; i <list.size(); i++)
        {
            if (list[i] == obj)
                return true;
        }
        return false;
    }
    // DISPLAYING BOOK
    void displayBook()
    {
        for (int i = 0; i < list.size(); i++)
        {
            list[i].display();
            cout << endl;
        }
    }
    // Adding MEMBERS
    void addMember(Member &m)
    {
        record.push_back(m);
    }
    // Display MEMBERS
    void displayMembers()
    {
        for (int i = 0; i < record.size(); i++)
        {
            record[i].display();
            cout << endl;
        }
    }

    // CHECKING IS ISSUED
    bool isIssued(Book &b)
    {
        if (b.getIsIssued())
            return true;
        return false;
    }

    // issue a book
    void issuebook(Member &m, Book &b)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i] == b && !list[i].getIsIssued())
            {
                cout << "Book issued to " << m.getMember();
                list[i].issue();
                list[i].setIssuedTo(m.getMember());
                return;
            }
        }
        cout << "Book not Available!!" << endl;
    }

    // Saving files
    void saveToFiles()
    {
        ofstream file("IssuedBooks.txt");
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].getIsIssued())
            {
                file << "Book Name : " << list[i].getBook()
                     << " Isseued To : " << list[i].getIssuedTo() << endl
                     << "Author : " << list[i].getAuthor() << endl;
            }
        }
        file.close();
    }
};
#endif