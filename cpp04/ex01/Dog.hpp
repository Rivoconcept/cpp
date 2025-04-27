/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:43:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/27 13:31:40 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;

    public:
        Dog();
        Dog(const Dog& dog);
        Dog& operator=(const Dog& dog);
        ~Dog();

        void makeSound() const;
        
        const std::string& getBrainIdea(int index) const;
        void setBrainIdea(int index, const std::string& idea);
        
};

#endif