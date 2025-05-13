/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:54:02 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:18:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP // Garde d'inclusion
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp" // MateriaSource implémente IMateriaSource.

// class AMateria; // Déjà forward-déclaré dans IMateriaSource.hpp
                // ou AMateria.hpp serait inclus si IMateriaSource.hpp l'incluait.

// La classe MateriaSource est une implémentation concrète de IMateriaSource.
// Elle peut apprendre des Materias et en créer de nouvelles instances.
class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4]; // Stockage pour les "modèles" de Materias appris (4 maximum).
    // int       _learnedCount; // Optionnel : pour suivre le nombre de templates réellement appris.

public:
    // --- Constructeurs et Destructeur ---

    // Constructeur par défaut.
    // Déclaration seulement.
    MateriaSource();

    // Constructeur par copie.
    // (Important si une MateriaSource doit être copiée, pour copier les templates appris).
    // Déclaration seulement.
    MateriaSource(const MateriaSource& src);

    // Opérateur d'affectation.
    // Déclaration seulement.
    MateriaSource& operator=(const MateriaSource& rhs);

    // Destructeur.
    // Doit libérer les Materias "modèles" stockées.
    // Automatiquement virtuel.
    // Déclaration seulement.
    virtual ~MateriaSource();

    // --- Implémentation des Méthodes de IMateriaSource ---

    // Apprend un modèle de Materia.
    // Déclaration seulement.
    virtual void learnMateria(AMateria* m);

    // Crée une Materia à partir d'un type appris.
    // Déclaration seulement.
    virtual AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP