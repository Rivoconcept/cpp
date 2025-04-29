/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:35:14 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/29 17:53:25 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <iostream>
# include <string>
# include <cstring>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& animal);
        virtual ~Animal();

        const std::string& getType( void ) const;
        void setType(std::string type);

        Animal &operator=(const Animal& animal);

        virtual void makeSound() const;

};

std::ostream &operator<<(std::ostream& out, const Animal& animal);


#endif