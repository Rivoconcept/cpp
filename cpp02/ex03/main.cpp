/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:19:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 14:28:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	{
		Fixed		a;
		Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
		std::cout << std::endl;
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		Fixed c = a + b;
		std::cout << Fixed::min( b, c ) << std::endl;
		std::cout << std::endl;

	}
	{
		Fixed a(42), b(42);

		std::cout << std::endl;
		std::cout << a << " < " << b <<	 " ==> " << (a < b) << std::endl;
		std::cout << a << " > " << b <<	 " ==> " << (a > b) << std::endl;
		std::cout << a << " <= " << b << " ==> " << (a <= b) << std::endl;
		std::cout << a << " >= " << b << " ==> " << (a >= b) << std::endl;
		std::cout << a << " == " << b << " ==> " << (a == b) << std::endl;
		std::cout << a << " != " << b << " ==> " << (a != b) << std::endl;
		std::cout << std::endl;

	}
	{
		Fixed a(1.0f), b(3);
		Fixed c;

		std::cout << std::endl;
		std::cout << a << " + " << b <<	 " ==> " << (a + b) << std::endl;
		std::cout << a << " - " << b <<	 " ==> " << (a - b) << std::endl;
		std::cout << a << " * " << b << " ==> " << (a * b) << std::endl;
		std::cout << a << " / " << b << " ==> " << (a / b) << std::endl;
		std::cout << std::endl;
		c = (a / b) * b;
		std::cout << c << std::endl;
		std::cout << std::endl;

	}

	return 0;
}
