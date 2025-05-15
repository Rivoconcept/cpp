/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:40:07 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/05/14 14:40:12 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp" // Inclusion du header de l'interface IMateriaSource

// Définition du destructeur virtuel de IMateriaSource.
// Comme pour ICharacter, même un corps vide nécessite une définition
// s'il n'est pas défini inline dans le .hpp.
IMateriaSource::~IMateriaSource() {
    // std::cout << "IMateriaSource Destructor called" << std::endl; // Optionnel
    // Le corps est vide.
}

// Les méthodes learnMateria et createMateria sont virtuelles pures dans IMateriaSource.hpp,
// donc elles n'ont pas de définition ici. Elles doivent être implémentées
// par les classes concrètes comme MateriaSource.