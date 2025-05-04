/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:49:13 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/02 17:15:52 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H
# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& cure);
        Cure& operator=(const Cure& cure);
        ~Cure();
        
        AMateria* clone() const;
        void use(ICharacter& target);
};

std::ostream& operator<<(std::ostream& out, const Cure& cure);

#endif