#include "transaction.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

Transaction::Transaction() : type("N/A"), amount(0.0) {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&now_c);
    timestamp.pop_back();
}

Transaction::Transaction(const std::string& t, double amt) : type(t), amount(amt) {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    timestamp = std::ctime(&now_c);
    timestamp.pop_back();
}

void Transaction::display() const {
    std::cout << "[" << timestamp << "] " << type << ": ₹" << amount << "\n";
}