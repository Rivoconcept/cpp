/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:42:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/27 13:32:03 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog: Default constructor called " << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->_brain = new Brain(*dog._brain);
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        Animal::operator=(dog);
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*dog._brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog: Destructor called " << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: WOUFFFF! WOUFFF! WOUFFFF! " << std::endl;
}

const std::string& Dog::getBrainIdea(int index) const
{
    return (this->_brain->getTabIdea(index));
}

void Dog::setBrainIdea(int index, const std::string& idea)
{
    this->_brain->setTabIdea(index, idea);
}






