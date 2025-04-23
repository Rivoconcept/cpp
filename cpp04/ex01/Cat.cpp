/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:59:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/22 18:34:11 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: MIAOU~! MIAOU~! MIAOU~!" << std::endl;
}
