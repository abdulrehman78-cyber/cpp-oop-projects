#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
using namespace std;

class Member
{
private:
    int memberId;
    string name;

public:
    Member()
    {
        name = "";
        memberId = 0;
    }
    Member(string name, int id)
    {
        this->memberId = id;
        this->name = name;
    }

    string getMember()
    {
        return name;
    }

    void display()
    {
        cout << "Member Name : " << name << endl;
    }
};
#endif