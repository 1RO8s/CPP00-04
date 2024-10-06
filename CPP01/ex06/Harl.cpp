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
  std::cout << "[ DEBUG ]:\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]:\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\n" << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]:\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]:\nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::invalid(void) {
  std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
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
  switch (logLevel)
  {
  case DEBUG:
    (this->*_logFunctions[DEBUG])();
  case INFO:
    (this->*_logFunctions[INFO])();
  case WARNING:
    (this->*_logFunctions[WARNING])();
  case ERROR:
    (this->*_logFunctions[ERROR])();
    break;
  case INVALID:
    (this->*_logFunctions[INVALID])();
  default:
    break;
  }
}
