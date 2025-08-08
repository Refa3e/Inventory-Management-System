#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "User.h"
#include "Stock.h"
#include "Customers.h"

class System {
private:
    std::vector<User> users;
    std::vector<Stock> stocks;
    std::vector<Customers> customers;
    static int item_id;
    static int customer_id;
public:
    int menu();
    void choice();
    void SignUp();
    void Login();

    void LoadAllUsers();
    void LoadAllStocks();
    void LoadAllCustomers();

    void Add_item();
    void Update_items();
    void Display_items();
    void Search_items();
    void Delete_items();

    void Add_NewCustomer();
    void Update_Customer();
    void Display_Customer();
    void Search_Customer();
    void Delete_Customer();

    void Sales();
    void Buy();
};

#endif //SYSTEM_H