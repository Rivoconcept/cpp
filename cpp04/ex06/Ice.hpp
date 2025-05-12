/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:52:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:11:23 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include <ostream>

#include "AMateria.hpp"

/*class Ice : public AMateria
{
    public:
        Ice();
        virtual ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);
};*/

// Exemple pour Ice. Cure sera similaire.
class Ice : public AMateria {
    public:
        // Constructeur : appelle le constructeur de AMateria avec le type "ice".
        Ice() : AMateria("ice") {}
    
        // Destructeur : Peut être vide s'il n'y a pas de ressources spécifiques à Ice à libérer.
        // Le destructeur virtuel de AMateria s'assurera d'un nettoyage correct.
        virtual ~Ice() {} // Bonne pratique de le déclarer, même vide.
    
        // Implémentation de clone() pour Ice.
        // Retourne une nouvelle instance de Ice.
        virtual AMateria* clone() const {
            return new Ice(); // Crée un nouvel objet Ice sur le tas.
        }
    
        // Implémentation de use() pour Ice.
        // Affiche le message spécifique.
        virtual void use(ICharacter& target) {
            std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
            // Note : AMateria::use(target); pourrait être appelé ici si AMateria avait une implémentation de base,
            // mais ce n'est pas le cas ici.
        }
    };
    
    // Cure serait structurée de la même manière avec le type "cure"
    // et le message "* heals <name>’s wounds *".

#endif
