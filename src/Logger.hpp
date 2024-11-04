#pragma once
#include <bitset>
#include <iostream>
#include <string>

namespace ChessV2 {
using namespace std;

enum class LogLevel { DEBUG = 0, INFO, WARN, ERROR };
enum class LogColors { Red = 31, Yellow = 33, Blue = 34, Magenta = 35 };

class Logger {
public:
    Logger(LogLevel level) : m_logLevel(level) {
    }
    ~Logger() {
    }

    template <typename T>
    void debug(const T& out) {
        if (this->m_logLevel <= LogLevel::DEBUG) {
            cout << "\033[;" << static_cast<int>(LogColors::Magenta) << "m";
            cout << "[DEBUG] " << out;
            cout << "\033[0;0m" << endl;
        }
    }

    template <typename T>
    void info(const T& out) {
        if (this->m_logLevel <= LogLevel::INFO) {
            cout << "\033[;" << static_cast<int>(LogColors::Blue) << "m";
            cout << "[INFO] " << out << endl;
            cout << "\033[0;0m" << endl;
        }
    }

    template <typename T>
    void warn(const T& out) {
        if (this->m_logLevel <= LogLevel::WARN) {
            cout << "\033[;" << static_cast<int>(LogColors::Yellow) << "m";
            cout << "[WARN] " << out << endl;
            cout << "\033[0;0m" << endl;
        }
    }

    template <typename T>
    void error(const T& out) {
        if (this->m_logLevel <= LogLevel::ERROR) {
            cout << "\033[;" << static_cast<int>(LogColors::Red) << "m";
            cout << "[ERROR] " << out << endl;
            cout << "\033[0;0m" << endl;
        }
    }

    void bitout(const uint64_t& out) {
        cout << "[BITSET] " << bitset<64>(out) << endl;
    }

private:
    LogLevel m_logLevel;
};
};  // namespace ChessV2