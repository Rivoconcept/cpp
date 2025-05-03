/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:48:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/03 15:20:44 by rhanitra         ###   ########.fr       */
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

AMateria* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Ice& ice)
{
    out << "Ice (" << ice.getType() << ")" << std::endl;
    return (out);
}