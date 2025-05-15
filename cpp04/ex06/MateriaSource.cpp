/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:54:24 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 14:41:03 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp" // Inclusion du header de la classe MateriaSource
#include "AMateria.hpp"      // Inclusion pour manipuler les objets AMateria (templates)
#include <iostream>          // Pour std::cout (utilisé pour les messages de débogage/actions)

// --- Constructeurs et Destructeur ---

// Constructeur par défaut de MateriaSource.
// Initialise tous les emplacements pour les modèles (templates) à NULL.
MateriaSource::MateriaSource() {
    // std::cout << "MateriaSource Default Constructor called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        this->_templates[i] = NULL; // Marque chaque slot de template comme vide.
    }
}

// Constructeur par copie de MateriaSource.
// Assure une copie profonde des templates appris.
MateriaSource::MateriaSource(const MateriaSource& src) {
    // std::cout << "MateriaSource Copy Constructor called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (src._templates[i] != NULL) {
            // Clone chaque template de la source pour la nouvelle instance.
            this->_templates[i] = src._templates[i]->clone();
        } else {
            this->_templates[i] = NULL;
        }
    }
}

// Opérateur d'affectation de MateriaSource.
// Assure une copie profonde et gère l'auto-affectation et la libération des anciens templates.
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    // std::cout << "MateriaSource Assignment Operator called" << std::endl; // Optionnel
    if (this == &rhs) { // Protection contre l'auto-affectation.
        return *this;
    }

    // Libérer les templates existants dans 'this'.
    for (int i = 0; i < 4; ++i) {
        if (this->_templates[i] != NULL) {
            delete this->_templates[i];
            this->_templates[i] = NULL;
        }
    }

    // Copier (cloner) les templates de 'rhs'.
    for (int i = 0; i < 4; ++i) {
        if (rhs._templates[i] != NULL) {
            this->_templates[i] = rhs._templates[i]->clone();
        } else {
            this->_templates[i] = NULL;
        }
    }
    return *this;
}


// Destructeur de MateriaSource.
// Doit libérer la mémoire de tous les modèles (templates) de Materias stockés.
MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource Destructor called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (this->_templates[i] != NULL) {
            delete this->_templates[i]; // Supprime chaque template appris et stocké.
            // this->_templates[i] = NULL; // Pas critique car l'objet est détruit.
        }
    }
}

// --- Implémentation des Méthodes de IMateriaSource ---

// Apprend un "modèle" de Materia (pointée par m).
// La MateriaSource copie (clone) la Materia passée et la stocke.
// Elle peut stocker jusqu'à 4 Materias.
void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) { // On ne peut pas apprendre une Materia nulle.
        // std::cout << "MateriaSource cannot learn a null Materia." << std::endl; // Optionnel
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (this->_templates[i] == NULL) { // Premier slot de template libre trouvé.
            // "Copie la Materia passée en paramètre et la stocke en mémoire"
            // -> Cela signifie qu'on stocke un clone de 'm'.
            // La MateriaSource prend possession de ce clone.
            this->_templates[i] = m->clone();
            // std::cout << "MateriaSource learned " << m->getType() << " in template slot " << i << "." << std::endl; // Optionnel
            return; // Sortir dès que le template est appris et stocké.
        }
    }
    // Si la boucle se termine, la MateriaSource est pleine et ne peut plus apprendre.
    // std::cout << "MateriaSource's template storage is full. Cannot learn " << m->getType() << "." << std::endl; // Optionnel
    // L'énoncé ne spécifie pas de gérer la mémoire de 'm' dans ce cas (ex: delete m).
    // Si 'm' était un prototype temporaire, il pourrait y avoir une fuite si l'appelant ne le gère pas.
    // Généralement, on passe un prototype qui a sa propre gestion de cycle de vie.
}

// Crée et retourne une nouvelle instance de Materia.
// Celle-ci est une copie (clone) de celle apprise précédemment par la MateriaSource
// et dont le type correspond à la chaîne 'type' passée en paramètre.
// Retourne 0 (NULL) si le type est inconnu (non appris).
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        // Vérifie si un template existe et si son type correspond.
        if (this->_templates[i] != NULL && this->_templates[i]->getType() == type) {
            // Si un template correspondant est trouvé, retourne un clone de ce template.
            // L'appelant devient propriétaire de cette nouvelle instance de Materia.
            // std::cout << "MateriaSource creating a new " << type << " Materia." << std::endl; // Optionnel
            return this->_templates[i]->clone();
        }
    }
    // Si aucun template correspondant n'est trouvé après avoir parcouru tous les slots.
    // std::cout << "MateriaSource does not know type '" << type << "'. Cannot create Materia." << std::endl; // Optionnel
    return NULL; // Retourne 0 (NULL) comme demandé.
}