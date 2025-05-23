/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:49:13 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/04 15:37:03 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H
# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& ice);
        Ice& operator=(const Ice& ice);
        ~Ice();
        
        AMateria* clone() const;
        void use(ICharacter& target);
};

std::ostream& operator<<(std::ostream& out, const Ice& ice);

#endif