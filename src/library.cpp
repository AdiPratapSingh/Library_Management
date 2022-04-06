#include <bits/stdc++.h>
#include <user.hpp>
#include <book.hpp>
#include <ctime>

using namespace std;

int main(){
    UserDb database;
    BookDb bookdatabase;
    int mode = -1;

    while (mode!= 1&&mode != 2){
        cout<<"What do you want to do? Sign In[1] /Register[2] : ";
        cin>>mode;
        cout<<"\n";
        if(mode!=1&&mode!=2){
            cout<<"Please give a valid input\n";
        }
    }

    int verified = 0;

    while(verified == 0){
        int role;
        string UserName;
        string UserPassword;

        while (role!= 1&&role != 2&&role != 3){
            cout<<"Whith which role you want to sign in? Student[1]/Professor[2]/Librarian[3] : ";
            cin>>role;
            cout<<"\n";
            if(role!=1&&role!=2&&role!=3){
                cout<<"Please give a valid input\n";
            }
        }

        cout<<"Username : \n";
        getline(cin, UserName);

        cout<<"Password : \n";
        getline(cin, UserPassword);

        switch(role){
            case 1:
                int StudentIndex = database.FindStudent(UserName);
                if(StudentIndex = -1){
                    cout<<"Credentials dont match! Please try again\n";
                    continue;
                }
                else{
                    printf("Welcome %s! What do you want to do?\n", database.StudentList[StudentIndex].Name);
                    printf("- List Books                 [1]\n");
                    printf("- Issue Books                [2]\n");
                    printf("- Return Books               [3]\n");
                    printf("- Get Dues                   [4]\n");
                    printf("- Log Out                    [5]\n");
                    printf("Enter the correpsonding number to choose :");
                    int state;
                    cin>>state;
                    switch(state){
                        case 1:
                            bookdatabase.List();
                            break;
                        
                        case 2:
                            //Iss
                            
                    }
                }
                break;
            case 2:
            case 3:
        }

    }
}