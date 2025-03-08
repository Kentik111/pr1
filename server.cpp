#include <iostream>
#include "server.h"
#include "dataBase.h"

using namespace std;

DataBase database;

void Server::registerUser() {
    string name, password;
    cout << "Введите имя пользователя: ";
    cin >> name;
    cout << "Введите пароль: ";
    cin >> password;

    if (database.addUser(name, password)) {
        cout << "Регистрация успешна!\n";
    } else {
        cout << "Ошибка регистрации: пользователь уже существует.\n";
    }
}

void Server::login() {
    string name, password;
    cout << "Введите имя пользователя: ";
    cin >> name;
    cout << "Введите пароль: ";
    cin >> password;

    if (database.validateUser(name, password)) {
        loggedIn = true;
        cout << "Вход выполнен успешно!\n";
    } else {
        cout << "Ошибка входа: неверное имя пользователя или пароль.\n";
    }
}

void Server::logout() {
    loggedIn = false;
    cout << "Вы вышли из системы.\n";
}

void Server::addProduct() {
    if (!loggedIn) {
        cout << "Сначала войдите в систему.\n";
        return;
    }

    string productName;
    cout << "Введите название продукта: ";
    cin >> productName;
        if (database.addProduct(productName)) {
        cout << "Продукт добавлен.\n";
    } else {
        cout << "Ошибка добавления продукта.\n";
    }
}

void Server::deleteProduct() {
    if (!loggedIn) {
        cout << "Сначала войдите в систему.\n";
        return;
    }

    string productName;
    cout << "Введите название продукта для удаления: ";
    cin >> productName;

    if (database.deleteProduct(productName)) {
        cout << "Продукт удален.\n";
    } else {
        cout << "Ошибка удаления продукта.\n";
    }
}

void Server::checkProduct() {
    if (!loggedIn) {
        cout << "Сначала войдите в систему.\n";
        return;
    }

    string productName;
    cout << "Введите название продукта для проверки: ";
    cin >> productName;

    if (database.checkProduct(productName)) {
        cout << "Продукт проверен.\n";
    } else {
        cout << "Продукт не найден.\n";
    }
}

void Server::listCheckedProducts() {
    if (!loggedIn) {
        cout << "Сначала войдите в систему.\n";
        return;
    }

    database.printCheckedProducts();
}
