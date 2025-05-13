/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:53:41 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 11:41:25 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

/*Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria *Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}*/

#include "Cure.hpp"      // Header pour Cure
#include "ICharacter.hpp" // Pour le paramètre de use() et target.getName()
#include <iostream>      // Pour std::cout

// Constructeur de Cure
// Appelle le constructeur de la classe de base (AMateria) avec le type "cure".
Cure::Cure() : AMateria("cure") {
    // std::cout << "Cure default constructor called" << std::endl; // Optionnel
}

// Constructeur par copie de Cure
Cure::Cure(const Cure& src) : AMateria(src) { // Appelle le constructeur par copie de AMateria
    // std::cout << "Cure copy constructor called" << std::endl; // Optionnel
}

// Opérateur d'affectation de Cure
Cure& Cure::operator=(const Cure& rhs) {
    // std::cout << "Cure assignment operator called" << std::endl; // Optionnel
    if (this != &rhs) {
        AMateria::operator=(rhs); // Appelle l'opérateur d'affectation de la classe de base
    }
    return *this;
}

// Destructeur de Cure
Cure::~Cure() {
    // std::cout << "Cure destructor called" << std::endl; // Optionnel
}

// Implémentation de la méthode clone() pour Cure.
// Doit retourner une nouvelle instance de Cure, allouée dynamiquement.
AMateria* Cure::clone() const {
    return new Cure(); // Crée et retourne un pointeur vers un nouvel objet Cure.
}

// Implémentation de la méthode use() pour Cure.
// Affiche le message spécifique à l'utilisation d'une Materia de type Cure.
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
