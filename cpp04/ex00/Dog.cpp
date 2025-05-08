/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:42:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/08 17:32:03 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog: Default constructor called " << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        Animal::operator=(dog);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called " << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: WOUFFFF! WOUFFF! WOUFFFF! " << std::endl;
}