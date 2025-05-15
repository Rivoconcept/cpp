/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:38:57 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/05/14 14:39:02 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp" // Inclusion du header de l'interface ICharacter

// Définition du destructeur virtuel de ICharacter.
// Même si le corps est vide, une définition est nécessaire car il a été déclaré
// (et non défini inline avec {} dans le .hpp).
// C'est crucial pour permettre une suppression polymorphique correcte des objets
// qui implémentent cette interface.
ICharacter::~ICharacter() {
    // std::cout << "ICharacter Destructor called" << std::endl; // Optionnel
    // Le corps est vide, car une interface ne gère généralement pas de membres de données.
}

// Les autres méthodes de ICharacter (getName, equip, unequip, use) sont
// virtuelles pures (déclarées avec = 0; dans ICharacter.hpp),
// elles n'ont donc PAS de définition dans ICharacter.cpp.
// Elles DOIVENT être implémentées par les classes concrètes dérivées (comme Character).