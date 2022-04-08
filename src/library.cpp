#include <fstream>
#include <bits/stdc++.h>
#include <user.hpp>
#include <book.hpp>
#include <ctime>

using namespace std;

// string convertToString(char* a){
//     string s(a);
//     return s;
// }

int main(){
    UserDb database;
    BookDb bookdatabase;
    int running = 1;
    string z;

    char p;
    std::cout<<"Do you want to populate the Database from the contents in textfile [y/n] :";
    cin>>p;
    if(p=='y'){
        vector<string> lines;
        string line;

        ifstream input_file1("../Database/books.txt");
        ifstream input_file2("../Database/user.txt");

        if (!input_file1.is_open()) {
            cerr << "Could not open the file - '"
                << "Database/books.txt" << "'" << endl;
        }
        if (!input_file2.is_open()) {
            cerr << "Could not open the file - '"
                << "Database/user.txt" << "'" << endl;
        }

        while (getline(input_file1, line)){
            lines.push_back(line);
        }

        for (int i=0;i<lines.size();i=i+5){
            Book book;
            book.Title = lines[i];
            book.Author = lines[i+1];
            book.ISBN = lines[i+2];
            book.Publication = lines[i+3];
            bookdatabase.list.push_back(book);
        }
    
        lines.clear();

        while (getline(input_file2, line)){
            lines.push_back(line);
        }

        for (int i=0;i<lines.size();i=i+5){
            int role = (lines[i])[0] - '0'; 
            switch(role){
                case 1:{
                    Student student;
                    student.Name = lines[i+1];
                    student.UserName = lines[i+2];
                    student.Password = lines[i+3];
                    student.Fine = 0;
                    database.StudentList.push_back(student);
                    break;
                }
                case 2:{
                    Professor professor;
                    professor.Name = lines[i+1];
                    professor.UserName = lines[i+2];
                    professor.Password = lines[i+3];
                    professor.Fine = 0;
                    database.ProfessorList.push_back(professor);
                    break;
                }
                case 3:{
                    Librarian librarian;
                    librarian.Name = lines[i+1];
                    librarian.UserName = lines[i+2];
                    librarian.Password = lines[i+3];
                    librarian.Fine = 0;
                    database.LibrarianList.push_back(librarian);
                    break;
                }
            }
        }

        input_file1.close();
        input_file2.close();
    }

    while(running){
        int mode = -1;

        while (mode!= 1&&mode != 2){
            cout<<"What do you want to do? Sign In[1] /Register[2] : ";
            cin>>z;
            mode = z[0] - '0';
            cout<<"\n";
            if(mode!=1&&mode!=2){
                cout<<"Please give a valid input\n";
            }
        }

        int LoggedIn = 0;
        switch(mode){
            case 1:{                        // Sign In
                while(LoggedIn == 0){
                    int role = -1;
                    string UserName;
                    string UserPassword;

                    while (role!= 1&&role != 2&&role != 3){
                        cout<<"Whith which role you want to sign in? Student[1]/Professor[2]/Librarian[3] : ";
                        cin>>z;
                        role = z[0] - '0';
                        cout<<"\n";
                        if(role!=1&&role!=2&&role!=3){
                            cout<<"Please give a valid input\n";
                        }
                    }

                    cout<<"Username : ";
                    cin.ignore();
                    cin>>UserName;

                    cout<<"Password : ";
                    cin.ignore();
                    cin>>UserPassword;

                    switch(role){
                        case 1:{                 // Student
                            // cout<<database.StudentList.size()<<"\n";
                            int StudentIndex = database.FindStudent(UserName);
                            if(StudentIndex == -1||database.StudentList[StudentIndex].Password!=UserPassword){
                                cout<<"Credentials dont match! Please try again\n";
                                continue;
                            }
                            else{
                                LoggedIn = 1;
                                cout<<"Welcome "<<database.StudentList[StudentIndex].Name<<"\n\n";
                                while(LoggedIn==1){
                                    int state = -1;
                                    while(state <1 || state > 5 ){   
                                        printf("What do you want to do?\n");
                                        printf("- List Books                 [1]\n");
                                        printf("- Issue Book                 [2]\n");
                                        printf("- Return Book                [3]\n");
                                        printf("- Get Dues                   [4]\n");
                                        printf("- Log Out                    [5]\n");
                                        printf("Enter the correpsonding number to choose :");
                                        cin>>z;
                                        state = z[0] - '0';
                                        if(state <1 || state > 5 ){
                                            cout<<"Please provide a valid input";
                                        }
                                    }
                                    switch(state){
                                        case 1:{       // Student List Books
                                            bookdatabase.List();
                                            break;
                                        }
                                        
                                        case 2:{       // Student Issue Books`
                                            database.StudentList[StudentIndex].Issue(bookdatabase);
                                            break;
                                        }
                                        case 3:{       // Student Return Book
                                            database.StudentList[StudentIndex].Return(bookdatabase);
                                            break;
                                        }        
                                        case 4:{       // Student Get Dues
                                            cout<<"Your current Dues are : ₹ "<<database.StudentList[StudentIndex].Fine<<"\n\n";
                                            break;
                                        }
                                        case 5:{       // Student Log Out
                                            LoggedIn = -1;
                                            cout<<"Logging Out!\n\n";
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{   // Professor
                            int ProfessorIndex = database.FindProfessor(UserName);
                            if(ProfessorIndex == -1||database.ProfessorList[ProfessorIndex].Password!=UserPassword){
                                cout<<"Credentials dont match! Please try again\n";
                                continue;
                            }
                            else{
                                LoggedIn = 1;
                                cout<<"Welcome "<<database.ProfessorList[ProfessorIndex].Name<<"\n\n";
                                while(LoggedIn==1){
                                    int state = -1;
                                    while(state <1 || state > 5 ){   
                                        printf("What do you want to do?\n");
                                        printf("- List Books                 [1]\n");
                                        printf("- Issue Book                 [2]\n");
                                        printf("- Return Book                [3]\n");
                                        printf("- Get Dues                   [4]\n");
                                        printf("- Log Out                    [5]\n");
                                        printf("Enter the correpsonding number to choose :");

                                        cin>>z;
                                        state = z[0] - '0';
                                        if(state <1 || state > 5 ){
                                            cout<<"Please provide a valid input";
                                        }
                                    }
                                    switch(state){
                                        case 1:{       // Professor List Books
                                            bookdatabase.List();
                                            break;
                                        }
                                        case 2:{       // Professor Issue Books`
                                            database.ProfessorList[ProfessorIndex].Issue(bookdatabase);
                                            break;
                                        }
                                        case 3:{       // Professor Return Book
                                            database.ProfessorList[ProfessorIndex].Return(bookdatabase);
                                            break;
                                        }
                                        case 4:{       // Professor Get Dues
                                            cout<<"Your current Dues are : ₹ "<<database.ProfessorList[ProfessorIndex].Fine;
                                            break;
                                        }
                                        case 5:{       // Professor Log Out
                                            LoggedIn = -1;
                                            cout<<"Logging Out!\n\n";
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 3:{    // Librarian
                            int LibrarianIndex = database.FindLibrarian(UserName);
                            if(LibrarianIndex == -1||database.LibrarianList[LibrarianIndex].Password!=UserPassword){
                                cout<<"Credentials dont match! Please try again\n";
                                continue;
                            }
                            else{
                                LoggedIn = 1;
                                cout<<"Welcome "<<database.LibrarianList[LibrarianIndex].Name<<"\n\n";
                                while(LoggedIn == 1){
                                    int state = -1;
                                    while(state <1 || state > 8 ){   
                                        printf("What do you want to do?\n");
                                        printf("- List Books                 [1]\n");
                                        printf("- List User                  [2]\n");
                                        printf("- Add Book                   [3]\n");
                                        printf("- Delete Book                [4]\n");
                                        printf("- Inspect User               [5]\n");
                                        printf("- Delete User                [6]\n");
                                        printf("- Log Out                    [7]\n");
                                        printf("- Add User                   [8]\n");
                                        printf("Enter the correpsonding number to choose :");
                                        cin>>z;
                                        state = z[0] - '0';
                                        cout<<"\n";
                                        if(state <1 || state > 8 ){
                                            cout<<"Please provide a valid input";
                                        }
                                    }
                                    switch(state){
                                        case 1:{       // Librarian List Books
                                            bookdatabase.List();
                                            break;
                                        }

                                        case 2:{       // Librarian List User
                                            cout<<"What is the designation of the Users whome you want to list :\n";
                                            cout<<"- Student                     [1]\n";
                                            cout<<"- Professor                   [2]\n";
                                            cout<<"- Librarian                   [3]\n";

                                            cin>>z;
                                            switch(z[0] - '0'){
                                                case 1:{
                                                    cout<<"||              Name              ||          Username            ||\n";
                                                    cout<<"===================================================================\n";
                                                    for(int i=0;i<database.StudentList.size();i++){
                                                        cout<<"||  "<<database.StudentList[i].Name <<"  ||  "<<database.StudentList[i].UserName<<"||\n";
                                                        cout<<"====================================================================\n\n";
                                                    }
                                                    break;
                                                }
                                                case 2:{
                                                    cout<<"||              Name              ||          Username            ||\n";
                                                    cout<<"===================================================================\n";
                                                    for(int i=0;i<database.ProfessorList.size();i++){
                                                        cout<<"||  "<<database.ProfessorList[i].Name <<"  ||  "<<database.ProfessorList[i].UserName<<"||\n";
                                                        cout<<"====================================================================\n\n";
                                                    }
                                                    break;
                                                }
                                                case 3:{
                                                    cout<<"||              Name              ||          Username            ||\n";
                                                    cout<<"===================================================================\n";
                                                    for(int i=0;i<database.LibrarianList.size();i++){
                                                        cout<<"||  "<<database.LibrarianList[i].Name <<"  ||  "<<database.LibrarianList[i].UserName<<"||\n";
                                                        cout<<"====================================================================\n\n";
                                                    }
                                                    break;
                                                }
                                                default:{
                                                    cout<<"Please give a valid input\n";
                                                }
                                            }
                                            break;
                                        }

                                        case 3:{       // Librarian Add Book
                                            bookdatabase.Add();
                                            break;
                                        }

                                        case 4:{       // Librarian Delete Book
                                            bookdatabase.Delete();
                                            break;
                                        }

                                        case 5:{       // Librarian Inspect User
                                            //=====================
                                            // Kuch kar
                                            //=====================
                                            cout<<"What is the designation of the Users whome you want to inspect :\n";
                                            cout<<"- Student                     [1]\n";
                                            cout<<"- Professor                   [2]\n";
                                            cout<<"- Librarian                   [3]\n";
                                            
                                            cin>>z;
                                            switch(z[0]-'0'){
                                                case 1:{
                                                    database.FindStudent();
                                                    break;
                                                }
                                                case 2:{
                                                    database.FindProfessor();
                                                    break;
                                                }
                                                case 3:{
                                                    database.FindLibrarian();
                                                    break;
                                                }
                                            }
                                            break;
                                        }

                                        case 6:{       // Librarian Delete User
                                            cout<<"What is the designation of the person whome you want to delete :\n";
                                            cout<<"- Student                     [1]\n";
                                            cout<<"- Professor                   [2]\n";
                                            cout<<"- Librarian                   [3]\n";
                                            
                                            cin>>z;
                                            switch(z[0]-'0'){
                                                case 1:{
                                                    database.DeleteStudent();
                                                    break;
                                                }
                                                case 2:{
                                                    database.DeleteProfessor();
                                                    break;
                                                }
                                                case 3:{
                                                    database.DeleteLibrarian();
                                                    break;
                                                }
                                            }
                                            break;
                                        }

                                        case 7:{       // Librarian Log Out
                                            LoggedIn = -1;
                                            cout<<"Logging Out!\n\n";
                                            break;
                                        }
                                        
                                        case 8:{
                                            cout<<"What is the designation of the Users whome you want to add :\n";
                                            cout<<"- Student                     [1]\n";
                                            cout<<"- Professor                   [2]\n";
                                            cout<<"- Librarian                   [3]\n";
                                            
                                            cin>>z;
                                            switch(z[0]-'0'){
                                                case 1:{
                                                    database.AddStudent();
                                                    break;
                                                }
                                                case 2:{
                                                    database.AddProfessor();
                                                    break;
                                                }
                                                case 3:{
                                                    database.AddLibrarian();
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                    }

                }
                break;
            }
            case 2:{                                // Register
                int role = -1;
                string UserName;
                string UserPassword;
                string name;

                while (role!= 1&&role != 2&&role != 3){
                    cout<<"Whith which role you want to Sign Up? Student[1]/Professor[2]/Librarian[3] : ";
                    
                    cin>>z;
                    role = z[0] - '0';
                    cout<<"\n";
                    if(role!=1&&role!=2&&role!=3){
                        cout<<"Please give a valid input\n";
                    }
                }

                cout<<"Username : ";
                cin.ignore();
                cin>>UserName;

                cout<<"Password : ";
                cin.ignore();
                cin>>UserPassword;

                cout<<"Name : ";
                cin.ignore();
                cin>>name;
                cout<<"\n";

                switch(role){
                    case 1:{                     // Student
                        Student student;
                        student.UserName = UserName;
                        student.Password = UserPassword;
                        student.Name = name;
                        student.Fine = 0;
                        student.calc = time(0);
                        database.StudentList.push_back(student);
                        break;
                    }
                    case 2:{                     // Professor
                        Professor professor;
                        professor.UserName = UserName;
                        professor.Password = UserPassword;
                        professor.Name = name;
                        professor.Fine = 0;
                        professor.calc = time(0);
                        database.ProfessorList.push_back(professor);
                        break;
                    }
                    case 3:{                     // Librarian
                        Librarian librarian;
                        librarian.UserName = UserName;
                        librarian.Password = UserPassword;
                        librarian.Name = name;
                        librarian.Fine = 0;
                        librarian.calc = time(0);
                        database.LibrarianList.push_back(librarian);
                        break;
                    }
                }
                break;
            }
        }
    }
}