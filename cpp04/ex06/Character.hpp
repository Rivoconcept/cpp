/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:51:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:03:45 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

/*class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];

    public:
        Character(std::string const &name);
        Character(const Character &other);
        Character &operator=(const Character &other);
        virtual ~Character();

        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};*/

// Forward declaration si AMateria est définie après ICharacter, ou inclure le header.
class AMateria;

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4]; // Inventaire de 4 pointeurs vers AMateria.
    // int         _materiaCount; // Optionnel, pour suivre le nombre de materias équipées.

public:
    // Constructeur : prend le nom du personnage.
    // Initialise l'inventaire à vide (nullptr).
    Character(std::string const & name);

    // Constructeur par recopie : pour la copie profonde.
    Character(Character const & src);

    // Opérateur d'affectation : pour la copie profonde.
    Character& operator=(Character const & rhs);

    // Destructeur : doit libérer les Materias de l'inventaire.
    virtual ~Character();

    // Implémentations des fonctions de l'interface ICharacter.
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};


#endif
