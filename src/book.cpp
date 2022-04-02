#include <bits/stdc++.h>
#include <library.hpp>
#include <ctime>
#include <chrono>

using namespace std;

void Book::Show_duedate(){
    if(isBooked){
        cout<<"The duedate for the book is "; // -----
    }
    else{
        cout<<"This book has no duedate, therefore it is available. "<<endl;
    }
    cout<<"\n\n";
    cout<<"=======================================================================\n\n\n";
};

void BookDb::Add(){
    Book book;
    
    cout<<"Enter the Title of the Book"<<endl;
    getline(cin, book.Title);

    cout<<"Enter the Author of the Book"<<endl;
    getline(cin, book.Author);

    cout<<"Enter the ISBN of the Book"<<endl;
    getline(cin, book.ISBN);

    cout<<"Enter the Publication of the Book"<<endl;
    getline(cin, book.Publication);

    list.push_back(book);
}

void BookDb::Delete(){
    
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to delete using Title of the book.\nPress 2 if you want to delete using ISBN.\nPress 3 if you want to abort the process\n"<<endl;
        cin>>flag;
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
            cout<<"\n\n";
        }

        if(flag == 1){
            cout<<"Enter the Title of the Book which you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<list.size();i++){
                if(list[i].Title == str){
                    list.erase(list.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the ISBN of the Book which you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<list.size();i++){
                if(list[i].ISBN == str){
                    list.erase(list.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag==3){
            return;
        }

        if(found){
            cout<<"The book has been deleted!"<<endl;
            cout<<"\n\n";
            return;
        }
        else{
            cout<<"Book not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n\n";
    }
}

void BookDb::Search(){
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to search using Title of the book.\nPress 2 if you want to search using ISBN.\nPress 3 if you want to abort the process\n"<<endl;
        cin>>flag;
        
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
        }

        if(flag == 1){
            cout<<"Enter the Title of the Book which you want to search :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<list.size();i++){
                if(list[i].Title == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"\n";
                    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||";
                    cout<<"=================================================================================================================================";
                    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the ISBN of the Book which you want to delete :"<<endl;
            getline(cin, str);

            for(int i=0;i<list.size();i++){
                if(list[i].ISBN == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||";
                    cout<<"=================================================================================================================================";
                    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag==3){
            return;
        }

        if(found){
            return;
        }
        else{
            cout<<"Book not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n\n";
    }
}