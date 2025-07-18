#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& uname, const std::string& pass);
    virtual ~User() = default;
    std::string getUsername() const;
    bool checkPassword(const std::string& pass) const;
};

#endif