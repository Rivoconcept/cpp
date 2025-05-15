/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:52:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 14:36:54 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"        // Inclusion du header de la classe Ice
#include "ICharacter.hpp" // Inclusion pour ICharacter utilisé dans use()
#include <iostream>       // Pour std::cout

// --- Constructeurs et Destructeur ---

// Constructeur par défaut de Ice.
// Appelle le constructeur de la classe de base AMateria avec le type "ice".
Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice Default Constructor called" << std::endl; // Optionnel
}

// Constructeur par copie de Ice.
// Appelle le constructeur par copie de AMateria pour copier les membres de la classe de base.
Ice::Ice(const Ice& src) : AMateria(src) {
    // std::cout << "Ice Copy Constructor called" << std::endl; // Optionnel
    // Si Ice avait des membres propres, ils seraient copiés ici.
}

// Opérateur d'affectation de Ice.
Ice& Ice::operator=(const Ice& rhs) {
    // std::cout << "Ice Assignment Operator called" << std::endl; // Optionnel
    if (this != &rhs) { // Protection contre l'auto-affectation
        AMateria::operator=(rhs); // Appel de l'opérateur d'affectation de la classe de base
                                  // pour copier les parties héritées d'AMateria.
        // Si Ice avait des membres propres, ils seraient affectés ici.
    }
    return *this;
}

// Destructeur de Ice.
// Le corps peut être vide si Ice ne gère pas de ressources allouées dynamiquement spécifiques.
Ice::~Ice() {
    // std::cout << "Ice Destructor called" << std::endl; // Optionnel
}

// --- Méthodes Publiques (Redéfinitions) ---

// Implémentation concrète de la méthode clone pour Ice.
// Crée et retourne un pointeur vers une NOUVELLE instance de Ice.
// L'appelant devient propriétaire de la mémoire allouée.
AMateria* Ice::clone() const {
    return new Ice(); // Alloue dynamiquement un nouvel objet Ice.
}

// Implémentation concrète de la méthode use pour Ice.
// Affiche le message spécifique à l'utilisation d'une Materia de type Ice sur une cible.
void Ice::use(ICharacter& target) {
    // target.getName() est appelée pour obtenir le nom du personnage cible.
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}