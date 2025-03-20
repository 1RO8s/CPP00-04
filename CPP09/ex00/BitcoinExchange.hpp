#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
    double getBitcoinValue(const std::string& date, double amount) const;

private:
    std::map<std::string, double> _database;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const double value) const;
    bool parseInputLine(const std::string& line, std::string& date, double& value) const;
    std::string findClosestDate(const std::string& date) const;
};

#endif
