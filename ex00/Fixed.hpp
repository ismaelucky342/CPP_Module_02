/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:56:39 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 22:56:40 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iomanip>
#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fract_bits = 8;
	public:
		Fixed();								// Default constructor
		Fixed(const Fixed &ref);				// Copy constructor
		Fixed &operator=(const Fixed &ref);		// Copy assignment operator
		~Fixed();								// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif