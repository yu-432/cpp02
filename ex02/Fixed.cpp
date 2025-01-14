/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:55 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/14 17:00:07 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed& src) { *this = src; }

Fixed::Fixed(const int value) { _rawBits = value << _fractBits; }

Fixed::Fixed(const float value) {
  _rawBits = ( static_cast<float>(value) * (1 << _fractBits));
}

Fixed& Fixed::operator=(const Fixed& src) {
  _rawBits = src._rawBits;
  return *this;
}

bool Fixed::operator>(const Fixed& right) {
  return _rawBits > right._rawBits;
}

bool Fixed::operator<(const Fixed& right) {
  return _rawBits < right._rawBits;
}

bool Fixed::operator>=(const Fixed& right) {
  return _rawBits >= right._rawBits;
}

bool Fixed::operator<=(const Fixed& right) {
  return _rawBits <= right._rawBits;
}

bool Fixed::operator==(const Fixed& right) {
  return _rawBits == right._rawBits;
}

bool Fixed::operator!=(const Fixed& right) {
  return _rawBits != right._rawBits;
}

Fixed Fixed::operator+(const Fixed& right) {
  Fixed res(this->toFloat() + right.toFloat());
  return res;
}

Fixed Fixed::operator-(const Fixed& right) {
  Fixed res(this->toFloat() - right.toFloat());
  return res;
}

Fixed Fixed::operator*(const Fixed& right) {
  Fixed res(this->toFloat() * right.toFloat());
  return res;
}

Fixed Fixed::operator/(const Fixed& right) {
  Fixed res(this->toFloat() / right.toFloat());
  return res;
}

Fixed& Fixed::operator++() {
  _rawBits = _rawBits + 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  _rawBits = _rawBits + 1;
  return temp;
}

Fixed& Fixed::operator--() {
  _rawBits = _rawBits - 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  _rawBits = _rawBits - 1;
  return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a._rawBits < b._rawBits) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a._rawBits < b._rawBits) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return (a._rawBits > b._rawBits) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a._rawBits > b._rawBits) ? a : b;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return _rawBits; }

void Fixed::setRawBits(int const raw) { _rawBits = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(_rawBits) / (1 << _fractBits); }

int Fixed::toInt(void) const { return _rawBits >> _fractBits; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& src) {
  ostream << src.toFloat();
  return ostream;
}
