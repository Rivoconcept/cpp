/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:59:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/01 11:10:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "Cat: Default constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& cat) : AAnimal(cat)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->_brain = new Brain(*cat._brain);
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        AAnimal::operator=(cat);
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*cat._brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: MIAOU~! MIAOU~! MIAOU~!" << std::endl;
}

const std::string& Cat::getBrainIdea(int index) const
{
    return (this->_brain->getTabIdea(index));
}

void Cat::setBrainIdea(int index, const std::string& idea)
{
    this->_brain->setTabIdea(index, idea);
}

