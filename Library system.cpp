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

};

