/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:06:43 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 01:11:26 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

/*=================================INCLUDES==================================*/

#include <string>
#include <iostream>
#include "Fixed.hpp"

/*=================================CLASS====================================*/

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
	// Constructors
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);

	// Deconstructors
		~Point();

	// Overloaded Operators
		Point &operator=(const Point &src);

	// Public Methods

	// Getter
		const Fixed &getX(void)const;
		const Fixed &getY(void)const;
	// Setter

};

// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point);

#endif