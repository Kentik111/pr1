#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class DataBase {
private:
    struct User {
        string password;
    };

    struct Product {
        bool checked;
        bool defective;
        vector<string> defects;
    };

    unordered_map<string, User> users;
    unordered_map<string, Product> products;

public:
    bool addUser(const string& name, const string& password);
    bool validateUser(const string& name, const string& password);

    bool addProduct(const string& name);
    bool deleteProduct(const string& name);

    bool checkProduct(const string& name, const vector<pair<string, bool>>& criteria);
    void printCheckedProducts();
    void printDefectiveProducts();
};

#endif

