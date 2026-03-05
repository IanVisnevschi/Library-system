#include <iostream>
#include <vector>
#include <string>
using namespace std;

int currentDay = 0;

//Adding some info
class User{
protected:
    int id;
    string name;
    string email;
    
public:
   User(int i, string n, string e){
      id = i;
      name = n;
      email = e;
   }


   int getId(){
    return id;
   }


   virtual void displayInfo() {
       cout<<"ID: " <<id<<endl;
       cout<<"Name: "<< name << endl;
       cout<<"Email: "<< email << endl;
       }

};



class Book {
private:
    int bookId;
    string  title;
    string  author;
    string status;
    int borrowedDay;
    int reservedDay;

public:
    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        status = "Available";
        borrowedDay = -1;
        reservedDay = -1;
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

    int getBorrowedDay() {
        return borrowedDay;
    }

    int getReservedDay() {
        return reservedDay;
    }

    void setStatus(string s) {
        status = s;
    }

    void setBorrowedDay(int d) {
        borrowedDay = d;

    }

    void setReservedDay(int d) {
        reservedDay = d;
    }

    void displayBook() {
        cout << "Book ID: " << bookId
            << "| Title: " << title
            << "| Author: " << author
            << "| Status: " << status << endl;
    }


};


class Member : public User {
    private:
       int borrowedCount;

    public:
        Member(int i, string n, string e)
            : User(i,n,e) {
            borrowedCount = 0;
       }

        void searchBook(vector<Book>& books) {
            string title;
            cin.ignore();
            cout<<"Enter title: ";
            getline(cin,title);

            for (int i = 0;i < books.size();i++) {
                if (books[i].getTitle() == title) {
                    books[i].displayBook();
                    return ;
                }
            }
            cout<<"Book not found.\n";


       }

        void borrowBook(vector<Book>& books, int limit) {
            if (borrowedCount >= limit) {
                cout<<"you reached borrowing limit.\n";
                return;
          }
           int id;
           cout<<"Enter book ID: ";
           cin>>id;

           for (int i = 0; i < books.size();i++) {
               if (books[i].getBookId() == id && books[i].getStatus() == "Available") {

                books[i].setStatus("Borrowed");
                books[i].setBorrowedDay(currentDay);
                borrowedCount++;
                cout<<"Book borrowed.\n";
                return;
                }
           }
           cout<<"Book not available.\n";
        }
            
       
        void returnBook(vector<Book>& books) {
            int id;
            cout<<"Enter Book ID: ";
            cin>>id;

            for(int i=0;i<books.size();i++){
              if(books[i].getBookId()==id && books[i].getStatus()== "Borrowed"){
                books[i].setStatus("Available");
                borrowedCount--;
                cout<<"Book returned.\n";
                return;
              }
             }
             cout<<"Book not found.\n";
        }

        void reserveBook(vector<Book>& books) {
            int id;
            cout<<"Enter Book ID: ";
            cin>>id;

            for (int i = 0;i < books.size();i++) {
                if (books[i].getBookId()== id && books[i].getStatus() == "Available") {
                     books[i].setStatus("Reserved");
                     books[i].setReservedDay(currentDay);
                     cout<<"Book reserved\n";
                     return;

                }
            }
            cout<<"Book not available.\n";
        }

        void checkNotifications(vector<Book>& books) {
            for (int i = 0; i < books.size();i++) {
                if (books[i].getStatus() == "Borrowed") {
                    if (currentDay - books[i].getBorrowedDay() >= 6) {
                        cout<<"Reminder: Book ID "<<books[i].getBookId()<<"is due soon\n";
                    }
                }
            }
        }

    
       

        
};




class Librarian : public User {
public:

    Librarian(int i, string n, string e) : User(i,n,e) {}

    void addBook(vector<Book>& books) {
        int id;
        string title;
        string author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id,title,author));
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
    void overdueReport(vector<Book>& books) {
        cout<<"Overdue Books: \n";
        for (int i = 0;i < books.size();i++) {
          if(books[i].getStatus()=="Borrowed" &&
            currentDay - books[i].getBorrowedDay()>7){
             books[i].displayBook();
             }
        }
    }


};

class Administrator : public User {
private:
    int borrowingLimit;

public:
    Administrator(int i, string n, string e) : User(i,n,e) {
        borrowingLimit = 5;

    }

    void setBorrowingLimit() {
        cout << "Enter new borrowing limit: ";
        cin >> borrowingLimit;
        }


    int getLimit() {
        return borrowingLimit;

    }

   
};

void showAvailableBooks(vector<Book>& books) {
    cout << "Available Books:\n";
    for (int i = 0;i < books.size();i++) {
        if (books[i].getStatus() == "Available") books[i].displayBook();
    }
}

void updateReservations(vector<Book>& books) {
    for (int i = 0;i < books.size();i++) {
        if (books[i].getStatus() == "Reserved" && currentDay - books[i].getReservedDay() > 3) {
            books[i].setStatus("Available");
            cout << "Reservation expired for Book ID " << books[i].getBookId() << endl;

        }
    }
}











int main() {

    Member member1(1, "Denis", "d@mail.com");
    Librarian librarian1(2, "Jacob", "j@mail.com");
    Administrator admin1(3, "Ian", "I@mail.com");

    vector<Book> books;
    books.push_back(Book(101, "c++", "John"));
    books.push_back(Book(102, "48 Laws of power", "Robert G."));

    int role, id, choice;

    while (true) {

        cout << "\n===== LIBRARY SYSTEM =====\n";
        cout << "1.Member 2.Librarian 3.Admin 0.Exit\n";
        cin >> role;

        if (role == 0) {
            cout << "System closed.\n";
            break;
        }

        cout << "Enter ID: ";
        cin >> id;

        // MEMBER
        if (role == 1 && id == member1.getId()) {
            do {
                currentDay++;
                updateReservations(books);
                member1.checkNotifications(books);

                cout << "\n1.Search 2.Borrow 3.Return 4.Reserve 5.View Available 0.Logout\n";
                cin >> choice;

                if (choice == 1) member1.searchBook(books);
                else if (choice == 2) member1.borrowBook(books, admin1.getLimit());
                else if (choice == 3) member1.returnBook(books);
                else if (choice == 4) member1.reserveBook(books);
                else if (choice == 5) showAvailableBooks(books);

            } while (choice != 0);
        }

        // LIBRARIAN
        else if (role == 2 && id == librarian1.getId()) {
            do {
                cout << "\n1.Add 2.Remove 3.Overdue Report 0.Logout\n";
                cin >> choice;

                if (choice == 1) librarian1.addBook(books);
                else if (choice == 2) librarian1.removeBook(books);
                else if (choice == 3) librarian1.overdueReport(books);

            } while (choice != 0);
        }

        // ADMIN
        else if (role == 3 && id == admin1.getId()) {
            do {
                cout << "\n1.Set Borrowing Limit 0.Logout\n";
                cin >> choice;

                if (choice == 1) admin1.setBorrowingLimit();

            } while (choice != 0);
        }

        else {
            cout << "Invalid login.\n";
        }
    }

    return 0;
}
