#include <bits/stdc++.h>
#include <ctime>
#include <chrono>

using namespace std;

class Book{
    public:
        string Title;
        string Author;
        string ISBN;
        string Publication;
        chrono::system_clock duedate;
        bool isBooked;
        void Show_duedate(chrono::system_clock & duedate);
};

class BookDb{
    public:
        vector<Book> list; 
        void Add();
        void Delete();
        void Search();
};

class User{
    public:
        string UserName;
        string Name;
        string Password;
        int Fine;
        vector<pair<Book,chrono::system_clock>> list;    
};

class Student:public User{
    public:
        void Calculate_fine(int &Fine,vector<pair<Book,chrono::system_clock>> &list);
        void Clear_fine_amount(int &Fine);
};

class Professor:public User{
    public:
        void Calculate_fine(int &Fine,vector<pair<Book,chrono::system_clock>> &list);
        void Clear_fine_amount(int &Fine);
};

class Librarian:public User{
    public:
        void Delete(UserDb &database);
        void Add(UserDb &database);
        // Need to add more functionality
};

class UserDb{
    vector<User> list;
};
