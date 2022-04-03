#include <bits/stdc++.h>
#include <book.hpp>
#include <ctime>
#include <chrono>

using namespace std;

class UserDb{
    vector<Student> StudentList;
    vector<Professor> ProfessorList;
    vector<Librarian> LibrarianList;

    void FindStudent();        // Done
    void FindProfessor();      // Done

    void DeleteStudent();      // Done
    void DeleteProfessor();    // Done
    void DeleteLibrarian();    // Done

    void AddStudent();         // Done
    void AddProfessor();       // Done
    void AddLibrarian();       // Done
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
        int Calculate_fine(time_t t);        // Done 
        void Clear_fine_amount();            // Done
};

class Professor:public User{
    public:
        int Calculate_fine(time_t t);        // Done
        void Clear_fine_amount();            // Done
};

class Librarian:public User{
    public:
        
};