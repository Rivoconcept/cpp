/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:34:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/22 18:36:04 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal: Constructor called for "<< this->_type << std::endl; 
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    std::cout << "Animal: Copy constructor called for " << animal._type << std::endl;
    *this = animal;
}

const std::string& Animal::getType( void ) const
{
    return (this->_type);
}

void Animal::setType(std::string type)
{
    this->_type = type;
}

Animal &Animal::operator=(const Animal& animal)
{
    if (this != &animal)
    {
        this->_type = animal._type;
    }
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal: The Default sound of animal" << std::endl;
}

std::ostream &operator<<(std::ostream& out, const Animal& animal)
{
    out << "The type of the Animal is a " << animal.getType();
    return (out);
}
