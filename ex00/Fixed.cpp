/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:56:43 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 00:45:24 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout	 << MAGENTA "Default constructor called" RESET << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout	<< GREEN "Copy constructor called" RESET << std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed& ref)
{
	std::cout  << GREEN "Copy assignment operator called" RESET << std::endl;
	if (this != &ref)
	{
		_value = ref.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout	<< RED "Destructor called" RESET << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout	<< CYAN "getRawbits member function called" RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}