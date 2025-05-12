/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:52:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:07:12 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

/*Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria *Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}*/

#include "Ice.hpp"       // Header pour Ice
#include "ICharacter.hpp" // Pour le paramètre de use() et target.getName()
#include <iostream>      // Pour std::cout

// Constructeur de Ice
// Appelle le constructeur de la classe de base (AMateria) avec le type "ice".
Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice default constructor called" << std::endl; // Optionnel
}

// Constructeur par copie de Ice
Ice::Ice(const Ice& src) : AMateria(src) { // Appelle le constructeur par copie de AMateria
    // std::cout << "Ice copy constructor called" << std::endl; // Optionnel
    // Pas d'autres membres à copier spécifiquement dans Ice, AMateria s'en charge.
}

// Opérateur d'affectation de Ice
Ice& Ice::operator=(const Ice& rhs) {
    // std::cout << "Ice assignment operator called" << std::endl; // Optionnel
    if (this != &rhs) {
        AMateria::operator=(rhs); // Appelle l'opérateur d'affectation de la classe de base
        // Pas d'autres membres à affecter spécifiquement dans Ice.
    }
    return *this;
}


// Destructeur de Ice
// Peut être vide si Ice ne gère pas de ressources spécifiques
// qui ne sont pas déjà gérées par AMateria.
Ice::~Ice() {
    // std::cout << "Ice destructor called" << std::endl; // Optionnel
}

// Implémentation de la méthode clone() pour Ice.
// Doit retourner une nouvelle instance de Ice, allouée dynamiquement.
// 'const' car cette méthode ne modifie pas l'objet sur lequel elle est appelée.
AMateria* Ice::clone() const {
    return new Ice(); // Crée et retourne un pointeur vers un nouvel objet Ice.
}

// Implémentation de la méthode use() pour Ice.
// Affiche le message spécifique à l'utilisation d'une Materia de type Ice.
void Ice::use(ICharacter& target) {
    // target.getName() appelle la méthode getName() de l'objet ICharacter
    // pour obtenir le nom du personnage cible.
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
