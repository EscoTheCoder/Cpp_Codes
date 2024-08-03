#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {

    int choice;
    int i;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "    SECURITY SYSTEM" << endl;

    cout << " ___________________________" << endl;
    cout << "|        1. Register        |" << endl;
    cout << "|        2. Login           |" << endl;
    cout << "|        3. Change Password |" << endl;
    cout << "|________4. End Program_____|" << endl << endl;

    do {
        cout << endl << "Enter Your Coice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
                cout << "__________Registration__________" << endl << endl;
                cout << "Please Enter Your Username:";
                cin >> name;
                cout << "Please Enter Your Password:";
                cin >> password0;
                cout << "Please Enter Your Age:";
                cin >> age;

                fstream file1;
                file1.open("file.txt", ios::out);

                if (file1.is_open()) {
                    file1 << name << endl;
                    file1 << password0;
                    cout << "Registration Successfull" << endl;
                    file1.close();
                }
                break;
            }
            case 2: {
                i = 0;
                cout << "__________Login__________" << endl << endl;
                cout << "Please Enter Your Username:";
                cin >> user;
                cout << "Please Enter Your Password:";
                cin >> pass;

                fstream file2;
                file2.open("file.txt", ios::in);

                if (file2.is_open()) {
                    string line;
                    while (getline(file2, line)) {
                        creds[i] = line;
                        i++;
                    }
                    file2.close();
                    if (user == creds[0] && pass == creds[1]) {
                        cout << "______Login Successful______" << endl << endl;

                        cout << "Details:" << endl;
                        cout << "Username:" << user << endl;
                        cout << "Password:" << pass << endl;
                        cout << "Age:" << age << endl;
                    } else {
                        cout << endl << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|        1.Press 2 to Login           |" << endl;
                        cout << "|        2.Press 3 to Change Password |" << endl;
                    }
                }
                break;
            }
            case 3: {
                i = 0;
                cout << "____________Change Password___________" << endl;

                fstream file3;
                file3.open("file.txt", ios::in);

                cout << "Enter The Old Password:";
                cin >> old;
                if (file3.is_open()) {
                    string line;
                    while (getline(file3, line)) {
                        cp[i] = line;
                        i++;
                    }
                    if (old == creds[1]) {
                        file3.close();

                        fstream file4;
                        file4.open("file.txt", ios::out);

                        if (file4.is_open()) {
                            cout << "Enter your New Password:";
                            cin >> password1;
                            cout << "Enter your New Password Again:";
                            cin >> password2;

                            if (password1 == password2) {
                                file4 << cp[0] << endl;
                                file4 << password1;
                                cout << "Password Changed Successfully" << endl;
                            } else {
                                file4 << cp[0] << endl;
                                file4 << old;
                                cout << "Passwords Are Not The Same" << endl;
                            }
                        }
                    } else {
                        cout << "Please Enter A Valid Password" << endl;
                        break;
                    }
                }
                break;
            }
            case 4: {
                cout << "____________Thank You__________" << endl;
                break;
            }
            default: {
                cout << "Enter A Valid choice:";
            }
        }
    }
    while(choice!=4);

    return 0;
}



