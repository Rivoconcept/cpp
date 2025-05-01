/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:41:47 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/01 11:08:45 by rhanitra         ###   ########.fr       */
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
