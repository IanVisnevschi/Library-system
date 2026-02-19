#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User{
private:
    int id;
    string name;
    string email;
    
public:
   User(int userId, string userName, string userEmail){
      id = userId;
      name = userName;
      email = userEmail;
   }


   int getId(){
    return id;
   }

   string getName(){
    return name;
   }

   string getEmail(){
    return email;
   }

   virtual void displayInfo() {
       cout<<"User ID: " <<id<<endl;
       cout<<"Name: "<< name << endl;
       cout<<"Email: "<< email << endl;
       }

};


class Member : public User {
    private:
       int borrowedBooks;

    public:
        Member(int userId, string userName, string userEmail)
            : User(userId, userName, userEmail) {
            borrowedBooks = 0;
       }

        void borrowBook() {
            borrowedBooks++;
            cout<<getName()<<"borrowed a book. Total borrowed: " << borrowedBooks << endl;

       }
       
        void returnBook() {
            if (borrowedBooks > 0) {
                borrowedBooks --;
                cout<<getName()<<"returned a book. Total borrowed: " <<borrowedBooks << endl;
            }
            else {
                cout <<getName()<<"has no books to return. \n"<<endl;
            }

       }

        void displayInfo() override {
            User::displayInfo();
            cout<<"Borrowed Books: "<<borrowedBooks<<endl;
        }
};


int main() {
    Member m1(67,"Ian","Ian@gmail.com");

    m1.displayInfo();
    m1.borrowBook();
    m1.borrowBook();
    m1.returnBook();
    m1.displayInfo();

    return 0;
}

