/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:55 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/06 20:47:12 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->m_value = value << this->fractBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->m_value = roundf(value * (1 << this->fractBits));
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

bool Fixed::operator>(const Fixed& right) {
	return this->fractBits > right.m_value;
}

bool Fixed::operator<(const Fixed& right) {
	return this->fractBits < right.m_value;
}

bool Fixed::operator>=(const Fixed& right) {
	return this->fractBits >= right.m_value;
}

bool Fixed::operator<=(const Fixed& right) {
	return this->fractBits <= right.m_value;
}

bool Fixed::operator!=(const Fixed& right) {
	return this->fractBits != right.m_value;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->m_value;
}

void	Fixed::setRawBits(int const raw) {
	this->m_value = raw;
}

float	Fixed::toFloat(void) const {
	return this->m_value / 256.0;
}

int		Fixed::toInt(void) const {
	return this->m_value >> this->fractBits;
}

std::ostream&	operator << (std::ostream& ostream, const Fixed& src) {
	ostream << src.toFloat();
	return ostream;
}
