#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <vector>

class Bank {
private:
    std::vector<Account> accounts;
    int nextAccountNo;

public:
    Bank();
    void createAccount(const std::string& name, AccountType type, double initBal);
    void deposit(int accNo, double amount);
    void withdraw(int accNo, double amount);
    void displayAccount(int accNo) const;
    void displayAll() const;
    void displayHistory(int accNo) const;
};

#endif