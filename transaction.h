#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string timestamp;
    std::string type;
    double amount;

public:
    Transaction();
    Transaction(const std::string& type, double amount);
    void display() const;
};

#endif