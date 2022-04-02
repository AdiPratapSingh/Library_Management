#include <bits/stdc++.h>
#include <book.hpp>
#include <ctime>
#include <chrono>

using namespace std;

class UserDb{
    vector<Student> StudentList;
    vector<Professor> ProfessorList;

    void FindStudent();        // Done
    void FindProfessor();      // Done

    void DeleteStudent();      // Done
    void DeleteProfessor();    // Done

    void AddStudent();      
    void AddProfessor();
};

class User{
    public:
        string UserName;
        string Name;
        string Password;
        int Fine;
        time_t calc;
        vector<pair<Book,time_t>> list;    
};

class Student:public User{
    public:
        int Calculate_fine(time_t t);
        void Clear_fine_amount();
};

class Professor:public User{
    public:
        int Calculate_fine(time_t t);
        void Clear_fine_amount();
};

class Librarian:public User{
    public:
        
        // Need to add more functionality
};