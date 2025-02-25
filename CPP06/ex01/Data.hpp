#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
    int _value;
    std::string _str;

public:
    Data();
    Data(int value, const std::string& str);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

    int getValue() const;
    const std::string& getStr() const;
};

#endif 