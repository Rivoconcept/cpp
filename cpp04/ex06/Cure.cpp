/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:53:41 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 14:38:28 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"       // Inclusion du header de la classe Cure
#include "ICharacter.hpp" // Inclusion pour ICharacter utilisé dans use()
#include <iostream>       // Pour std::cout

// --- Constructeurs et Destructeur ---

// Constructeur par défaut de Cure.
// Appelle le constructeur de AMateria avec le type "cure".
Cure::Cure() : AMateria("cure") {
    // std::cout << "Cure Default Constructor called" << std::endl; // Optionnel
}

// Constructeur par copie de Cure.
// Appelle le constructeur par copie d'AMateria.
Cure::Cure(const Cure& src) : AMateria(src) {
    // std::cout << "Cure Copy Constructor called" << std::endl; // Optionnel
}

// Opérateur d'affectation de Cure.
Cure& Cure::operator=(const Cure& rhs) {
    // std::cout << "Cure Assignment Operator called" << std::endl; // Optionnel
    if (this != &rhs) {
        AMateria::operator=(rhs); // Appel de l'opérateur d'affectation de la base.
    }
    return *this;
}

// Destructeur de Cure.
Cure::~Cure() {
    // std::cout << "Cure Destructor called" << std::endl; // Optionnel
}

// --- Méthodes Publiques (Redéfinitions) ---

// Implémentation concrète de la méthode clone pour Cure.
// Crée et retourne un pointeur vers une NOUVELLE instance de Cure.
AMateria* Cure::clone() const {
    return new Cure(); // Alloue dynamiquement un nouvel objet Cure.
}

// Implémentation concrète de la méthode use pour Cure.
// Affiche le message spécifique à l'utilisation d'une Materia de type Cure sur une cible.
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}