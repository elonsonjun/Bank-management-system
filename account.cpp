#include "account.h"
#include <iostream>
#include <iomanip>

Account::Account(int accNo, const std::string& name, AccountType accType, double initBal)
    : accountNumber(accNo), ownerName(name), type(accType), balance(initBal) {
    interestRate = (type == AccountType::SAVINGS) ? 0.03 : 0.0;
}

int Account::getAccountNumber() const { return accountNumber; }
std::string Account::getOwnerName() const { return ownerName; }
double Account::getBalance() const { return balance; }
AccountType Account::getType() const { return type; }

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposit", amount);
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        addTransaction("Withdraw", amount);
        return true;
    }
    return false;
}

void Account::addTransaction(const std::string& type, double amount) {
    history.emplace_back(type, amount);
}

void Account::applyInterest() {
    if (type == AccountType::SAVINGS) {
        double interest = balance * interestRate;
        deposit(interest);
    }
}

void Account::display() const {
    std::cout << "Account #" << accountNumber << " ("
              << (type == AccountType::SAVINGS ? "Savings" : "Current")
              << ") - " << ownerName << " | Balance: ₹" 
              << std::fixed << std::setprecision(2) << balance << "\n";
}

void Account::displayHistory() const {
    for (const auto& tx : history) {
        tx.display();
    }
}