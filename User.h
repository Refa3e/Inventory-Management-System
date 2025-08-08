#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class User {
private:
    string username;
    string password;
public:
    void SetUserName(string name);
    string GetUserName() const;
    void SetPassword(string pass);
    string GetPassword() const;
    void SignUp();
    void Login();
    bool Login_valid(const User &user, string name, string pass);
    void SaveToFile(const string &filename) const;
    bool LoadFromFile(const string &filename, const string &name, const string &pass);
};
#endif // USER_H