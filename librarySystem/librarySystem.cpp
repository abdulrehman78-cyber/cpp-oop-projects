#include<bits/stdc++.h>
using namespace std;
class Book{
    protected:
    string name;
    string author;
    public:
    Book(){
        name = "";
        author = "";
    };
    Book(string name,string author){
        this->name = name;
        this->author = author;
    }

    void display(){
        cout<<"Name : "<<name<<endl<<
        "Author : "<<author<<endl;
    }

    string getName(){
        return name;
    }

    bool operator==(Book &obj){
        return  (obj.name == name && obj.author == author); 
    }

    bool Issued = false;

    void issue(){
        Issued = true;
    }

    bool getIsIssued(){
        return Issued;
    }
    string getAuthor(){
        return author;
    }
    string getBook(){
        return name;
    }

    string issuedTo = "";

    void setIssuedTo(string memberName){
        issuedTo = memberName;
    }

    string getIssuedTo(){
        return issuedTo;
    }
    
};
class Member{
    private:
    int memberId;
    string name;
    public:
    Member(){
        name = "";
        memberId  = 0;
    }
    Member(string name,int id){
        this->memberId = id;
        this->name = name;
    }

    string getMember(){
        return name;
    }
    

    void display(){
        cout<<"Member Name : "<<name<<endl;
    }

};
class Library{
    private:
    Member record[100]; //composition has a relationship
    int memCount = 0;
    Book list[100]; //composition has a relationship
    int bookCount = 0;
    public:
    //ADDING BOOK
    void addBook(Book &obj){       
            list[bookCount] = obj;
            bookCount++;
    } 
    //CHECKING AVAILABILITY
    bool isAvailable(Book obj){
        for(int i = 0;i<bookCount;i++){
          if(list[i] == obj)
            return true; 
        }
        return false;
    }
    //DISPLAYING BOOK
    void displayBook(){
        for(int i = 0;i < bookCount;i++){
            list[i].display();
            cout<<endl;
        }
    }
    //Adding MEMBERS
    void addMember(Member &m){
        record[memCount] = m; 
        memCount ++;
    }
    //Display MEMBERS
    void displayMembers(){
        for(int i = 0;i < memCount;i++){
            record[i].display();
            cout<<endl;
        }
    }

    //CHECKING IS ISSUED 
    bool isIssued(Book &b){
        if(b.getIsIssued()) return true;
        return false;
    }

    
    //issue a book
    void issuebook(Member &m,Book &b){
        for(int i = 0;i<bookCount;i++){
            if(list[i] == b && !list[i].getIsIssued()){         
                cout<<"Book issued to "<<m.getMember();
                list[i].issue();
                list[i].setIssuedTo(m.getMember()) ;
                return;
            }
        }   
        cout<<"Book not Available!!"<<endl;
    }

    //Saving files
    void saveToFiles(){
        ofstream file("IssuedBooks.txt");
        for(int i = 0;i<bookCount;i++){
            if(list[i].getIsIssued()){
                file<<"Book Name : "<<list[i].getBook()
                <<" Isseued To : "<<list[i].getIssuedTo()<<endl
                <<"Author : "<<list[i].getAuthor()<<endl;
            } 
        }
        file.close();
    }
};
 
int main(){

    Book b1("CPP","ABUD00");
    Book b2("RR","ABUD00");
    Book b3("Harry Potter","ABUD00");
  

    Library l;
    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);

    Book search("RR","ABUD00");

    if(l.isAvailable(search)) cout << "Available" << endl;
    else cout << "Not available" << endl;

    Member m1("Sunny Malton",1);
    l.addMember(m1);
    l.issuebook(m1,b1);

    Member m2("Shoiab",2);
    l.addMember(m2);
    cout<<endl;
    l.displayMembers();
    l.issuebook(m2,b2);

    l.saveToFiles();

    
    return 0;
}