/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:51:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:44:37 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP // Garde d'inclusion
#define CHARACTER_HPP

#include "ICharacter.hpp" // Character implémente l'interface ICharacter.
#include <string>         // Pour std::string _name.

class ICharacter;

// class AMateria; // AMateria est déjà forward-déclaré dans ICharacter.hpp ou inclus.
                // Cependant, si Character utilise AMateria d'une manière qui requiert plus
                // que ce que ICharacter.hpp fournit (peu probable ici car _inventory est privé),
                // une inclusion ou forward declaration pourrait être nécessaire.
                // Pour l'inventaire de AMateria*, ICharacter.hpp est suffisant via equip/unequip/use.

// La classe Character est une implémentation concrète de ICharacter.
class Character : public ICharacter
{
private:
    std::string _name;        // Nom du personnage.
    AMateria* _inventory[4]; // Inventaire du personnage (4 Materias maximum).
                               // Stocke des pointeurs vers AMateria pour permettre le polymorphisme.

public:
    // --- Constructeurs et Destructeur ---

    // Constructeur prenant le nom du personnage.
    // Déclaration seulement.
    Character(std::string const & name);

    // Constructeur par recopie (pour la copie profonde).
    // Déclaration seulement.
    Character(Character const & src);

    // Opérateur d'affectation (pour la copie profonde).
    // Déclaration seulement.
    Character& operator=(Character const & rhs);

    // Destructeur.
    // Doit libérer les Materias de l'inventaire.
    // Automatiquement virtuel car ~ICharacter() est virtuel.
    // Déclaration seulement.
    virtual ~Character();

    // --- Implémentation des Méthodes de ICharacter ---

    // Retourne le nom du personnage.
    // Déclaration seulement.
    virtual std::string const & getName() const;

    // Équipe une Materia.
    // Déclaration seulement.
    virtual void equip(AMateria* m);

    // Déséquipe une Materia d'un emplacement (idx).
    // Déclaration seulement.
    virtual void unequip(int idx);

    // Utilise la Materia à l'emplacement [idx] sur la cible 'target'.
    // Déclaration seulement.
    virtual void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP
