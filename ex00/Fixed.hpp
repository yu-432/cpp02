/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:05:17 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/14 19:25:57 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& src);
  Fixed& operator=(const Fixed& src);
  ~Fixed();
  void setRawBits(int const raw);
  int getRawBits(void) const;

 private:
  int _rawBits;
  static const int _fractBits = 8;
};
