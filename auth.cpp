#include "auth.h"

AuthSystem::AuthSystem() {
    adminCredentials["admin"] = "admin123";
}

bool AuthSystem::loginAsAdmin(const std::string& user, const std::string& pass) {
    return adminCredentials.count(user) && adminCredentials[user] == pass;
}

bool AuthSystem::loginAsUser(const std::string& user, const std::string& pass) {
    return userCredentials.count(user) && userCredentials[user] == pass;
}

void AuthSystem::registerUser(const std::string& user, const std::string& pass) {
    userCredentials[user] = pass;
}