/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:05:17 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/14 17:12:49 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& src);
  ~Fixed();
  Fixed& operator=(const Fixed& src);
  void setRawBits(int const raw);
  int getRawBits(void) const;

 private:
  int _rawBits;
  static const int _fractBits = 8;
};
