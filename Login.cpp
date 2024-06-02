#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void loginn();
void registerr();
void forgott();

main()
{
    int choice;
    cout << "************************ Welcome ************************" << endl;
    cout << "Menu" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Forget username and password" << endl;
    cout << "4. Exit " << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    cout << endl;

    switch (choice)
    {
    case 1:
        loginn();
        break;

    case 2:
        registerr();
        break;

    case 3:
        forgott();
        break;

    case 4:
        system("cls"); // clear the console screen.
        cout << "You have a made a mistake , please try again .";
        main();
    }
}

void loginn()
{
    int count;
    string user, passWord, u, p;

    system("cls"); // clear the console screen.
    cout << "please fill the following details " << endl;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> passWord;

    ifstream input("database.txt"); // This allows you to read data from the specified file.
    while (input >> u >> p)
    {
        if (u == user && p == passWord)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        /* code */
        cout << "Hello " << user << "\n <LOGIN SUCCESSFULLY>\n";
        cout << "******************* Welcome to login page *******************";
        cin.get();
    }
    else
    {
        cout << "\nSorry brohh.\n Please check your usename and password ?" << endl;
    }
}

void registerr()
{
    string username, userpassword, ru, pu;
    system("cls"); // clear the console screen.
    cout << "Enter your name : ";
    cin >> username;
    cout << "Enter your password : ";
    cin >> userpassword;

    ofstream reg("database.txt", ios::app);
    reg << username << " " << userpassword << endl;
    system("cls"); // clear the console screen.
    cout << "\nAapka account teyar hai. " << endl;
    cout << "Login karen. ";
}

void forgott()
{
    int ch;
    system("cls");
    cout << "Kya gunda bnega re tu ......ek option choose krle ? " << endl;
    cout << "1. Search your id by username" << endl;
    cout << "2. Main menu" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        int count = 0;
        string searchUser, su, sp;
        cout << "\n Enter your remembered username :";

        cin >> searchUser;
        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchUser)
            {
                count == 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\nAccount found" << endl;
            cout << "\nYour password is : " << endl;
            cin.get();
            system("cls");
            main();
        }
        else
        {

            cout << "\nSorry , your userid not found in our Database.\n";
            cin.get();
        }
        break;
            
    }
}