#pragma once

#include <string>
#include <type_traits>

#include <gmp.h>

namespace kasner {

class integer {
public:

    // ctors and dtor
    integer();

    template<class Int, typename std::enable_if<
        std::is_fundamental<Int>::value and
        std::is_integral<Int>::value and
        std::is_signed<Int>::value,
    Int>::type = 0>
    integer(Int value)
    {
        mpz_init_set_si(mpz, value);
    }

    template<class UInt, typename std::enable_if<
        std::is_fundamental<UInt>::value and
        std::is_integral<UInt>::value and
        not std::is_signed<UInt>::value,
    UInt>::type = 0>
    integer(UInt value)
    {
        mpz_init_set_ui(mpz, value);
    }

    integer(double value);
    integer(const integer& that);
    integer(integer&& that);

    ~integer();

    void swap(integer& that);

    // comparison
    friend bool operator==(const integer& lhs, const integer& rhs);
    friend bool operator!=(const integer& lhs, const integer& rhs);
    friend bool operator<(const integer& lhs, const integer& rhs);
    friend bool operator>(const integer& lhs, const integer& rhs);
    friend bool operator<=(const integer& lhs, const integer& rhs);
    friend bool operator>=(const integer& lhs, const integer& rhs);

    // arithmetic
    integer& operator=(const integer& rhs);
    integer& operator=(integer&& rhs);
    friend integer operator-(integer that);
    friend integer operator+(integer lhs, const integer& rhs);
    integer& operator+=(const integer& rhs);
    friend integer operator-(integer lhs, const integer& rhs);
    integer& operator-=(const integer& rhs);
    friend integer operator*(integer lhs, const integer& rhs);
    integer& operator*=(const integer& rhs);
    friend integer operator/(integer lhs, const integer& rhs);
    integer& operator/=(const integer& rhs);
    friend integer operator%(integer lhs, const integer& rhs);
    integer& operator%=(const integer& rhs);
    friend integer pow(const integer& base, unsigned long int iexp);
    integer& pow(unsigned long int iexp);

    // increment and decrement
    integer& operator++();
    integer operator++(int);
    integer& operator--();
    integer operator--(int);

    // logical
    bool operator!() const;

    // bitwise
    friend integer operator&(integer lhs, const integer& rhs);
    integer& operator&=(const integer& rhs);
    friend integer operator|(integer lhs, const integer& rhs);
    integer& operator|=(const integer& rhs);
    friend integer operator^(integer lhs, const integer& rhs);
    integer& operator^=(const integer& rhs);
    friend integer operator~(integer lhs);
    friend integer operator<<(integer lhs, unsigned long int rhs);
    integer& operator<<=(unsigned long int rhs);
    friend integer operator>>(integer lhs, unsigned long int rhs);
    integer& operator>>=(unsigned long int rhs);

    // conversion
    explicit operator int() const;
    explicit operator unsigned int() const;
    explicit operator double() const;
    explicit operator std::string() const;

private:
    mpz_t mpz;
};

}
