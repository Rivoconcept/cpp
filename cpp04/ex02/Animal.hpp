/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:35:14 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/01 11:02:47 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <iostream>
# include <string>
# include <cstring>

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal& animal);
        virtual ~AAnimal();

        const std::string& getType( void ) const;
        void setType(std::string type);

        AAnimal &operator=(const AAnimal& animal);

        virtual void makeSound() const = 0;

};

std::ostream &operator<<(std::ostream& out, const AAnimal& animal);


#endif