#pragma once
#include <bits/stdc++.h>
#include <ctime>
#include <chrono>

using namespace std;
class Book{
    public:
        Book();
        Book(string Title, string Author, string ISBN, string Publication);
        string Title;
        string Author;
        string ISBN;
        string Publication;
        time_t duedate;
        bool isBooked;
        void Show_duedate(); //  not Done
};

class BookDb{
    public:
        vector<Book> list; 
        void Add();        // Done
        int Add(Book book);

        void Delete();     // Done

        void Search();     // Done
        int Search(string BookName); // Dine

        void List();       // Done
        Book*Issue(); 
};