#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Customers {
private:
    string name;
    string phone_number;
    string address;
    int id_customer;
public:
    Customers() {
        name ="";
        phone_number="";
        address="";
        id_customer=0;
    }
    void SetName(string name);
    void SetPhoneNumber(string phone_number);
    void SetAddress(string address);
    string GetName() const;
    string GetPhoneNumber() const;
    string GetAddress() const;
    void Add_NewCustomer();
    void SetIdCustomer(int id);
    int GetIdCustomer() const;
    void SaveToFile(const string &filename) const;
    bool SearchCustomer(const string &filename, int customer_id);
};
#endif //CUSTOMERS_H
