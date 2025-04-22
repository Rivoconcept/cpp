/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:42:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/22 18:35:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog: Default constructor called " << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called " << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: WOUFFFF! WOUFFF! WOUFFFF! " << std::endl;
}