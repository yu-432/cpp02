/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:55 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/08 18:36:43 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed::Fixed(const int value) {
	this->setRawBits(value << this->fractBits);
}

Fixed::Fixed(const float value) {
	this->setRawBits(roundf(value * (1 << this->fractBits)));
}

Fixed& Fixed::operator = (const Fixed& src) {
	this->setRawBits(src.getRawBits());
	return *this;
}

bool Fixed::operator > (const Fixed& right) {
	return this->getRawBits() > right.getRawBits();
}

bool Fixed::operator < (const Fixed& right) {
	return this->getRawBits() < right.getRawBits();
}

bool Fixed::operator >= (const Fixed& right) {
	return this->getRawBits() >= right.getRawBits();
}

bool Fixed::operator <= (const Fixed& right) {
	return this->getRawBits() <= right.getRawBits();
}

bool Fixed::operator != (const Fixed& right) {
	return this->getRawBits() != right.getRawBits();
}

Fixed Fixed::operator + (const Fixed& right) {
	Fixed res(this->toFloat() + right.toFloat());
	return res;
}

Fixed Fixed::operator - (const Fixed& right) {
	Fixed res(this->toFloat() - right.toFloat());
	return res;
}

Fixed Fixed::operator * (const Fixed& right) {
	Fixed res(this->toFloat() * right.toFloat());
	return res;
}

Fixed Fixed::operator / (const Fixed& right) {
	Fixed res(this->toFloat() / right.toFloat());
	return res;
}

Fixed& Fixed::operator ++ () {
	this->setRawBits(this->getRawBits()+1);
	return *this;
}

Fixed Fixed::operator ++ (int) {
	Fixed temp = *this;
	this->setRawBits(this->getRawBits()+1);
	return temp;
}

Fixed& Fixed::operator -- () {
	this->setRawBits(this->getRawBits()-1);
	return *this;
}

Fixed Fixed::operator -- (int) {
	Fixed temp = *this;
	this->setRawBits(this->getRawBits()-1);
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits(void) const {
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return this->getRawBits() / 256.0;
}

int		Fixed::toInt(void) const {
	return this->getRawBits() >> this->fractBits;
}

std::ostream&	operator << (std::ostream& ostream, const Fixed& src) {
	ostream << src.toFloat();
	return ostream;
}
