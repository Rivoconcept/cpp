/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:38:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/22 18:34:44 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal: Default construstor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal: Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa)
{
    std::cout << "WrongAnimal: Copy constructor called for " << wa.getType() << std::endl;
    *this = wa;
}

const std::string& WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal: Default Sound of WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wa)
{
    if (this != &wa)
    {  
        this->_type = wa._type;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const WrongAnimal& wa)
{
    out << "The type of the WrongAnimal is " << wa.getType();
    return (out);
}