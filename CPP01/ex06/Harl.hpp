#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
 public:
  Harl();
  ~Harl();
  void complain(std::string level);

 private:
  void debug();
  void info();
  void warning();
  void error();
  void invalid();

  std::string _levels[5];
  enum LogLevel { DEBUG, INFO, WARNING, ERROR, INVALID };
  LogLevel _getLogLevel(const std::string& level);
  void (Harl::*_logFunctions[5])(void);
};

#endif
