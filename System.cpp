#include "System.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "User.h"
#include "Stock.h"
#include "Customers.h"

using namespace std;

int System::item_id = 100;
int System::customer_id = 100;

void System::LoadAllUsers() {
    users.clear();
    ifstream file("users.txt");
    string username, password;
    while (file >> username >> password) {
        User u;
        u.SetUserName(username);
        u.SetPassword(password);
        users.push_back(u);
    }
    file.close();
}

void System::LoadAllStocks() {
    stocks.clear();
    ifstream file("stock.txt");
    int id;
    string name;
    double price;
    int number;
    while (file >> id >> name >> price >> number) {
        Stock s;
        s.SetId(id);
        s.SetName(name);
        s.SetPrice(price);
        s.Set_numberOfItem(number);
        stocks.push_back(s);
    }
    file.close();
}

void System::LoadAllCustomers() {
    customers.clear();
    ifstream file("customers.txt");
    int id;
    string name, phone, address;
    while (file >> id >> name >> phone >> address) {
        Customers c;
        c.SetIdCustomer(id);
        c.SetName(name);
        c.SetPhoneNumber(phone);
        c.SetAddress(address);
        customers.push_back(c);
    }
    file.close();
}

void System::SignUp() {
    User u;
    u.SignUp();
    LoadAllUsers();
}

void System::Login() {
    User u;
    u.Login();
    LoadAllUsers();
}

int System::menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\n====== Main Menu ======\n";
        cout << "1) Sign up\n";
        cout << "2) Login\n";
        cout << "3) Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice! Try again.\n";
            choice = -1;
        }
    }
    return choice;
}

