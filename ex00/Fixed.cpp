/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:56:43 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 22:56:43 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout	<< "Default constructor called" << std::endl;
	_value = 0;
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
	{
		_value = ref.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout	<< "getRawbits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}