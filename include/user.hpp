#include <bits/stdc++.h>
#include <book.hpp>
#include <ctime>
#include <chrono>

using namespace std;

class UserDb{
    vector<Student> StudentList;
    vector<Professor> ProfList;
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
        void Calculate_fine();
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