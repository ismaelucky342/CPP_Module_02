/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:55:59 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 01:03:13 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/*=================================INCLUDES==================================*/

#include <iomanip>
#include <iostream>

/*=================================COLORS====================================*/


#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BRIGHT_GREEN "\033[38;5;46m"
#define WHITE "\033[37m"

/*=================================CLASS=====================================*/

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
		
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed& min(const Fixed &f1, const Fixed &f2);
		
		static Fixed& max(Fixed &f1, Fixed &f2);
		static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);

#endif