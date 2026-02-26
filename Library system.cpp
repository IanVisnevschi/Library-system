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

class Librarian : public User {
public:

    Librarian(int userId, string userName, string userEmail) : User(userId, userName, userEmail) {}

    void addBook(vector<Book>& books) {
        int id;
        string title;
        string author;

        cout << "Enter Book ID: ";
        cin >> id;

        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        Book newBook(id, title, author);
        books.push_back(newBook);

        cout << "Book added successfuly\n";

    }
    void removeBook(vector<Book>& books) {
        int id;
        cout << "Enter Book ID to remove: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].getBookId() == id) {
                books.erase(books.begin() + i);
                cout << "Book removed successfuly\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void displayInfo()override {
        User::displayInfo();
        cout << "Role: Librarian\n";
    }


};











int main() {

    vector<Book> books;
    Librarian lib1(1, "Jacob", "Jacob@gmail.com");

    lib1.addBook(books);

    cout << "\nAll Books:\n";
    for (int i = 0; i < books.size(); i++) {
        books[i].displayBook();

    }
    return 0;


}