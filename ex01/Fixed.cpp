/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:55:59 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 00:49:11 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

double round(double d)
{
	return floor(d + 0.5);
}

Fixed::Fixed()
{
	std::cout	<< GREEN "Default constructor called" RESET << std::endl;
	_value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout	<< CYAN "Int constructor called"  RESET << std::endl;
	_value = num << _fract_bits;
}

Fixed::Fixed(const float num)
{
	std::cout	<< YELLOW "Float constructor called" RESET << std::endl;
	_value = round(num * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout	<< MAGENTA "Copy constructor called" RESET << std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed& ref)
{
	std::cout	<< BLUE "Copy assignment operator called" RESET << std::endl;
	if (this != &ref)
		_value = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout	<< RED "Destructor called" RESET << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << _fract_bits);
}

int		Fixed::toInt() const
{
	return (_value >> _fract_bits);
}

std::ostream & operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}