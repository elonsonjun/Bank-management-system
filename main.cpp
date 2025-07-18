#include "bank.h"
#include "auth.h"
#include <iostream>

void userMenu(Bank& bank, AuthSystem& auth) {
    std::string username, password;
    std::cout << "Enter username: "; std::cin >> username;
    std::cout << "Enter password: "; std::cin >> password;

    if (!auth.loginAsUser(username, password)) {
        std::cout << "Invalid credentials!\n";
        return;
    }

    int choice;
    do {
        std::cout << "\n1. Deposit\n2. Withdraw\n3. View Balance\n4. Transaction History\n5. Exit\nChoose: ";
        std::cin >> choice;

        int accNo;
        double amount;
        switch (choice) {
            case 1:
                std::cout << "Account No: "; std::cin >> accNo;
                std::cout << "Amount: "; std::cin >> amount;
                bank.deposit(accNo, amount);
                break;
            case 2:
                std::cout << "Account No: "; std::cin >> accNo;
                std::cout << "Amount: "; std::cin >> amount;
                bank.withdraw(accNo, amount);
                break;
            case 3:
                std::cout << "Account No: "; std::cin >> accNo;
                bank.displayAccount(accNo);
                break;
            case 4:
                std::cout << "Account No: "; std::cin >> accNo;
                bank.displayHistory(accNo);
                break;
        }
    } while (choice != 5);
}

void adminMenu(Bank& bank, AuthSystem& auth) {
    std::string username, password;
    std::cout << "Enter admin username: "; std::cin >> username;
    std::cout << "Enter password: "; std::cin >> password;

    if (!auth.loginAsAdmin(username, password)) {
        std::cout << "Invalid admin credentials!\n";
        return;
    }

    int choice;
    do {
        std::cout << "\n1. Create Account\n2. Display All Accounts\n3. Exit\nChoose: ";
        std::cin >> choice;

        std::string name; double initBal; int typeChoice;
        switch (choice) {
            case 1:
                std::cout << "Name: "; std::cin.ignore(); std::getline(std::cin, name);
                std::cout << "Initial Balance: "; std::cin >> initBal;
                std::cout << "Type (1 = Savings, 2 = Current): "; std::cin >> typeChoice;
                bank.createAccount(name, static_cast<AccountType>(typeChoice - 1), initBal);
                break;
            case 2:
                bank.displayAll();
                break;
        }
    } while (choice != 3);
}

int main() {
    Bank bank;
    AuthSystem auth;
    auth.registerUser("user1", "pass1");

    int mainChoice;
    do {
        std::cout << "\n1. User Login\n2. Admin Login\n3. Exit\nChoose: ";
        std::cin >> mainChoice;
        switch (mainChoice) {
            case 1: userMenu(bank, auth); break;
            case 2: adminMenu(bank, auth); break;
        }
    } while (mainChoice != 3);

    return 0;
}