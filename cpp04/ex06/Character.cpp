/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:51:36 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:07:51 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

/*Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
                delete _inventory[i];
            _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}*/

#include "Character.hpp" // Header pour Character
#include "AMateria.hpp"  // Pour manipuler les AMateria dans l'inventaire
#include <iostream>      // Pour std::cout (optionnel, pour débogage)

// Constructeur de Character
// Initialise le nom et met tous les emplacements de l'inventaire à nullptr.
Character::Character(std::string const & name) : _name(name) {
    // std::cout << "Character constructor called for: " << this->_name << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        this->_inventory[i] = nullptr; // Marque chaque slot comme vide.
    }
}

// Constructeur par recopie de Character (copie profonde)
Character::Character(Character const & src) : _name(src._name) {
    // std::cout << "Character copy constructor called for: " << src._name << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (src._inventory[i] != nullptr) {
            // Si la source a une Materia dans ce slot, on la clone.
            // this->_inventory[i] reçoit un pointeur vers une NOUVELLE Materia,
            // qui est une copie de celle de la source.
            this->_inventory[i] = src._inventory[i]->clone();
        } else {
            this->_inventory[i] = nullptr; // Sinon, le slot reste vide.
        }
    }
}

// Opérateur d'affectation de Character (copie profonde)
Character& Character::operator=(Character const & rhs) {
    // std::cout << "Character assignment operator called for: " << this->_name << " from " << rhs._name << std::endl; // Optionnel
    // 1. Vérifier l'auto-affectation
    if (this == &rhs) {
        return *this;
    }

    // 2. Libérer les ressources existantes de l'objet courant (this)
    for (int i = 0; i < 4; ++i) {
        if (this->_inventory[i] != nullptr) {
            delete this->_inventory[i]; // Supprime l'ancienne Materia.
            this->_inventory[i] = nullptr; // Important de remettre à nullptr.
        }
    }

    // 3. Copier les données simples (le nom)
    this->_name = rhs._name;

    // 4. Copier les ressources de l'objet source (rhs) en les clonant
    for (int i = 0; i < 4; ++i) {
        if (rhs._inventory[i] != nullptr) {
            this->_inventory[i] = rhs._inventory[i]->clone(); // Clone la Materia de la source.
        } else {
            this->_inventory[i] = nullptr;
        }
    }

    // 5. Retourner une référence à l'objet courant
    return *this;
}

// Destructeur de Character
// Doit libérer la mémoire de toutes les Materias dans l'inventaire.
Character::~Character() {
    // std::cout << "Character destructor called for: " << this->_name << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (this->_inventory[i] != nullptr) {
            delete this->_inventory[i]; // Appelle le destructeur de la Materia concernée.
            this->_inventory[i] = nullptr; // Bonne pratique, même si l'objet va être détruit.
        }
    }
}

// Getter pour le nom du personnage.
std::string const & Character::getName() const {
    return this->_name;
}

// Équipe une Materia.
// La Materia est ajoutée au premier emplacement vide de l'inventaire.
void Character::equip(AMateria* m) {
    if (m == nullptr) { // Si la Materia à équiper est nulle, on ne fait rien.
        // std::cout << this->_name << " tried to equip a null Materia." << std::endl; // Optionnel
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (this->_inventory[i] == nullptr) { // Premier slot libre trouvé.
            this->_inventory[i] = m; // Le personnage prend possession de la Materia 'm'.
            // std::cout << this->_name << " equipped " << m->getType() << " in slot " << i << std::endl; // Optionnel
            return; // Sortir dès que la Materia est équipée.
        }
    }
    // Si on arrive ici, l'inventaire est plein.
    // std::cout << this->_name << "'s inventory is full. Cannot equip " << m->getType() << std::endl; // Optionnel
    // L'énoncé dit "ne faites rien", donc pas de delete de 'm' ici.
    // L'appelant est responsable de 'm' si l'équipement échoue (inventaire plein).
}

// Déséquipe une Materia à un index donné.
// La Materia n'est PAS supprimée (delete).
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) { // Vérifie si l'index est valide.
        if (this->_inventory[idx] != nullptr) { // S'il y a une Materia dans ce slot.
            // AMateria* temp = this->_inventory[idx]; // Optionnel: pour déboguer ou retourner.
            // std::cout << this->_name << " unequipped " << this->_inventory[idx]->getType() << " from slot " << idx << std::endl; // Optionnel
            this->_inventory[idx] = nullptr; // Le slot est maintenant vide. Le personnage ne possède plus cette Materia.
            // L'énoncé dit "ne doit PAS delete la Materia".
            // La Materia est "laissée au sol". L'appelant doit la gérer s'il veut éviter une fuite.
        } else {
            // std::cout << "Slot " << idx << " is already empty for " << this->_name << "." << std::endl; // Optionnel
        }
    } else {
        // std::cout << "Invalid index " << idx << " for unequip on " << this->_name << "." << std::endl; // Optionnel
        // Si l'index est invalide, ne rien faire.
    }
}

// Utilise une Materia de l'inventaire sur une cible.
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4) { // Vérifie si l'index est valide.
        if (this->_inventory[idx] != nullptr) { // S'il y a une Materia dans ce slot.
            // Appel polymorphique : this->_inventory[idx] est un AMateria*,
            // mais la méthode use() appelée sera celle du type concret (Ice::use ou Cure::use).
            // std::cout << this->_name << " uses Materia in slot " << idx << " on " << target.getName() << ":" << std::endl; // Optionnel
            this->_inventory[idx]->use(target);
        } else {
            // std::cout << "No Materia in slot " << idx << " for " << this->_name << " to use." << std::endl; // Optionnel
            // Si le slot est vide, ne rien faire.
        }
    } else {
        // std::cout << "Invalid index " << idx << " for use on " << this->_name << "." << std::endl; // Optionnel
        // Si l'index est invalide, ne rien faire.
    }
}
