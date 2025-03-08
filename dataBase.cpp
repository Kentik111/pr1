#include "dataBase.h"

bool DataBase::addUser(const string& name, const string& password) {
    if (users.find(name) != users.end()) {
        return false;
    }

    users[name] = {password};
    return true;
}

bool DataBase::validateUser(const string& name, const string& password) {
    auto it = users.find(name);

    if (it != users.end() && it->second.password == password) {
        return true;
    }

    return false;
}

bool DataBase::addProduct(const string& name) {
    if (products.find(name) != products.end()) {
        return false;
    }

    products[name] = {false};
    return true;
}

bool DataBase::deleteProduct(const string& name) {
    return products.erase(name) > 0;
}

bool DataBase::checkProduct(const string& name) {
    auto it = products.find(name);

    if (it != products.end()) {
        it->second.checked = true;
        return true;
    }

    return false;
}

void DataBase::printCheckedProducts() {
    cout << "Проверенные продукты:\n";
    for (const auto& pair : products) {
        if (pair.second.checked) {
            cout << "- " << pair.first << "\n";
        }
    }
}

