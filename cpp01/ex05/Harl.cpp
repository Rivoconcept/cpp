/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:56:11 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/21 18:50:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-\
    triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. \
    You didn’t put enough bacon in my burger! If you did, I wouldn’t be \
    asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. \
    I’ve been coming for years, whereas you started working \
    here just last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak \
    to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
    int i = 0;
    std::string params[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[])(void) =  {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    while (params[i] != level)
        i++;
    (this->*functions[i])();
}
