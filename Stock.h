// -------------------- Stock.h --------------------
#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Stock {
private:
    string name;
    double price;
    int number_of_item;
    int id;
public:
    Stock() {
        name ="";
        price= 0.0;
        number_of_item=0;
        id=0;
    };
    void SetName(string name);
    string GetName()const;
    void SetPrice(double price);
    double GetPrice()const;
    void Set_numberOfItem(int number_of_item );
    int Get_numberOfItem()const;
    void SetId(int id);
    int getid()const;
    void AddItem();
    void SaveToFile(const string &filename) const;
    bool LoadFromFile(const string &filename, int search_id);
};
#endif //STOCK_H
