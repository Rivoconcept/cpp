/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:19:28 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/03 15:20:12 by rhanitra         ###   ########.fr       */
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

AMateria::AMateria(const AMateria& materia)
{
    std::cout << "Materia: Copy constructor called";
    *this = materia;
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

std::ostream& operator<<(std::ostream& out, const AMateria& m)
{
    out << "Materia(" << m.getType() << ")" << std::endl;
    return (out);
}