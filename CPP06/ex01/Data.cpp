#include "Data.hpp"

Data::Data() : _value(0), _str("") {}

Data::Data(int value, const std::string& str) : _value(value), _str(str) {}

Data::Data(const Data& other) : _value(other._value), _str(other._str) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        _value = other._value;
        _str = other._str;
    }
    return *this;
}

Data::~Data() {}

int Data::getValue() const {
    return _value;
}

const std::string& Data::getStr() const {
    return _str;
} 