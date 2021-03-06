#include <bits/stdc++.h>
#include <user.hpp>
#include <book.hpp>
#include <ctime>
#include <chrono>

using namespace std;

string convertToString(char* a){
    string s(a);
    return s;
}

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

Book::Book(string Title1, string Author1, string ISBN1, string Publication1){
    Title = Title1;
    Author = Author1;
    ISBN = ISBN1;
    Publication = Publication1;
    isBooked = false;
}

Book::Book(){
    string str = "NA";
    Title = str;
    Author = str;
    ISBN = str;
    Publication = str;
    isBooked = false;
}

void BookDb::Add(){
    Book book;
    
    cout<<"Enter the Title of the Book"<<endl;
    cin.ignore();
    getline(cin, book.Title);

    cout<<"Enter the Author of the Book"<<endl;
    cin.ignore();
    getline(cin,book.Author);

    cout<<"Enter the ISBN of the Book"<<endl;
    cin.ignore();
    getline(cin,book.ISBN);

    cout<<"Enter the Publication of the Book"<<endl;
    cin.ignore();
    getline(cin,book.Publication);

    list.push_back(book);
    return;
}

int BookDb::Add(Book book){
    list.push_back(book);
    return list.size();
}

void BookDb::Delete(){   
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to delete using Title of the book.\nPress 2 if you want to delete using ISBN.\nPress 3 if you want to abort the process\n"<<endl;
        cin>>str;
        flag = str[0] - '0';
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>str;
            flag = str[0] - '0';
            cout<<"\n\n";
        }

        if(flag == 1){
            cout<<"Enter the Title of the Book which you want to delete :"<<endl;
            // cin.ignore();
            // cin>>str;
            cin.ignore();
            getline(cin,str);
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
            // getline(cin, str);
            // cin.ignore();
            // cin>>str;
            cin.ignore();
            getline(cin,str);
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
            cout<<"The book has been deleted!\n"<<endl;
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
        cin>>str;
        flag = str[0] - '0';
        
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>str;
            flag = str[0] - '0';
        }

        if(flag == 1){
            cout<<"Enter the Title of the Book which you want to search :"<<endl;
            // cin.ignore();
            // cin>>str;
            cin.ignore();
            getline(cin,str);
            cout<<"\n\n";

            for(int i=0;i<list.size();i++){
                if(list[i].Title == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"\n";
                    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||\n";
                    cout<<"=================================================================================================================================";
                    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||\n";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the ISBN of the Book which you want to delete :"<<endl;
            // cin.ignore();
            // cin>>str;
            cin.ignore();
            getline(cin,str);

            for(int i=0;i<list.size();i++){
                if(list[i].ISBN == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||\n";
                    cout<<"=================================================================================================================================\n";
                    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||\n";
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

int BookDb::Search(string BookName){
    for(int i=0;i<list.size();i++){
        if(list[i].Title == BookName){
            return i;
        }
    }
}

void BookDb::List(){
    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||\n";
    cout<<"==================================================================================================================================\n";
    for(int i=0;i<list.size();i++)
    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||\n";
    cout<<"==================================================================================================================================\n\n\n";
    return;              
}

Book*BookDb::Issue(){
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to issue using Title of the book.\nPress 2 if you want to issue using ISBN.\nPress 3 if you want to abort the process\n"<<endl;
        cin>>str;
        flag = str[0] - '0';
        
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>str;
            flag = str[0] - '0';
        }

        if(flag == 1){
            cout<<"Enter the Title of the Book which you want to issue :"<<endl;
            // string bookname, bookname2;
            cin.ignore();
            getline(cin,str);
            cout<<"\n\n";
            // cout<<bookname<<" "<<bookname2<<"\n";

            for(int i=0;i<list.size();i++){
                cout<<list[i].Title<<" "<<str<<"\n";
                if(list[i].Title == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"\n";
                    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||\n";
                    cout<<"=================================================================================================================================\n";
                    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||\n";
                    found = 1;
                    cout<<list[i].isBooked<<"\n";
                    if(list[i].isBooked == true){
                        cout<<"Unfortunately, the book has been held by someone else\n\n";
                        return NULL;
                    }
                    else{
                        cout<<"The book has been issued!\n";
                    }
                    list[i].isBooked = true;
                    cout<<"------------"<<list[i].isBooked<<"\n";
                    cout<<"\n\n";
                    return &list[i];
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the ISBN of the Book which you want to issue :"<<endl;
            cin.ignore();
            getline(cin,str);
            // getline(cin, str);
            // cin.ignore();
            // cin>>str;

            for(int i=0;i<list.size();i++){
                if(list[i].ISBN == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Title              ||          Author            ||          Publication            ||          ISBN            ||\n";
                    cout<<"=================================================================================================================================\n";
                    cout<<"||  "<<list[i].Title<<"  ||  "<<list[i].Author<<"  ||  "<<list[i].Publication<<"  ||  "<<list[i].ISBN<<"  ||\n";
                    found = 1;
                    if(list[i].isBooked == true){
                        cout<<"Unfortunately, the book has been held by someone else\n\n";
                        return NULL;
                    }
                    list[i].isBooked = true;
                    // list[i].duedate = time(0) + (90*24*60*60);
                    cout<<"\n\n";
                    return &list[i];
                }
            }
        }
        else if(flag==3){
            cout<<"Aborting!\n";
            return NULL;
        }

        if(!found){
            cout<<"Book not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n\n";
    }
}