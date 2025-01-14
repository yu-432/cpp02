/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:55 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/14 19:54:30 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _rawBits = value << _fractBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  _rawBits = roundf(value * (1 << _fractBits));
}

Fixed& Fixed::operator=(const Fixed& src) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &src) _rawBits = src.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return _rawBits; }

void Fixed::setRawBits(int const raw) { _rawBits = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(_rawBits) / (1 << _fractBits);
}

int Fixed::toInt(void) const { return _rawBits >> _fractBits; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& src) {
  ostream << src.toFloat();
  return ostream;
}
