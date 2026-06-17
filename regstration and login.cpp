#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool registerUser(string username, string password) {
    ifstream infile("users.txt");
    string u, p;
    while(infile >> u >> p) {
        if(u == username) {
            cout << "Username already exists!" << endl;
            return false;
        }
    }
    infile.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();
    cout << "Registration successful!" << endl;
    return true;
}

bool loginUser(string username, string password) {
    ifstream infile("users.txt");
    string u, p;
    while(infile >> u >> p) {
        if(u == username && p == password) {
            cout << "Login successful!" << endl;
            return true;
        }
    }
    cout << "Invalid credentials!" << endl;
    return false;
}

int main() {
    int choice;
    string username, password;
    while(true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;
        if(choice == 1) {
            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;
            registerUser(username, password);
        } else if(choice == 2) {
            cout << "Enter username: "; cin >> username;
            cout << "Enter password: "; cin >> password;
            loginUser(username, password);
        } else {
            cout << "Exiting program..." << endl;
            break;
        }
    }
    return 0;
}

