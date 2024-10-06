#include "Harl.hpp"

Harl::Harl() {
  this->_levels[0] = "DEBUG";
  _levels[1] = "INFO";
  _levels[2] = "WARNING";
  _levels[3] = "ERROR";
  _levels[4] = "INVALID";
  this->_logFunctions[DEBUG] = &Harl::debug;
  this->_logFunctions[INFO] = &Harl::info;
  this->_logFunctions[WARNING] = &Harl::warning;
  this->_logFunctions[ERROR] = &Harl::error;
  this->_logFunctions[INVALID] = &Harl::invalid;
  std::cout << "Harl object created" << std::endl;
}

Harl::~Harl() {
  std::cout << "Harl object destroyed" << std::endl;
}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]:\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]:\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]:\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]:\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::invalid(void) {
    std::cout << "Invalid log level" << std::endl;
}

// 文字列からenum LogLevelを取得する
Harl::LogLevel Harl::_getLogLevel(const std::string& level) {
    for (int i = 0; i < 4; i++) {
        if (level == this->_levels[i]) {
            return static_cast<LogLevel>(i);
        }
    }
    return INVALID;
}

void Harl::complain(std::string level) {
  LogLevel logLevel = this->_getLogLevel(level);
  (this->*_logFunctions[logLevel])();
}
