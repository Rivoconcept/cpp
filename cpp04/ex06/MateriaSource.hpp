/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:54:02 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:04:52 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

/*class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_templates[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};*/

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4]; // Stockage pour les "modèles" de Materias appris.
    // int       _learnedCount; // Optionnel, pour suivre le nombre de templates appris.

public:
    // Constructeur : initialise les templates à nullptr.
    MateriaSource();

    // Destructeur : doit libérer les Materias "modèles" stockées.
    virtual ~MateriaSource();

    // (Optionnel mais bonne pratique : constructeur de copie et op. d'affectation si nécessaires,
    // ils devraient aussi faire des copies profondes des templates en utilisant clone())

    // Implémentations des fonctions de l'interface IMateriaSource.
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
