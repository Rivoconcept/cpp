/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:48:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 14:56:55 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

/*class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const &type);
        virtual ~AMateria();

        std::string const &getType() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};*/

class AMateria
{
protected:
    std::string _type; // Le type de la Materia (ex: "ice", "cure")
                       // Protégé pour que les classes filles y aient accès, mais pas le monde extérieur directement.

public:
    // Constructeur : Initialise le type de la Materia.
    AMateria(std::string const & type) : _type(type) {}

    // Destructeur virtuel : TRÈS IMPORTANT !
    // Si vous manipulez des objets Materia via des pointeurs AMateria*
    // et que vous faites un delete sur ce pointeur, sans destructeur virtuel,
    // seul le destructeur de AMateria serait appelé, pas celui de la classe dérivée (Ice, Cure).
    // Cela peut entraîner des fuites de mémoire si les classes dérivées ont des ressources à libérer.
    // Même s'il est vide ici, sa présence est cruciale.
    virtual ~AMateria() {}

    // Getter pour le type. Const car ne modifie pas l'objet.
    std::string const & getType() const { return this->_type; }

    // Fonction virtuelle pure : clone()
    // Chaque Materia concrète (Ice, Cure) DOIT implémenter cette fonction.
    // Son but est de retourner une NOUVELLE instance du même type que l'objet actuel.
    // Essentiel pour la copie polymorphique (ex: copier un inventaire de Materias).
    // Const car cloner ne modifie pas l'original.
    virtual AMateria* clone() const = 0;

    // Fonction virtuelle : use()
    // Permet à une Materia d'agir sur un personnage cible.
    // Elle n'est pas purement virtuelle ici (pas de "= 0"), ce qui signifie qu'AMateria
    // pourrait avoir une implémentation par défaut (bien que ce ne soit pas demandé ici).
    // Les classes dérivées vont la redéfinir (override) pour avoir un comportement spécifique.
    virtual void use(ICharacter& target); // L'implémentation sera spécifique à Ice et Cure.
                                         // On peut laisser le corps vide dans AMateria.cpp si elle n'a pas de comportement par défaut.
};

#endif
