/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:54:24 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:08:15 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        _templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_templates[i])
                delete _templates[i];
            _templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] == NULL)
        {
            _templates[i] = m->clone();
            delete m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return NULL;
}*/
#include "MateriaSource.hpp" // Header pour MateriaSource
#include "AMateria.hpp"      // Pour manipuler les AMateria (templates)
#include <iostream>          // Pour std::cout (optionnel, pour débogage)

// Constructeur de MateriaSource
// Initialise tous les templates à nullptr.
MateriaSource::MateriaSource() {
    // std::cout << "MateriaSource default constructor called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        this->_templates[i] = nullptr;
    }
}

// Constructeur par copie de MateriaSource
MateriaSource::MateriaSource(const MateriaSource& src) {
    // std::cout << "MateriaSource copy constructor called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (src._templates[i] != nullptr) {
            this->_templates[i] = src._templates[i]->clone(); // Copie profonde des templates
        } else {
            this->_templates[i] = nullptr;
        }
    }
}

// Opérateur d'affectation de MateriaSource
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    // std::cout << "MateriaSource assignment operator called" << std::endl; // Optionnel
    if (this != &rhs) {
        // 1. Libérer les templates existants
        for (int i = 0; i < 4; ++i) {
            if (this->_templates[i] != nullptr) {
                delete this->_templates[i];
                this->_templates[i] = nullptr;
            }
        }
        // 2. Copier les templates de la source (rhs) en les clonant
        for (int i = 0; i < 4; ++i) {
            if (rhs._templates[i] != nullptr) {
                this->_templates[i] = rhs._templates[i]->clone();
            } else {
                this->_templates[i] = nullptr;
            }
        }
    }
    return *this;
}


// Destructeur de MateriaSource
// Doit libérer la mémoire des Materias "modèles" stockées.
MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource destructor called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (this->_templates[i] != nullptr) {
            delete this->_templates[i]; // Supprime chaque template appris.
            this->_templates[i] = nullptr;
        }
    }
}

// Apprend un "modèle" de Materia.
// Copie la Materia passée et la stocke.
void MateriaSource::learnMateria(AMateria* m) {
    if (m == nullptr) { // Si la Materia à apprendre est nulle, on ne fait rien.
        // std::cout << "MateriaSource cannot learn a null Materia." << std::endl; // Optionnel
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (this->_templates[i] == nullptr) { // Premier slot libre trouvé.
            // "Copie la Materia passée en paramètre et la stocke en mémoire"
            // Cela signifie qu'on ne stocke pas 'm' directement, mais un clone de 'm'.
            // La MateriaSource possède ce clone. L'original 'm' n'est pas géré ici.
            this->_templates[i] = m->clone();
            // std::cout << "MateriaSource learned " << m->getType() << " in template slot " << i << std::endl; // Optionnel
            return; // Sortir dès que le template est appris.
        }
    }
    // Si on arrive ici, la MateriaSource est pleine et ne peut plus apprendre.
    // std::cout << "MateriaSource is full. Cannot learn " << m->getType() << std::endl; // Optionnel
    // L'énoncé ne spécifie pas de gérer 'm' dans ce cas (ex: delete m).
    // Si 'm' était créé juste pour être appris, et que l'apprentissage échoue,
    // cela pourrait être une fuite si l'appelant ne le gère pas.
    // Cependant, souvent on passe un prototype existant qui n'est pas à supprimer par learnMateria.
}

// Crée une nouvelle Materia basée sur un type appris.
// Retourne une nouvelle instance de la Materia (un clone du template).
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (this->_templates[i] != nullptr && this->_templates[i]->getType() == type) {
            // Si un template correspond au type demandé, on retourne un clone de ce template.
            // L'appelant devient propriétaire de cette nouvelle Materia.
            // std::cout << "MateriaSource creating " << type << " from template slot " << i << std::endl; // Optionnel
            return this->_templates[i]->clone();
        }
    }
    // Si aucun template correspondant n'est trouvé.
    // std::cout << "MateriaSource does not know type " << type << ". Cannot create." << std::endl; // Optionnel
    return nullptr; // Retourne 0 (nullptr) si le type est inconnu.
}

