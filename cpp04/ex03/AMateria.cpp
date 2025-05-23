/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:19:28 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/04 14:48:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Materia: Default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type)
{
    this->_type = type;
    std::cout << "Materia: Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << "Materia: Copy constructor called";
}

AMateria& AMateria::operator=(const AMateria& materia)
{
    if (this != &materia)
    {
        this->_type = materia._type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "Materia: Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target) {
    (void)target;
}

std::ostream& operator<<(std::ostream& out, const AMateria& m)
{
    out << "Materia(" << m.getType() << ")" << std::endl;
    return (out);
}