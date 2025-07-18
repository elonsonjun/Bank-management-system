#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <map>

class AuthSystem {
private:
    std::map<std::string, std::string> adminCredentials;
    std::map<std::string, std::string> userCredentials;

public:
    AuthSystem();
    bool loginAsAdmin(const std::string& user, const std::string& pass);
    bool loginAsUser(const std::string& user, const std::string& pass);
    void registerUser(const std::string& user, const std::string& pass);
};

#endif