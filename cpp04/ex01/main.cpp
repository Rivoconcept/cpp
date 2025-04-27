/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:41:47 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/27 14:09:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    const int size = 6;
    const Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
        {
            Dog* dog = (Dog*)animals[i];
            dog->setBrainIdea(0, "I want to play!");
            dog->setBrainIdea(1, "I want to eat!");
        }
        else
        {
            Cat* cat = (Cat*)animals[i];
            cat->setBrainIdea(0, "I want to sleep...");
            cat->setBrainIdea(1, "I want to climb the curtains!");
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
        {
            Dog* dog = (Dog*)animals[i];
            std::cout << "Dog Idea 0: " << dog->getBrainIdea(0) << std::endl;
            std::cout << "Dog Idea 1: " << dog->getBrainIdea(1) << std::endl;
        }
        else
        {
            Cat* cat = (Cat*)animals[i];
            std::cout << "Cat Idea 0: " << cat->getBrainIdea(0) << std::endl;
            std::cout << "Cat Idea 1: " << cat->getBrainIdea(1) << std::endl;
        }
    }

    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

    return (0);
}

