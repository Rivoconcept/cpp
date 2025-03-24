/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:56:11 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:35:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!"
				<< std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be \
asking for more!"
				<< std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years, whereas you started working \
here just last month."
				<< std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak \
to the manager now."
				<< std::endl;
}

void Harl::complain(std::string level)
{
	int	i;

	i = 0;
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptrFunc)(void) = NULL;
	while (i < 4 && levels[i] != level)
		i++;
	for (; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			ptrFunc = &Harl::debug;
			break ;
		case 1:
			ptrFunc = &Harl::info;
			break ;
		case 2:
			ptrFunc = &Harl::warning;
			break ;
		case 3:
			ptrFunc = &Harl::error;
			break ;
		default:
			return ;
		}
		(this->*ptrFunc)();
	}
}
