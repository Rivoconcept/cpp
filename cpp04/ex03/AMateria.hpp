/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:19:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/02 14:35:55 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& materia);
        AMateria& operator=(const AMateria& materia);
        virtual ~AMateria();
        
        std::string const & getType() const;
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

std::ostream& operator<<(const std::ostream& out, const AMateria& materia);

#endif