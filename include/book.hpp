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
        void Show_duedate(); // Done
};

class BookDb{
    public:
        vector<Book> list; 
        void Add(); // Done
        void Delete(); // Done
        void Search(); // Done
};