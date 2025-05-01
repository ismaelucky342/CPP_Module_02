/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:56:29 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 01:05:15 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f) * Fixed( 2 ) );


	std::cout << CYAN "1. Original a:\t\t" RESET << BRIGHT_GREEN << a << RESET << std::endl;
	std::cout << CYAN "2. a at ++a:\t\t" RESET << BRIGHT_GREEN << ++a << RESET << std::endl;
	std::cout << CYAN "3. a after ++a:\t\t" RESET <<BRIGHT_GREEN <<  a << RESET <<std::endl;
	std::cout << CYAN "4. tis at a++:\t\t" RESET << BRIGHT_GREEN <<  a++ << RESET << std::endl;
	std::cout << CYAN "5. tis after a++:\t" RESET << BRIGHT_GREEN << a << RESET << std::endl;
	std::cout << CYAN "6. b value: \t\t" RESET << BRIGHT_GREEN << b << RESET << std::endl; 
	std::cout << CYAN "7. Max(a,b): \t\t" RESET << BRIGHT_GREEN << Fixed::max(a, b) << RESET << std::endl;
	std::cout << CYAN "8. Min(a,b): \t\t" RESET << BRIGHT_GREEN << Fixed::min(a, b) << RESET << std::endl;

	return 0;
}