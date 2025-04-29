/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:41:47 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/29 19:24:36 by rhanitra         ###   ########.fr       */
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


int main()
{
    const int ideasCount = 6;
    const std::string Ideas[ideasCount] = {"Dog: I want to dig holes", "Dog: I want to bark", "Cat: I want to sleep", "Dog: I want to run", "Cat: I want to eat fish", "Cat: I want to climb trees"};
    
    int i = 0;
    int j = 0;
    int catCount = 0;
    int dogCount = 0;
    
    for (int i = 0; i < ideasCount; i++)
    {
        if (Ideas[i].rfind("Dog", 0) == 0)
            dogCount++;
        if (Ideas[i].rfind("Cat", 0) == 0)
            catCount++;
    }
    
    Dog* dogs[dogCount];
    Cat* cats[catCount];
    
    for (int k = 0; k < ideasCount; k++)
    {
        if (Ideas[k].rfind("Dog", 0) == 0)
        {
            dogs[i] = new Dog();
            dogs[i]->setBrainIdea(i, Ideas[k]);
            i++;
        }
        if (Ideas[k].rfind("Cat", 0) == 0)
        {
            cats[j] = new Cat();
            cats[j]->setBrainIdea(j, Ideas[k]);
            j++;
        }
    }
    
    for (int i = 0; i < catCount; i++)
    {
        std::cout << "\n";
        cats[i]->makeSound();
        std::cout << cats[i]->getBrainIdea(i) << std::endl;
    }

    for (int i = 0; i < dogCount; i++)
    {
        std::cout << "\n";
        dogs[i]->makeSound();
        std::cout << dogs[i]->getBrainIdea(i) << std::endl;
        std::cout << "\n";
    }

    for (int i = 0; i < dogCount; i++)
        delete dogs[i];
    for (int i = 0; i < catCount; i++)
        delete cats[i];

    return 0;
}



/*
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
}*/
