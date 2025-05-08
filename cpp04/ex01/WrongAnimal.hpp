/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:31:15 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/08 17:56:23 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& wa);
        WrongAnimal& operator=(const WrongAnimal& wa);
        virtual ~WrongAnimal();

        const std::string& getType(void) const;
        void setType(std::string type);

        void makeSound() const;
    
};

std::ostream& operator<<(std::ostream& out, const WrongAnimal& wa);

#endif