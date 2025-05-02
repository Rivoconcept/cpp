/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:48:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/02 17:27:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
    std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const std::string& ice) : AMateria(ice)
{
    std::cout << "Ice: Constructor called" << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria()
{
    std::cout << "Ice: Copy constructor called" << std::endl;
    *this = ice;
}

Ice& Ice::operator=(const Ice& ice)
{
    if (this != &ice)
    {
        this->_type = ice._type;
    }
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice: Destructor called" << std::endl;
}