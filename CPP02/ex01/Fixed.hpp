#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed(const int num);
    Fixed(const float num);
    Fixed &operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

  private:
    int _rawBits;
    static const int FRACTIONAL_BITS = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
