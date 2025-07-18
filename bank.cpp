#include "bank.h"
#include <iostream>

Bank::Bank() : nextAccountNo(1000) {}

void Bank::createAccount(const std::string& name, AccountType type, double initBal) {
    accounts.emplace_back(nextAccountNo++, name, type, initBal);
    std::cout << "Account created successfully!\n";
}

void Bank::deposit(int accNo, double amount) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            acc.deposit(amount);
            std::cout << "Deposit successful.\n";
            return;
        }
    }
    std::cout << "Account not found!\n";
}

void Bank::withdraw(int accNo, double amount) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            if (acc.withdraw(amount))
                std::cout << "Withdrawal successful.\n";
            else
                std::cout << "Insufficient funds.\n";
            return;
        }
    }
    std::cout << "Account not found!\n";
}

void Bank::displayAccount(int accNo) const {
    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            acc.display();
            return;
        }
    }
    std::cout << "Account not found!\n";
}

void Bank::displayAll() const {
    for (const auto& acc : accounts) {
        acc.display();
    }
}

void Bank::displayHistory(int accNo) const {
    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            acc.displayHistory();
            return;
        }
    }
    std::cout << "Account not found!\n";
}