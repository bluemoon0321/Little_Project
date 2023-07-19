#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t________________________________________________________\n\n\n";
    cout<<"\t\t\t                   Welcone to Logon page                \n\n\n";
    cout<<"\t\t\t___________________        Menu         ________________\n\n\n";
    cout<<"                                                                 \n\n";
    cout<<"\t|Press 1 to Login                       |"<<'\n';
    cout<<"\t|Press 2 to Register                    |"<<'\n';
    cout<<"\t|Press 3 if you forgot your password    |"<<'\n';
    cout<<"\t|Press 4 to Exit                        |"<<'\n';
    cout<<"\n\t\t\t Please enter your choice :";
    cin>>c;
    cout<<'\n';

    switch(c)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();   
            break;
        
        case 4:
            cout<<"\t\t\t Thankyou! \n\n\n";
            break;
        
        default:
            system("cls");
            cout<<"\t\t\t Please select from the options above \n"<<'\n';
            main();
    }

}


void login(){
    int count;
    string userID,password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the user name and password: "<<'\n';
    cout<<"\t\t\t UserName: ";
    cin>>userID;
    cout<<'\n';
    cout<<"\t\t\t Password: ";
    cin>>password;
    cout<<'\n';

    ifstream input("records.txt");
    while(input>>id>>pass){
        if(id==userID&&pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count){
        cout<<userID<<"\n Your login is successful \n Thanks for logging in! \n";
        main();
    }else{
        cout<<"\n Login Error \n Please check your username or password\n";
        main();
    }
}

void registration(){
    string rUserID, rPassword,rID,rPass;
    system("cls");
    cout<<"\t\t\t Enter the Username: ";
    cin>>rUserID;
    cout<<"\t\t\t Enter the Password: ";
    cin>>rPassword;

    ofstream f1("records.txt", ios::app);
    f1<<rUserID<<"  "<<rPassword<<'\n';
    system("cls");
    cout<<"\n\t\t\t Registration is successful! \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your ID by username "<<'\n';
    cout<<"Press 2 to go back to the main menu "<<'\n';
    cout<<"\t\t\t Enter your choice: ";
    cin>>option;
    switch(option){
        case 1:{
            int count=0;
            string sUserID, sID, sPass;
            cout<<"\n\t\t Enter the username which you remembered: ";
            cin>>sUserID;

            ifstream f2("records.txt");
            while(f2>>sID>>sPass){
                if(sID==sUserID){
                    count=1;
                }
            }
            f2.close();
            if(count){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is: "<<sPass;
                main();
            }else{
                cout<<"\n\t Sorry! your account is not found! \n";
                main();
            }
            break;
        }
        case 2:{
            main();
            break;
        }
        
        default:{
            cout<<"\t\t\t Wrong choice! Please try again\n";
            main();
            break;
        }

    }
}