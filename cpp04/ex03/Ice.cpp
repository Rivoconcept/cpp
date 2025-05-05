/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:48:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/05 16:43:43 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria(ice)
{
    std::cout << "Ice: Copy constructor called" << std::endl;
    this->_type = ice._type;
}

Ice& Ice::operator=(const Ice& ice)
{
    if (this != &ice)
    {
        AMateria::operator=(ice);
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
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Ice& ice)
{
    out << "Ice (" << ice.getType() << ")" << std::endl;
    return (out);
}