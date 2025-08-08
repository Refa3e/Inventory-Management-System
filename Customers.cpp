#include "Customers.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void Customers::SetName(string name) {
    this->name = name;
}
void Customers::SetPhoneNumber(string phone_number) {
    this->phone_number = phone_number;
}
void Customers::SetAddress(string address) {
    this->address = address;
}
string Customers::GetName() const {
    return name;
}
string Customers::GetPhoneNumber() const {
    return phone_number;
}
string Customers::GetAddress() const {
    return address;
}
void Customers::SetIdCustomer(int id) {
    this->id_customer = id;
}
int Customers::GetIdCustomer() const {
    return id_customer;
}
void Customers::Add_NewCustomer() {
    int id;
    string name, phone, address;
    cout << "Enter customer ID: ";
    cin >> id;
    SetIdCustomer(id);
    cout << "Enter customer name: ";
    cin >> name;
    SetName(name);
    cout << "Enter phone number: ";
    cin >> phone;
    SetPhoneNumber(phone);
    cout << "Enter address: ";
    cin >> address;
    SetAddress(address);
    SaveToFile("customers.txt");
    cout << "Customer added successfully." << endl;
}
void Customers::SaveToFile(const string &filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << id_customer << " " << name << " " << phone_number << " " << address << "\n";
        file.close();
    }
}
bool Customers::SearchCustomer(const string &filename, int customer_id) {
    ifstream file(filename);
    int file_id;
    string file_name, file_phone, file_address;
    if (file.is_open()) {
        while (file >> file_id >> file_name >> file_phone >> file_address) {
            if (file_id == customer_id) {
                SetIdCustomer(file_id);
                SetName(file_name);
                SetPhoneNumber(file_phone);
                SetAddress(file_address);
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}