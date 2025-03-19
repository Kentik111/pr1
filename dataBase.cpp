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
bool DataBase::checkProduct(const string& name, const vector<pair<string, bool>>& criteria) {
    auto it = products.find(name);

    if (it == products.end()) {
        return false;
    }

    it->second.checked = true;
    it->second.defective = false;
    it->second.defects.clear();

    for (const auto& criterion : criteria) {
        if (!criterion.second) {
            it->second.defective = true;
            it->second.defects.push_back(criterion.first);
        }
    }

    return true;
}

void DataBase::printCheckedProducts() {
    cout << "Проверенные продукты:\n";
    for (const auto& pair : products) {
        if (pair.second.checked && !pair.second.defective) {
            cout << "- " << pair.first << "\n";
        }
    }
}

void DataBase::printDefectiveProducts() {
    cout << "Бракованные продукты:\n";
    for (const auto& pair : products) {
        if (pair.second.checked && pair.second.defective) {
            cout << "- " << pair.first << " (";
            for (size_t i = 0; i < pair.second.defects.size(); ++i) {
                cout << pair.second.defects[i];
                if (i < pair.second.defects.size() - 1) {
                    cout << ", ";
                }
            }
            cout << ")\n";
        }
    }
}



