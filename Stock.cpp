#include "Stock.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void Stock::SetName(string name) {
    this->name=name;
}
string Stock::GetName() const {
    return name;
}
void Stock::SetPrice(double price) {
    this->price=price;
}
double Stock::GetPrice() const {
    return price;
}
void Stock::Set_numberOfItem(int number_of_item) {
    this->number_of_item =number_of_item;
}
int Stock::Get_numberOfItem() const {
    return number_of_item;
}
void Stock::SetId(int id) {
    this->id=id;
}
int Stock::getid() const {
    return id;
}
void Stock::AddItem() {
    int id;
    string name;
    double price;
    int number;
    cout << "Enter item ID: ";
    cin >> id;
    SetId(id);
    cout << "Enter item name: ";
    cin >> name;
    SetName(name);
    cout << "Enter item price: ";
    cin >> price;
    SetPrice(price);
    cout << "Enter number of item: ";
    cin >> number;
    Set_numberOfItem(number + Get_numberOfItem());
    SaveToFile("stock.txt");
    cout << "Item added successfully." << endl;
}
void Stock::SaveToFile(const string &filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << id << " " << name << " " << price << " " << number_of_item << "\n";
        file.close();
    }
}
bool Stock::LoadFromFile(const string &filename, int search_id) {
    ifstream file(filename);
    int file_id;
    string file_name;
    double file_price;
    int file_number;
    if (file.is_open()) {
        while (file >> file_id >> file_name >> file_price >> file_number) {
            if (file_id == search_id) {
                SetId(file_id);
                SetName(file_name);
                SetPrice(file_price);
                Set_numberOfItem(file_number);
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}
