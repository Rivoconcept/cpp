/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:35:14 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/14 19:01:03 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <cstdlib>
# include <iostream>
# include <string>

class Animal
{
    private:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& animal);
        ~Animal();

        const std::string& getType( void ) const;

        Animal &operator=(const Animal& animal);

};

std::ostream &operator<<(std::ostream& out, const Animal& animal);


#endif