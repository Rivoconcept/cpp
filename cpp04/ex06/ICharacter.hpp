/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:50:08 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:17:59 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP // Garde d'inclusion
#define ICHARACTER_HPP

#include <string> // Pour std::string utilisé par getName()

// Déclaration anticipée de AMateria.
// Nécessaire car equip() prend un AMateria* et use() peut aussi en dépendre indirectement.
class AMateria;

// Interface pour les personnages.
// Définit le contrat que toute classe de personnage concret doit respecter.
// Une classe avec au moins une fonction virtuelle pure est une classe abstraite.
class ICharacter
{
public:
    // Destructeur virtuel.
    // Crucial pour les interfaces/classes de base polymorphiques.
    // Assure que le destructeur de la classe dérivée est appelé.
    // Déclaration seulement. La définition (même vide : {}) sera dans ICharacter.cpp.
    virtual ~ICharacter();

    // --- Méthodes Virtuelles Pures ---
    // Ces méthodes DOIVENT être implémentées par les classes dérivées concrètes.

    // Retourne le nom du personnage.
    virtual std::string const & getName() const = 0;

    // Équipe une Materia (AMateria) au personnage.
    virtual void equip(AMateria* m) = 0;

    // Déséquipe une Materia à un index spécifique de l'inventaire.
    virtual void unequip(int idx) = 0;

    // Utilise la Materia à un index spécifique de l'inventaire sur une cible (target).
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP