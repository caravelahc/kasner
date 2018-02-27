#include "integer.h"

namespace kasner {

integer::integer()
{
    mpz_init(mpz);
}

integer::integer(double value)
{
    mpz_init_set_d(mpz, value);
}

integer::integer(const integer& that)
{
    mpz_init_set(mpz, that.mpz);
}

integer::integer(integer&& that)
{
    mpz_init(mpz);
    swap(that);
}

integer::~integer() {
    mpz_clear(mpz);
}

void integer::swap(integer& that)
{
    mpz_swap(mpz, that.mpz);
}

integer& integer::operator=(const integer& rhs)
{
    mpz_set(mpz, rhs.mpz);
    return *this;
}

integer& integer::operator=(integer&& rhs)
{
    swap(rhs);
    return *this;
}

bool operator==(const integer& lhs, const integer& rhs)
{
    return mpz_cmp(lhs.mpz, rhs.mpz) == 0;
}

bool operator!=(const integer& lhs, const integer& rhs)
{
    return not (lhs == rhs);
}

bool operator<(const integer& lhs, const integer& rhs)
{
    return mpz_cmp(lhs.mpz, rhs.mpz) < 0;
}

bool operator>(const integer& lhs, const integer& rhs)
{
    return mpz_cmp(lhs.mpz, rhs.mpz) > 0;
}

bool operator<=(const integer& lhs, const integer& rhs)
{
    return mpz_cmp(lhs.mpz, rhs.mpz) <= 0;
}

bool operator>=(const integer& lhs, const integer& rhs)
{
    return mpz_cmp(lhs.mpz, rhs.mpz) >= 0;
}

integer operator+(integer lhs, const integer& rhs)
{
    return lhs += rhs;
}

integer operator-(integer that)
{
    mpz_neg(that.mpz, that.mpz);
    return that;
}

integer& integer::operator+=(const integer& rhs)
{
    mpz_add(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator-(integer lhs, const integer& rhs)
{
    return lhs -= rhs;
}

integer& integer::operator-=(const integer& rhs)
{
    mpz_sub(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator*(integer lhs, const integer& rhs)
{
    return lhs *= rhs;
}

integer& integer::operator*=(const integer& rhs)
{
    mpz_mul(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator/(integer lhs, const integer& rhs)
{
    return lhs /= rhs;
}

integer& integer::operator/=(const integer& rhs)
{
    mpz_tdiv_q(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator%(integer lhs, const integer& rhs)
{
    return lhs %= rhs;
}

integer& integer::operator%=(const integer& rhs)
{
    mpz_mod(mpz, mpz, rhs.mpz);
    return *this;
}

integer pow(integer base, unsigned long int iexp)
{
    return base.pow(iexp);
}

integer& integer::pow(unsigned long int iexp)
{
    mpz_pow_ui(mpz, mpz, iexp);
    return *this;
}

integer& integer::operator++()
{
    mpz_add_ui(mpz, mpz, 1);
    return (*this);
}

integer integer::operator++(int)
{
    auto tmp = integer{*this};
    ++(*this);
    return tmp;
}

integer& integer::operator--()
{
    mpz_sub_ui(mpz, mpz, 1);
    return (*this);
}

integer integer::operator--(int)
{
    auto tmp = integer{*this};
    --(*this);
    return tmp;
}

bool integer::operator!() const
{
    return mpz_cmp_si(mpz, 0) == 0;
}

integer operator&(integer lhs, const integer& rhs)
{
    return lhs &= rhs;
}

integer& integer::operator&=(const integer& rhs)
{
    mpz_and(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator|(integer lhs, const integer& rhs)
{
    return lhs |= rhs;
}

integer& integer::operator|=(const integer& rhs)
{
    mpz_ior(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator^(integer lhs, const integer& rhs)
{
    return lhs ^= rhs;
}

integer& integer::operator^=(const integer& rhs)
{
    mpz_xor(mpz, mpz, rhs.mpz);
    return *this;
}

integer operator~(integer that)
{
    mpz_com(that.mpz, that.mpz);
    return that;
}

integer operator<<(integer lhs, unsigned long int rhs)
{
    return lhs <<= rhs;
}

integer& integer::operator<<=(unsigned long int rhs)
{
    auto base = integer{2};
    return operator*=(base.pow(rhs));
}

integer operator>>(integer lhs, unsigned long int rhs)
{
    return lhs >>= rhs;
}

integer& integer::operator>>=(unsigned long int rhs)
{
    auto base = integer{2};
    return operator/=(base.pow(rhs));
}

integer::operator int() const
{
    return mpz_get_si(mpz);
}

integer::operator unsigned int() const
{
    return mpz_get_ui(mpz);
}

integer::operator double() const
{
    return mpz_get_d(mpz);
}

integer::operator std::string() const
{
    return mpz_get_str(nullptr, 10, mpz);
}

}
