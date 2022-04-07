#pragma once
#include <bits/stdc++.h>
#include <book.hpp>
#include <ctime>
#include <chrono>

using namespace std;

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
        void Issue(BookDb database);
        Book* Return(BookDb database);
};

class Professor:public User{
    public:
        int Calculate_fine(time_t t);        // Done
        void Clear_fine_amount();            // Done
        // void Issue();
        void Issue(BookDb database);
        Book* Return(BookDb database);
};

class Librarian:public User{
    public:
        
};

class UserDb{
    public:
        vector<Student> StudentList;
        vector<Professor> ProfessorList;
        vector<Librarian> LibrarianList;

        void FindStudent();        // Done
        int FindStudent(string UserName);

        void FindProfessor();      // Done
        int FindProfessor(string UserName);

        void FindLibrarian();      // Done
        int FindLibrarian(string UserName);

        void DeleteStudent();      // Done
        void DeleteProfessor();    // Done
        void DeleteLibrarian();    // Done

        void AddStudent();         // Done
        void AddProfessor();       // Done
        void AddLibrarian();       // Done
};