#include "User.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
void User::SetUserName(string name) {
    username = name;
}
string User::GetUserName() const {
    return username;
}
void User::SetPassword(string pass) {
    password = pass;
}
string User::GetPassword() const {
    return password;
}
void User::SaveToFile(const string &filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
    }
}
bool User::LoadFromFile(const string &filename, const string &name, const string &pass) {
    ifstream file(filename);
    string file_name, file_pass;
    while (file >> file_name >> file_pass) {
        if (file_name == name && file_pass == pass) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
void User::SignUp() {
    string name, pass;
    cout << "Enter username: ";
    cin >> name;
    SetUserName(name);
    cout << "Enter password: ";
    cin >> pass;
    SetPassword(pass);
    SaveToFile("users.txt");
    cout << "Account created successfully.\n";
}
bool User::Login_valid(const User &user, string name, string pass) {
    return LoadFromFile("users.txt", name, pass);
}
void User::Login() {
    string name, pass;
    cout << "Enter your username: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> pass;
    User temp_user;
    if (temp_user.Login_valid(temp_user, name, pass))
        cout << "Login successful\n";
    else
        cout << "Username or password not valid, try later!\n";
}
