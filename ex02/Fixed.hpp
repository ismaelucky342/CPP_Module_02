/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:55:59 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 22:56:21 by ismherna         ###   ########.fr       */
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
		Fixed(const int num);
		Fixed(const float num);
		
		Fixed(const Fixed &ref);				// Copy constructor
		Fixed &operator=(const Fixed &ref);		// Copy assignment operator
		~Fixed();								// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &ref) const;
		bool	operator>=(const Fixed &ref) const;
		bool	operator<(const Fixed &ref) const;
		bool	operator<=(const Fixed &ref) const;
		bool	operator==(const Fixed &ref) const;
		bool	operator!=(const Fixed &ref) const;

		Fixed	operator+(const Fixed &ref) const;
		Fixed	operator-(const Fixed &ref) const;
		Fixed	operator*(const Fixed &ref) const;
		Fixed	operator/(const Fixed &ref) const;
		
		Fixed&	operator++(void);	//++a
		Fixed	operator++(int);	//a++
		Fixed&	operator--(void);	//--a
		Fixed	operator--(int);	//a--

		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed& min(const Fixed &f1, const Fixed &f2);
		
		static Fixed& max(Fixed &f1, Fixed &f2);
		static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);

#endif