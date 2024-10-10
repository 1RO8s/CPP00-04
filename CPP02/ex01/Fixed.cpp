#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = num << Fixed::FRACTIONAL_BITS;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(num * (1 << Fixed::FRACTIONAL_BITS));
}

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
    ostream << fixed.toFloat();
    return ostream;
}

float Fixed::toFloat() const {
    return (this->_rawBits / static_cast<float>(1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt() const {
    return this->_rawBits >> Fixed::FRACTIONAL_BITS;
}