/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:55 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/07 13:26:47 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = value << this->fractBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(value * (1 << this->fractBits));
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return this->rawBits / 256.0;
}

int		Fixed::toInt(void) const {
	return this->rawBits >> this->fractBits;
}

std::ostream&	operator << (std::ostream& ostream, const Fixed& src) {
	ostream << src.toFloat();
	return ostream;
}
