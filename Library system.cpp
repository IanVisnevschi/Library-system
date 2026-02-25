#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Adding some info
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
            cout<<getName()<<" borrowed a book. Total borrowed: " << borrowedBooks << endl;

       }
       
        void returnBook() {
            if (borrowedBooks > 0) {
                borrowedBooks --;
                cout<<getName()<<" returned a book. Total borrowed: " <<borrowedBooks << endl;
            }
            else {
                cout <<getName()<<" has no books to return. \n"<<endl;
            }

       }

        void displayInfo() override {
            User::displayInfo();
            cout<<"Borrowed Books: "<<borrowedBooks<<endl;
        }
};



class Book {
private:
    int bookId;
    string  title;
    string  author;
    string status;

public:
    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        status = "Available";
    }

    int getBookId() {
        return bookId;

    }

    string getTitle() {
        return title;

    }

    string getAuthor() {
        return author;

    }

    string getStatus() {
        return status;

    }

    void setStatus(string newStatus) {
        status = newStatus;
    }

    void displayBook() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << status << endl;

    }



};

int main() {
   // Book b1(130, "48 laws of power", "Robert G");

   // cout << "initial book info: \n";
    //b1.displayBook();

    //cout << "\n Borrowing the book\n";
    //b1.setStatus("Borrowed");

    //cout << "\nUpdate Book info:\n";
    //b1.displayBook();

    //return 0;

    User u1(1,"Ian", "ian@gmail.com");
    cout<<"User created: "<< u1.getName()<<endl;
    cout<<"---------------------"<<endl;
    
    Member m1(2,"Denis","Denis@gmail.com");
    cout<<"Member created: "<< m1.getName()<<endl;

    m1.borrowBook();
    m1.borrowBook();
    return 0;


}

