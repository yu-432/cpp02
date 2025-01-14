/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:55 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/14 17:08:36 by yooshima         ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed& src) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &src)
    _rawBits = src._rawBits;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _rawBits = raw;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _rawBits;
}
