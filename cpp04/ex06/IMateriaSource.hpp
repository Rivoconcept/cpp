/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:54:48 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 14:41:03 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP // Garde d'inclusion
#define IMATERIASOURCE_HPP

#include <string> // Pour std::string dans createMateria

// Déclaration anticipée de AMateria.
// learnMateria prend un AMateria* et createMateria retourne un AMateria*.
class AMateria;

// Interface pour une source de Materias.
// Définit le contrat pour apprendre des modèles de Materias et en créer de nouvelles.
class IMateriaSource
{
public:
    // Destructeur virtuel.
    // Déclaration seulement. La définition (même vide : {}) sera dans IMateriaSource.cpp.
    virtual ~IMateriaSource();

    // --- Méthodes Virtuelles Pures ---

    // Apprend un "modèle" de Materia.
    // La source devra copier et stocker ce modèle.
    virtual void learnMateria(AMateria* m) = 0;

    // Crée et retourne une nouvelle instance de Materia basée sur un type (std::string) appris.
    // Retourne 0 (NULL) si le type est inconnu.
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURCE_HPP