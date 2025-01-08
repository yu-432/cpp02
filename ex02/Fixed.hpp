/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:05:17 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/08 18:32:31 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator = (const Fixed& src);
		bool operator > (const Fixed& right);
		bool operator < (const Fixed& right);
		bool operator >= (const Fixed& right);
		bool operator <= (const Fixed& right);
		bool operator != (const Fixed& right);
		Fixed operator + (const Fixed& right);
		Fixed operator - (const Fixed& right);
		Fixed operator * (const Fixed& right);
		Fixed operator / (const Fixed& right);
		Fixed& operator ++ ();
		Fixed operator ++ (int);
		Fixed& operator -- ();
		Fixed operator -- (int);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					rawBits;
		static const int	fractBits = 8;
};

std::ostream& operator << (std::ostream& ostream, const Fixed& src);
