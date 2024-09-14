/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:55:59 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 22:56:13 by ismherna         ###   ########.fr       */
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
	std::cout	<< "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout	<< "Int constructor called" << std::endl;
	_value = num << _fract_bits;
}

Fixed::Fixed(const float num)
{
	std::cout	<< "Float constructor called" << std::endl;
	_value = round(num * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout	<< "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed& ref)
{
	std::cout	<< "Copy assignment operator called" << std::endl;
	if (this != &ref)
		_value = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called" << std::endl;
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