void System::choice() {
    bool running = true;
    while (running) {
        int choose = menu();
        if (choose == 1) {
            SignUp();
        } else if (choose == 2) {
            Login();
            LoadAllStocks();
            LoadAllCustomers();

            int choice2 = -1;
            while (choice2 == -1) {
                cout << "\n====== Dashboard ======\n";
                cout << "1) Product management\n";
                cout << "2) Customer Management\n";
                cout << "3) Selling process\n";
                cout << "4) Buying process\n";
                cout << "5) Exit to main menu\n";
                cout << "Choose option: ";
                cin >> choice2;
                if (choice2 < 1 || choice2 > 5) {
                    cout << "Invalid choice, try again.\n";
                    choice2 = -1;
                }
            }

            switch (choice2) {
                case 1: {
                    int choice3 = -1;
                    while (choice3 == -1) {
                        cout << "\n=== Product Management ===\n";
                        cout << "1) Add item\n";
                        cout << "2) Update item\n";
                        cout << "3) Display items\n";
                        cout << "4) Search item\n";
                        cout << "5) Delete item\n";
                        cout << "6) Exit to dashboard\n";
                        cout << "Choose option: ";
                        cin >> choice3;
                        if (choice3 < 1 || choice3 > 6) {
                            cout << "Invalid choice, try again.\n";
                            choice3 = -1;
                        }
                    }
                    if (choice3 == 1) Add_item();
                    else if (choice3 == 2) Update_items();
                    else if (choice3 == 3) Display_items();
                    else if (choice3 == 4) Search_items();
                    else if (choice3 == 5) Delete_items();
                    break;
                }
                case 2: {
                    int choice4 = -1;
                    while (choice4 == -1) {
                        cout << "\n=== Customer Management ===\n";
                        cout << "1) Add new customer\n";
                        cout << "2) Update customer\n";
                        cout << "3) Display customers\n";
                        cout << "4) Search customer\n";
                        cout << "5) Delete customer\n";
                        cout << "6) Exit to dashboard\n";
                        cout << "Choose option: ";
                        cin >> choice4;
                        if (choice4 < 1 || choice4 > 6) {
                            cout << "Invalid choice, try again.\n";
                            choice4 = -1;
                        }
                    }
                    if (choice4 == 1) Add_NewCustomer();
                    else if (choice4 == 2) Update_Customer();
                    else if (choice4 == 3) Display_Customer();
                    else if (choice4 == 4) Search_Customer();
                    else if (choice4 == 5) Delete_Customer();
                    break;
                }
                case 3:
                    Sales();
                    break;
                case 4:
                    Buy();
                    break;
                case 5:
                    continue;
            }

        } else if (choose == 3) {
            cout << "Exiting program... Goodbye!\n";
            running = false;
        }
    }
}
void System::Add_item() {
    Stock s;
    s.AddItem();
    LoadAllStocks();
}
void System::Display_items() {
    LoadAllStocks();
    if (stocks.empty()) {
        cout << "No items to display.\n";
        return;
    }
    cout << "\n=== Items Dashboard ===\n";
    for (auto& x : stocks) {
        cout << "ID: " << x.getid()
             << ", Name: " << x.GetName()
             << ", Price: " << x.GetPrice()
             << ", Quantity: " << x.Get_numberOfItem() << "\n";
    }
}
void System::Update_items() {
    LoadAllStocks();
    int id;
    cout << "Enter item id to update: ";
    cin >> id;
    bool found = false;
    for (auto& x : stocks) {
        if (x.getid() == id) {
            int choice = -1;
            while (choice == -1) {
                cout << "Update:\n1) Name\n2) Price\n3) Quantity\nChoose: ";
                cin >> choice;
                if (choice < 1 || choice > 3) {
                    cout << "Invalid choice.\n";
                    choice = -1;
                }
            }
            if (choice == 1) {
                string name;
                cout << "Enter new name: ";
                cin >> name;
                x.SetName(name);
            } else if (choice == 2) {
                double price;
                cout << "Enter new price: ";
                cin >> price;
                x.SetPrice(price);
            } else if (choice == 3) {
                int q;
                cout << "Enter new quantity: ";
                cin >> q;
                x.Set_numberOfItem(q);
            }
            found = true;
            break;
        }
    }
    if (found) {
        ofstream file("stock.txt", ios::trunc);
        for (auto& s : stocks) {
            s.SaveToFile("stock.txt");
        }
        cout << "Item updated successfully.\n";
    } else {
        cout << "Item not found.\n";
    }
}
void System::Delete_items() {
    LoadAllStocks();
    int id;
    cout << "Enter item id to delete: ";
    cin >> id;
    auto it = remove_if(stocks.begin(), stocks.end(), [id](const Stock& s) {
        return s.getid() == id;
    });
    if (it != stocks.end()) {
        stocks.erase(it, stocks.end());
        ofstream file("stock.txt", ios::trunc);
        for (auto& s : stocks) {
            s.SaveToFile("stock.txt");
        }
        cout << "Item deleted successfully.\n";
    } else {
        cout << "No item with this id.\n";
    }
}
void System::Search_items() {
    LoadAllStocks();
    int id;
    cout << "Enter item id to search: ";
    cin >> id;
    for (auto& x : stocks) {
        if (x.getid() == id) {
            cout << "ID: " << x.getid()
                 << ", Name: " << x.GetName()
                 << ", Price: " << x.GetPrice()
                 << ", Quantity: " << x.Get_numberOfItem() << "\n";
            return;
        }
    }
    cout << "No item with this id.\n";
}
void System::Add_NewCustomer() {
    Customers c;
    c.Add_NewCustomer();
    LoadAllCustomers();
}
void System::Update_Customer() {
    LoadAllCustomers();
    int id;
    cout << "Enter customer id to update: ";
    cin >> id;
    bool found = false;
    for (auto& x : customers) {
        if (x.GetIdCustomer() == id) {
            int choice = -1;
            while (choice == -1) {
                cout << "Update:\n1) Name\n2) Phone\n3) Address\nChoose: ";
                cin >> choice;
                if (choice < 1 || choice > 3) {
                    cout << "Invalid choice.\n";
                    choice = -1;
                }
            }
            if (choice == 1) {
                string name;
                cout << "Enter new name: ";
                cin >> name;
                x.SetName(name);
            } else if (choice == 2) {
                string phone;
                cout << "Enter new phone: ";
                cin >> phone;
                x.SetPhoneNumber(phone);
            } else if (choice == 3) {
                string address;
                cout << "Enter new address: ";
                cin >> address;
                x.SetAddress(address);
            }
            found = true;
            break;
        }
    }
    if (found) {
        ofstream file("customers.txt", ios::trunc);
        for (auto& c : customers) {
            c.SaveToFile("customers.txt");
        }
        cout << "Customer updated successfully.\n";
    } else {
        cout << "Customer not found.\n";
    }
}
void System::Delete_Customer() {
    LoadAllCustomers();
    int id;
    cout << "Enter customer id to delete: ";
    cin >> id;
    auto it = remove_if(customers.begin(), customers.end(), [id](const Customers& c) {
        return c.GetIdCustomer() == id;
    });
    if (it != customers.end()) {
        customers.erase(it, customers.end());
        ofstream file("customers.txt", ios::trunc);
        for (auto& c : customers) {
            c.SaveToFile("customers.txt");
        }
        cout << "Customer deleted successfully.\n";
    } else {
        cout << "No customer with this id.\n";
    }
}
void System::Search_Customer() {
    LoadAllCustomers();
    int id;
    cout << "Enter customer id to search: ";
    cin >> id;
    for (auto& x : customers) {
        if (x.GetIdCustomer() == id) {
            cout << "Name: " << x.GetName()
                 << ", Phone: " << x.GetPhoneNumber()
                 << ", Address: " << x.GetAddress() << "\n";
            return;
        }
    }
    cout << "No customer with this id.\n";
}
void System::Display_Customer() {
    LoadAllCustomers();
    if (customers.empty()) {
        cout << "No customers to display.\n";
        return;
    }
    cout << "\n=== Customers Dashboard ===\n";
    for (auto& x : customers) {
        cout << "ID: " << x.GetIdCustomer()
             << ", Name: " << x.GetName()
             << ", Phone: " << x.GetPhoneNumber()
             << ", Address: " << x.GetAddress() << "\n";
    }
}
void System::Sales() {
    LoadAllStocks();
    Display_items();
    int id, quantity;
    cout << "Enter item id to sell: ";
    cin >> id;
    bool found = false;
    for (auto& x : stocks) {
        if (x.getid() == id) {
            cout << "Enter quantity to sell: ";
            cin >> quantity;
            if (quantity > x.Get_numberOfItem()) {
                cout << "Not enough stock.\n";
                return;
            }
            x.Set_numberOfItem(x.Get_numberOfItem() - quantity);
            time_t now = time(0);
            char* dt = ctime(&now);
            cout << "\n=== Sale Invoice ===\n";
            cout << "Product: " << x.GetName() << "\n";
            cout << "Quantity: " << quantity << "\n";
            cout << "Unit price: " << x.GetPrice() << "\n";
            cout << "Total price: " << x.GetPrice() * quantity << "\n";
            cout << "Date: " << dt;
            cout << "Remaining stock: " << x.Get_numberOfItem() << "\n";
            ofstream file("stock.txt", ios::trunc);
            for (auto &s : stocks) {
                s.SaveToFile("stock.txt");
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found.\n";
    }
}
void System::Buy() {
    Add_item();
}

