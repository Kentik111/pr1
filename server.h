#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
private:
    bool loggedIn;
public:
    Server() : loggedIn(false) {}

    void registerUser();
    void login();
    void logout();
    bool isLoggedIn() { return loggedIn; }

    void addProduct();
    void deleteProduct();
    void checkProduct();
    void listCheckedProducts();
};

#endif

