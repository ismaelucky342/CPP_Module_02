/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:55:59 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 00:54:37 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << BRIGHT_GREEN "a is " << a  << RESET << std::endl;
	std::cout << BRIGHT_GREEN "b is " << b  << RESET << std::endl;
	std::cout << BRIGHT_GREEN "c is " << c  << RESET << std::endl;
	std::cout << BRIGHT_GREEN "d is "  << d << RESET << std::endl;

	std::cout << BRIGHT_GREEN "a is " << a.toInt() << " as integer" RESET << std::endl;
	std::cout << BRIGHT_GREEN "b is " << b.toInt() << " as integer" RESET << std::endl;
	std::cout << BRIGHT_GREEN "c is " << c.toInt() << " as integer" RESET << std::endl;
	std::cout << BRIGHT_GREEN "d is " << d.toInt() << " as integer" RESET << std::endl;

	return 0;
}