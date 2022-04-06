#include <bits/stdc++.h>
#include <user.hpp>
#include <ctime>
#include <chrono>

using namespace std;

int Student::Calculate_fine(time_t t){
    int inc = (float)(t - calc)/(24.0*60.0*60.0);
    calc+=(24.0*60.0*60.0*inc);
    for(int i=0;i<list.size();i++){
        inc = (float)(t - max(calc,list[i].second))/(24.0*60.0*60.0);
        if(list[i].second < t){
            Fine += (inc*2);
        }
    }
}

void Student::Clear_fine_amount(){
    Fine = 0;
}

int Professor::Calculate_fine(time_t t){
    int inc = (float)(t - calc)/(24.0*60.0*60.0);
    calc+=(24.0*60.0*60.0*inc);
    for(int i=0;i<list.size();i++){
        inc = (float)(t - max(calc,list[i].second))/(24.0*60.0*60.0);
        if(list[i].second < t){
            Fine += (inc*5);
        }
    }
}

void Professor::Clear_fine_amount(){
    Fine = 0;
}

// interactive
void UserDb::FindStudent(){
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to search using Name of the Student.\nPress 2 if you want to Search using Username.\nPress 3 if you want to abort the process\n"<<endl;
        cin>>flag;

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
            cout<<"\n\n";
        }
        if(flag == 1){
            cout<<"Enter the name of the Student\n"<<endl;

            getline(cin, str);

            for(int i=0;i<StudentList.size();i++){
                if(StudentList[i].Name == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Name              ||          Username            ||          Fine Ammount            ||\n";
                    cout<<"========================================================================================================\n";
                    cout<<"||  "<<StudentList[i].Name <<"  ||  "<<StudentList[i].UserName<<" ||"<<StudentList[i].Calculate_fine(time(0))<<" ||\n";
                    cout<<"====================================================================\n\n";
                    cout<<"                        List of books issued\n\n";
                    cout<<"||          Book Name             ||          Due Date            ||\n";
                    cout<<"====================================================================\n";
                    for(int j=0;j<StudentList[i].list.size();j++){
                        char*due = ctime(&(StudentList[i].list[j].first.duedate));
                        cout<<StudentList[i].list[j].first.Title<<" || "<<due<<" ||\n";
                    }
                    cout<<"====================================================================\n";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the Username of the Student\n"<<endl;
            
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<StudentList.size();i++){
                if(StudentList[i].UserName == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Name              ||          Username            ||       Current Fine        ||\n";
                    cout<<"=================================================================================================\n";
                    
                    cout<<"||  "<<StudentList[i].Name <<"  ||  "<<StudentList[i].UserName<<" || "<<StudentList[i].Calculate_fine(time(0))<<" ||\n";
                    cout<<"=================================================================================================\n\n";
                    cout<<"                        List of books issued\n\n";
                    cout<<"||          Book Name             ||          Due Date            ||\n";
                    cout<<"====================================================================\n";
                    for(int j=0;j<StudentList[i].list.size();j++){
                        char*due = ctime(&(StudentList[i].list[j].first.duedate));
                        cout<<"|| "<<StudentList[i].list[j].first.Title<<" || "<<due<<" ||\n";
                    }
                    cout<<"====================================================================\n";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag==3){
            cout<<"Aborted!\n\n";
            return;
        }

        if(found){
            return;
        }
        else{
            cout<<"Student not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n\n";
    }
}

// via username non interactive
int UserDb::FindStudent(string str){
    int flag,found;
    found = 0;
    for(int i=0;i<StudentList.size();i++){
        if(StudentList[i].UserName == str){
            return i;
        }
    }
    return -1;
}


void UserDb::FindProfessor(){
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to search using Name of the Professor.\nPress 2 if you want to Search using Username.\nPress 3 if you want to abort the process\n"<<endl;
        cin>>flag;

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
            cout<<"\n\n";
        }
        if(flag == 1){
            cout<<"Enter the name of the Professor\n"<<endl;
            
            cout<<"\n\n";
            getline(cin, str);

            for(int i=0;i<ProfessorList.size();i++){
                if(ProfessorList[i].Name == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Name              ||          Username            ||          Fine Ammount            ||\n";
                    cout<<"========================================================================================================\n";
                    cout<<"||  "<<ProfessorList[i].Name <<"  ||  "<<ProfessorList[i].UserName<<" ||"<<ProfessorList[i].Calculate_fine(time(0))<<" ||\n";
                    cout<<"====================================================================\n\n";
                    cout<<"                        List of books issued\n\n";
                    cout<<"||          Book Name             ||          Due Date            ||\n";
                    cout<<"====================================================================\n";
                    for(int j=0;j<ProfessorList[i].list.size();j++){
                        char*due = ctime(&(ProfessorList[i].list[j].first.duedate));
                        cout<<ProfessorList[i].list[j].first.Title<<" || "<<due<<" ||\n";
                    }
                    cout<<"====================================================================\n";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the Username of the Pro\n"<<endl;
            
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<ProfessorList.size();i++){
                if(ProfessorList[i].UserName == str){

                    cout<<"The book has been found!"<<endl;
                    cout<<"||              Name              ||          Username            ||       Current Fine        ||\n";
                    cout<<"=================================================================================================\n";
                    
                    cout<<"||  "<<ProfessorList[i].Name <<"  ||  "<<ProfessorList[i].UserName<<" || "<<ProfessorList[i].Calculate_fine(time(0))<<" ||\n";
                    cout<<"=================================================================================================\n\n";
                    cout<<"                        List of books issued\n\n";
                    cout<<"||          Book Name             ||          Due Date            ||\n";
                    cout<<"====================================================================\n";
                    for(int j=0;j<ProfessorList[i].list.size();j++){
                        char*due = ctime(&(ProfessorList[i].list[j].first.duedate));
                        cout<<"|| "<<ProfessorList[i].list[j].first.Title<<" || "<<due<<" ||\n";
                    }
                    cout<<"====================================================================\n";
                    found = 1;
                    cout<<"\n\n";
                    break;
                }
            }
        }
        else if(flag==3){
            cout<<"Aborted!\n\n";
            return;
        }

        if(found){
            return;
        }
        else{
            cout<<"Professor not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n\n";
    }
}

// via username non interactive
int UserDb::FindProfessor(string str){
    int flag,found;
    found = 0;
    for(int i=0;i<ProfessorList.size();i++){
        if(ProfessorList[i].UserName == str){
            return i;
        }
    }
    return -1;
}

void UserDb::DeleteStudent(){   
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to delete using name of the Student.\nPress 2 if you want to delete using Username of Student.\nPress 3 if you want to abort the process"<<endl;
        cin>>flag;
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
            cout<<"\n\n";
        }

        if(flag == 1){
            cout<<"Enter the Name of the Student which you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<StudentList.size();i++){
                if(StudentList[i].Name == str){
                    StudentList.erase(StudentList.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the Username of the Student which you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<StudentList.size();i++){
                if(StudentList[i].UserName == str){
                    StudentList.erase(StudentList.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag==3){
            cout<<"Aborted!\n\n";
            return;
        }

        if(found){
            cout<<"Student has been deleted!\n"<<endl;
            cout<<"\n\n";
            return;
        }
        else{
            cout<<"Student not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n";
    }
}

void UserDb::DeleteProfessor(){   
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to delete using name of the Professor.\nPress 2 if you want to delete using Username of Professor.\nPress 3 if you want to abort the process"<<endl;
        cin>>flag;
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
            cout<<"\n\n";
        }

        if(flag == 1){
            cout<<"Enter the Name of the Professor who you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<ProfessorList.size();i++){
                if(ProfessorList[i].Name == str){
                    ProfessorList.erase(ProfessorList.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the Username of the Professor which you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<ProfessorList.size();i++){
                if(ProfessorList[i].UserName == str){
                    ProfessorList.erase(ProfessorList.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag==3){
            cout<<"Aborted!\n\n";
            return;
        }

        if(found){
            cout<<"Professor has been deleted!\n"<<endl;
            cout<<"\n\n";
            return;
        }
        else{
            cout<<"Professor not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n";
    }
}

void UserDb::DeleteLibrarian(){   
    int flag,found;
    found = 0;
    string str;

    while(!found){
        cout<<"Press 1 if you want to delete using name of the Librarian.\nPress 2 if you want to delete using Username of Librarian.\nPress 3 if you want to abort the process"<<endl;
        cin>>flag;
        cout<<"\n\n";

        while(flag!=1&&flag!=2&&flag!=3){
            cout<<"Please provide a valid input : ";
            cin>>flag;
            cout<<"\n\n";
        }

        if(flag == 1){
            cout<<"Enter the Name of the Librarian who you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<LibrarianList.size();i++){
                if(LibrarianList[i].Name == str){
                    LibrarianList.erase(LibrarianList.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag == 2){
            cout<<"Enter the Username of the Librarian which you want to delete :"<<endl;
            getline(cin, str);
            cout<<"\n\n";

            for(int i=0;i<LibrarianList.size();i++){
                if(LibrarianList[i].UserName == str){
                    LibrarianList.erase(LibrarianList.begin()+i);
                    found = 1;
                    break;
                }
            }
        }
        else if(flag==3){
            cout<<"Aborted!\n\n";
            return;
        }

        if(found){
            cout<<"Librarian has been deleted!\n"<<endl;
            cout<<"\n\n";
            return;
        }
        else{
            cout<<"Librarian not found, please recheck the entered value!\n\n";
        }
        cout<<"=======================================================================\n\n";
    }
}

void UserDb::AddProfessor(){   
    Professor prof;
    string str;

    cout<<"Enter the Name of the Professor:"<<endl;
    getline(cin, prof.Name);

    cout<<"Enter the UserName of the Professor:"<<endl;
    getline(cin, prof.UserName);

    cout<<"Enter the Password of the Professor:"<<endl;
    getline(cin, prof.Password);

    prof.Fine = 0;
    prof.calc = time(0);

    ProfessorList.push_back(prof);

}

void UserDb::AddStudent(){   
    Student student;
    string str;

    cout<<"Enter the Name of the Student:"<<endl;
    getline(cin, student.Name);

    cout<<"Enter the UserName of the Student:"<<endl;
    getline(cin, student.UserName);

    cout<<"Enter the Password of the Student:"<<endl;
    getline(cin, student.Password);

    student.Fine = 0;
    student.calc = time(0);
    
    StudentList.push_back(student);
}

void UserDb::AddLibrarian(){   
    Librarian Librarian;
    string str;

    cout<<"Enter the Name of the Librarian:"<<endl;
    getline(cin, Librarian.Name);

    cout<<"Enter the UserName of the Librarian:"<<endl;
    getline(cin, Librarian.UserName);

    cout<<"Enter the Password of the Librarian:"<<endl;
    getline(cin, Librarian.Password);

    Librarian.Fine = 0;
    Librarian.calc = time(0);
    
}