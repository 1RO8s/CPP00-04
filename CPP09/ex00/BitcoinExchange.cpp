#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    bool isHeader = true;
    while (std::getline(file, line)) {
        if (isHeader) {
            isHeader = false;
            continue;
        }

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            continue; // 不正な形式の行はスキップ
        }

        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        
        double rate;
        std::istringstream iss(rateStr);
        if (!(iss >> rate)) {
            continue; // 数値に変換できない場合はスキップ
        }

        _database[date] = rate;
    }

    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            if (line != "date | value") {
                std::cout << "Warning: First line should be 'date | value'. Processing anyway..." << std::endl;
            }
            continue;
        }

        std::string date;
        double value;
        
        if (!parseInputLine(line, date, value)) {
            continue; // エラーメッセージは既にparseInputLine内で出力されている
        }

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(value)) {
            if (value < 0) {
                std::cout << "Error: not a positive number." << std::endl;
            } else if (value > 1000) {
                std::cout << "Error: too large a number." << std::endl;
            }
            continue;
        }

        try {
            double btcValue = getBitcoinValue(date, value);
            std::cout << date << " => " << value << " = " << btcValue << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    file.close();
}

bool BitcoinExchange::parseInputLine(const std::string& line, std::string& date, double& value) const {
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 3);

    // 前後の空白を除去
    size_t first = date.find_first_not_of(" \t");
    size_t last = date.find_last_not_of(" \t");
    if (first != std::string::npos && last != std::string::npos) {
        date = date.substr(first, last - first + 1);
    }

    // 数値変換
    char* endPtr;
    value = std::strtod(valueStr.c_str(), &endPtr); 
    if (*endPtr != '\0' && !std::isspace(*endPtr)) {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // YYYY-MM-DD形式のチェック
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;
    
    // 各月の日数
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // うるう年のチェック
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    
    return day >= 1 && day <= daysInMonth[month];
}

bool BitcoinExchange::isValidValue(const double value) const {
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    if (_database.empty()) {
        throw std::runtime_error("Database is empty.");
    }

    std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
    if (it == _database.begin()) {
        // 最初の日付より前の場合は、最初の日付を返す
        return it->first;
    }
    
    --it;
    return it->first;
}

double BitcoinExchange::getBitcoinValue(const std::string& date, double amount) const {
    if (_database.empty()) {
        throw std::runtime_error("Database is empty.");
    }

    std::map<std::string, double>::const_iterator it = _database.find(date);
    
    // 一致する日付がない場合は、最も近い過去の日付を探す
    if (it == _database.end()) {
        std::string closestDate = findClosestDate(date);
        it = _database.find(closestDate);
    }
    
    if (it == _database.end()) {
        throw std::runtime_error("No exchange rate available for this date.");
    }
    
    return amount * it->second;
}
