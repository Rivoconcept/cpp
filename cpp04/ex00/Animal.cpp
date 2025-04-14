/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:34:52 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/14 19:00:51 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(std::string type) : _type(type) {}

Animal::~Animal() {}

Animal::Animal(const Animal& animal)
{
    std::cout << "The Animal's copy constructor called for " << animal._type << std::endl;
    *this = animal;
}

const std::string& Animal::getType( void ) const
{
    return (this->_type);
}

Animal &Animal::operator=(const Animal& animal)
{
    if (this != &animal)
    {
        this->_type = animal._type;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream& out, const Animal& animal)
{
    out << "The type of the Animal is a " << animal.getType();
    return (out);
}
