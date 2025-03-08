#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class DataBase {
private:
    struct User {
        string password;
    };

    struct Product {
        bool checked;
    };

    unordered_map<string, User> users;
    unordered_map<string, Product> products;

public:
    bool addUser(const string& name, const string& password);
    bool validateUser(const string& name, const string& password);

    bool addProduct(const string& name);
    bool deleteProduct(const string& name);

    bool checkProduct(const string& name);
    void printCheckedProducts();
};

#endif

