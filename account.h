#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "transaction.h"

enum class AccountType { SAVINGS, CURRENT };

class Account {
private:
    int accountNumber;
    std::string ownerName;
    AccountType type;
    double balance;
    double interestRate;
    std::vector<Transaction> history;

public:
    Account(int accNo, const std::string& name, AccountType accType, double initBal);

    int getAccountNumber() const;
    std::string getOwnerName() const;
    double getBalance() const;
    AccountType getType() const;
    
    void deposit(double amount);
    bool withdraw(double amount);
    void addTransaction(const std::string& type, double amount);
    void applyInterest();
    void display() const;
    void displayHistory() const;
};

#endif