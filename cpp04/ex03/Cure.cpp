/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:48:54 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/02 17:27:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
    std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(const std::string& cure) : AMateria(cure)
{
    std::cout << "Cure: Constructor called" << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria()
{
    std::cout << "Cure: Copy constructor called" << std::endl;
    *this = cure;
}

Cure& Cure::operator=(const Cure& cure)
{
    if (this != &cure)
    {
        this->_type = cure._type;
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure: Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl; 
}

std::ostream& operator<<(std::ostream out, const Cure& cure)
{
    out << "Cure (" << cure.getType() << ")" << std::endl;
    return (out);
}