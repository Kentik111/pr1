#include <iostream>
#include "client.h"
#include "server.h"

using namespace std;

void showMainMenu() {
    cout << "1. Войти\n";
    cout << "2. Зарегистрироваться\n";
    cout << "3. Выйти\n";
}

void showUserMenu() {
    cout << "1. Добавить продукт\n";
    cout << "2. Удалить продукт\n";
    cout << "3. Проверить продукт\n";
    cout << "4. Вывести все проверенные продукты\n";
    cout << "5. Выйти\n";
}

void Client::run() {
    Server server;
    int choice;

    while (true) {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                server.login();
                break;
            case 2:
                server.registerUser();
                break;
            case 3:
                return;
            default:
                cout << "Неверный выбор, попробуйте снова.\n";
        }

        while (server.isLoggedIn()) {
            showUserMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    server.addProduct();
                    break;
                case 2:
                    server.deleteProduct();
                    break;
                case 3:
                    server.checkProduct();
                    break;
                case 4:
                    server.listCheckedProducts();
                    break;
                case 5:
                    server.logout();
                    break;
                default:
                    cout << "Неверный выбор, попробуйте снова.\n";
            }
        }
    }
}


