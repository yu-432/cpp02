/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:05:17 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/07 13:26:47 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();
		Fixed&	operator = (const Fixed& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator << (const Fixed& src);
	private:
		int					rawBits;
		static const int	fractBits = 8;
};
