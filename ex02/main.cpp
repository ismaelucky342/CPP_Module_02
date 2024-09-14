/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:56:29 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 22:56:32 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f) * Fixed( 2 ) );


	std::cout << "1\t" << a << std::endl;
	std::cout << "2\t" << ++a << std::endl;
	std::cout << "3\t" << a << std::endl;
	std::cout << "4\t" << a++ << std::endl;
	std::cout << "5\t" << a << std::endl;

	std::cout << "b\t" << b << std::endl;

	std::cout << "Max\t" << Fixed::max( a, b ) << std::endl;
	
	return 0;
}