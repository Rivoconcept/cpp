/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:43:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/08 17:35:00 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& dog);
        Dog& operator=(const Dog& dog);
        ~Dog();

        void makeSound() const;
        
};

#endif