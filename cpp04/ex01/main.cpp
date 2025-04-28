/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:41:47 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/28 18:55:49 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int size = 6;
    const int half = size / 2;
    const int ideasCount = 3;

    const std::string dogIdeas[ideasCount] = { "I want to bark", "I want to run", "I want to dig holes"};

    const std::string catIdeas[ideasCount] = {"I want to sleep", "I want to eat fish", "I want to climb trees"};

    Dog* dogs[half];
    Cat* cats[half];

    for (int i = 0; i < half; i++)
    {
        dogs[i] = new Dog();
        for (int j = 0; j < ideasCount; j++)
        {
            dogs[i]->setBrainIdea(j, dogIdeas[j]);
        }
    }

    for (int i = 0; i < half; i++)
    {
        cats[i] = new Cat();
        for (int j = 0; j < ideasCount; j++)
        {
            cats[i]->setBrainIdea(j, catIdeas[j]);
        }
    }

    std::cout << "\nDog Ideas:\n";
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < ideasCount; j++)
        {
            std::cout << "Dog[" << i << "] Idea[" << j << "]: " << dogs[i]->getBrainIdea(j) << std::endl;
        }
    }

    std::cout << "\nCat Ideas:\n";
    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < ideasCount; j++)
        {
            std::cout << "Cat[" << i << "] Idea[" << j << "]: " << cats[i]->getBrainIdea(j) << std::endl;
        }
    }

    std::cout << "\nDog Sounds:\n";
    for (int i = 0; i < half; i++)
        dogs[i]->makeSound();

    std::cout << "\nCat Sounds:\n";
    for (int i = 0; i < half; i++)
        cats[i]->makeSound();

    for (int i = 0; i < half; i++)
    {
        delete dogs[i];
        delete cats[i];
    }

    return 0;
}
