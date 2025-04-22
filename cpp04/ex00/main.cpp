/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:41:47 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/22 18:31:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete j;
        delete i;
    }
    {
        std::cout << std::endl << "***** WrongAnimal test *****\n" << std::endl;
        const WrongAnimal* wrong = new WrongCat();

        std::cout << "Type: " << wrong->getType() << std::endl;
        wrong->makeSound(); 
        
        delete wrong;

        std::cout << std::endl << "***** Animal test *****\n" << std::endl;
        const Animal* good = new Cat();

        std::cout << "Type: " << good->getType() << std::endl;
        good->makeSound();

        delete good;
    }


    return (0);
}