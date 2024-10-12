#include "Fixed.hpp"

#include <cmath>
#include <limits>

Fixed::Fixed() : _rawBits(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int num) {
    // std::cout << "Int constructor called" << std::endl;
    this->_rawBits = num << Fixed::FRACTIONAL_BITS;
}

Fixed::Fixed(const float num) {
    // std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(num * (1 << Fixed::FRACTIONAL_BITS));
}

Fixed &Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

float Fixed::toFloat() const {
    return (this->_rawBits / static_cast<float>(1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt() const {
    return this->_rawBits >> Fixed::FRACTIONAL_BITS;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed obj;
    if (other.getRawBits() > 0 && this->getRawBits() >  std::numeric_limits<int>::max() - other.getRawBits()) {
        throw std::overflow_error("Overflow");
    } else if (other.getRawBits() < 0 && this->getRawBits() < std::numeric_limits<int>::min() - other.getRawBits()) {
        throw std::overflow_error("Underflow");
    } 
    obj.setRawBits(this->getRawBits() + other.getRawBits());
    return obj;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed obj;
    if (other.getRawBits() > 0 && this->getRawBits() < std::numeric_limits<int>::min() + other.getRawBits()) {
        throw std::overflow_error("Underflow");
    } else if (other.getRawBits() < 0 && this->getRawBits() > std::numeric_limits<int>::max() + other.getRawBits()) {
        throw std::overflow_error("Overflow");
    }
    obj.setRawBits(this->getRawBits() - other.getRawBits());
    return obj;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed obj;
    int64_t result = static_cast<int64_t>(this->_rawBits) * other.getRawBits();
    if (result > std::numeric_limits<int>::max()){
        throw std::overflow_error("Overflow");
    } else if (result < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Underflow");
    }
    obj.setRawBits(static_cast<int>(result >> Fixed::FRACTIONAL_BITS));
    return obj;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed obj;
    if (other.getRawBits() == 0) {
        throw std::runtime_error("Zero division error");
    }
    obj.setRawBits((this->_rawBits << Fixed::FRACTIONAL_BITS) / other.getRawBits());
    return obj;
}

Fixed &Fixed::operator++() {
    this->_rawBits += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed before(*this);
    this->_rawBits += 1;
    return before;
}

Fixed &Fixed::operator--() {
    this->_rawBits -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed before(*this);
    this->_rawBits -= 1;
    return before;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    // std::cout << "Fixed::min" << std::endl;
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    // std::cout << "const Fixed::min" << std::endl;
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    // std::cout << "Fixed::max" << std::endl;
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    // std::cout << "const Fixed::max" << std::endl;
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
    // std::cout << "call operator<<" << std::endl;
    ostream << fixed.toFloat();
    return ostream;
}
