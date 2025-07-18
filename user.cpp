#include "user.h"

User::User(const std::string& uname, const std::string& pass)
    : username(uname), password(pass) {}

std::string User::getUsername() const {
    return username;
}

bool User::checkPassword(const std::string& pass) const {
    return password == pass;
}