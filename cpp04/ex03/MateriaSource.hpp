/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:49:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/03 15:38:21 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& ms);
        MateriaSource& operator=(const MateriaSource& ms);
        virtual ~MateriaSource();
        
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};


#endif