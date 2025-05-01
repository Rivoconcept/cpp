/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:34:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/01 11:06:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(): _type("Animal")
{
    std::cout << "Animal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "Animal: Constructor called for "<< this->_type << std::endl; 
}

AAnimal::~AAnimal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& animal)
{
    std::cout << "Animal: Copy constructor called for " << animal._type << std::endl;
    *this = animal;
}

const std::string& AAnimal::getType( void ) const
{
    return (this->_type);
}

void AAnimal::setType(std::string type)
{
    this->_type = type;
}

AAnimal &AAnimal::operator=(const AAnimal& animal)
{
    if (this != &animal)
    {
        this->_type = animal._type;
    }
    return (*this);
}

void AAnimal::makeSound() const
{
    std::cout << "(AAnimal makes no sound)\n" << std::endl;
}

std::ostream &operator<<(std::ostream& out, const AAnimal& animal)
{
    out << "The type of the Animal is a " << animal.getType();
    return (out);
}
