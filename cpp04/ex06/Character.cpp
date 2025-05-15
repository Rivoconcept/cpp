/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:51:36 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 14:41:03 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"  // Inclusion du header de la classe Character
#include "AMateria.hpp"   // Inclusion pour manipuler les objets AMateria dans l'inventaire
#include <iostream>       // Pour std::cout (utilisé pour les messages de débogage/actions)

// --- Constructeurs et Destructeur ---

// Constructeur prenant le nom du personnage.
// Initialise le nom et met tous les emplacements de l'inventaire à NULL (vide).
Character::Character(std::string const & name) : _name(name) {
    // std::cout << "Character Constructor (name: " << this->_name << ") called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        this->_inventory[i] = NULL; // Initialise chaque slot de l'inventaire comme vide.
    }
}

// Constructeur par recopie (assure une copie profonde de l'inventaire).
Character::Character(Character const & src) : _name(src._name) { // Copie du nom
    // std::cout << "Character Copy Constructor (name: " << this->_name << ") called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (src._inventory[i] != NULL) {
            // Si la source a une Materia dans ce slot, on la clone.
            // this->_inventory[i] reçoit un pointeur vers une NOUVELLE Materia,
            // qui est une copie (clone) de celle de la source.
            this->_inventory[i] = src._inventory[i]->clone();
        } else {
            this->_inventory[i] = NULL; // Sinon, le slot de destination reste vide.
        }
    }
}

// Opérateur d'affectation (assure une copie profonde et gère l'auto-affectation).
Character& Character::operator=(Character const & rhs) {
    // std::cout << "Character Assignment Operator for " << this->_name << " from " << rhs._name << " called" << std::endl; // Optionnel
    // 1. Vérification de l'auto-affectation (ex: char1 = char1)
    if (this == &rhs) {
        return *this; // Ne rien faire si c'est le même objet.
    }

    // 2. Libérer les ressources existantes de l'objet courant (this).
    // Supprime toutes les Materias actuellement dans l'inventaire de 'this' pour éviter les fuites.
    for (int i = 0; i < 4; ++i) {
        if (this->_inventory[i] != NULL) {
            delete this->_inventory[i];   // Supprime l'ancienne Materia.
            this->_inventory[i] = NULL; // Réinitialise le pointeur.
        }
    }

    // 3. Copier les données simples (le nom) de l'objet source (rhs).
    this->_name = rhs._name;

    // 4. Copier (cloner) les ressources de l'objet source (rhs).
    // Alloue de nouvelles Materias pour 'this' en clonant celles de 'rhs'.
    for (int i = 0; i < 4; ++i) {
        if (rhs._inventory[i] != NULL) {
            this->_inventory[i] = rhs._inventory[i]->clone();
        } else {
            this->_inventory[i] = NULL;
        }
    }

    // 5. Retourner une référence à l'objet courant.
    return *this;
}

// Destructeur de Character.
// Doit libérer la mémoire de toutes les Materias stockées dans l'inventaire.
Character::~Character() {
    // std::cout << "Character Destructor (name: " << this->_name << ") called" << std::endl; // Optionnel
    for (int i = 0; i < 4; ++i) {
        if (this->_inventory[i] != NULL) {
            delete this->_inventory[i]; // Appelle le destructeur de la Materia concernée.
            // this->_inventory[i] = NULL; // Pas strictement nécessaire ici car l'objet est détruit.
        }
    }
}

// --- Implémentation des Méthodes de ICharacter ---

// Retourne une référence constante vers le nom du personnage.
std::string const & Character::getName() const {
    return this->_name;
}

// Équipe une Materia (pointée par m) au personnage.
// La Materia est ajoutée au premier emplacement vide de l'inventaire (de 0 à 3).
// Si l'inventaire est plein ou si m est NULL, ne fait rien.
void Character::equip(AMateria* m) {
    if (m == NULL) { // On ne peut pas équiper une Materia nulle.
        // std::cout << this->_name << " cannot equip a null Materia." << std::endl; // Optionnel
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (this->_inventory[i] == NULL) { // Premier slot libre trouvé.
            this->_inventory[i] = m; // Le personnage prend "possession" du pointeur m.
            // std::cout << this->_name << " equipped " << m->getType() << " in slot " << i << "." << std::endl; // Optionnel
            return; // Sortir dès que la Materia est équipée.
        }
    }
    // Si la boucle se termine, l'inventaire est plein.
    // std::cout << this->_name << "'s inventory is full. Cannot equip " << m->getType() << "." << std::endl; // Optionnel
    // L'énoncé dit "ne faites rien". Si m n'est pas équipé, l'appelant est toujours responsable de m.
}

// Déséquipe une Materia à un index (idx) donné.
// Le pointeur dans l'inventaire est mis à NULL.
// La Materia déséquipée n'est PAS supprimée (delete) par cette méthode.
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) { // Vérifie si l'index est valide (0 à 3).
        if (this->_inventory[idx] != NULL) { // S'il y a une Materia dans ce slot.
            // AMateria* droppedMateria = this->_inventory[idx]; // Pourrait être retourné ou géré.
            // std::cout << this->_name << " unequipped " << this->_inventory[idx]->getType() << " from slot " << idx << "." << std::endl; // Optionnel
            this->_inventory[idx] = NULL; // Le slot est maintenant vide.
            // Le personnage ne possède plus cette Materia.
            // L'appelant est responsable de gérer la 'droppedMateria' pour éviter une fuite,
            // si le pointeur a été récupéré avant de mettre à NULL.
        }
        // else { std::cout << "Slot " << idx << " is already empty for " << this->_name << "." << std::endl; } // Optionnel
    }
    // else { std::cout << "Invalid index " << idx << " for unequip on " << this->_name << "." << std::endl; } // Optionnel
    // Si l'index est invalide ou le slot déjà vide, ne rien faire.
}

// Utilise la Materia de l'inventaire à l'index [idx] sur le personnage 'target'.
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4) { // Vérifie si l'index est valide.
        if (this->_inventory[idx] != NULL) { // S'il y a une Materia utilisable dans ce slot.
            // Appel polymorphique : this->_inventory[idx] est un AMateria*,
            // mais la méthode use() appelée sera celle du type concret (Ice::use, Cure::use, etc.).
            // std::cout << this->_name << " uses Materia in slot " << idx << " on " << target.getName() << ":" << std::endl; // Optionnel
            this->_inventory[idx]->use(target);
        }
        // else { std::cout << "No Materia in slot " << idx << " for " << this->_name << " to use." << std::endl; } // Optionnel
    }
    // else { std::cout << "Invalid index " << idx << " for use on " << this->_name << "." << std::endl; } // Optionnel
    // Si l'index est invalide ou le slot vide, ne rien faire.
}