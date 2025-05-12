/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:54:48 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:04:08 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

/*class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *m) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};*/

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    // Apprend un "modèle" de Materia. La source devra la stocker.
    virtual void learnMateria(AMateria* m) = 0;
    // Crée une instance de Materia basée sur un type appris.
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
