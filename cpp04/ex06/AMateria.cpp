/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:49:05 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 14:41:12 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"   // Inclusion du header de la classe AMateria
#include "ICharacter.hpp" // Inclusion pour l'utilisation de ICharacter dans la méthode use()
#include <iostream>       // Pour std::cout (utilisé dans la méthode use() par défaut)

// --- Constructeurs et Destructeur ---

// Constructeur paramétrique: initialise le type de la Materia.
// Le membre _type est initialisé grâce à la liste d'initialisation du constructeur.
AMateria::AMateria(std::string const & type) : _type(type) {
    // std::cout << "AMateria Constructor (type: " << this->_type << ") called" << std::endl; // Optionnel: log de débogage
}

// Constructeur par copie.
// Copie le type de la Materia source.
// L'énoncé initial suggérait que copier le type n'a pas grand intérêt pour une affectation,
// mais pour un constructeur par copie, il est logique de copier l'état.
AMateria::AMateria(const AMateria& src) : _type(src._type) {
    // std::cout << "AMateria Copy Constructor (type: " << this->_type << ") called" << std::endl; // Optionnel
    // Si d'autres membres devaient être copiés, ce serait ici.
    // Ou, alternativement, si l'opérateur= est bien fait : *this = src; (mais attention aux initialisations)
}

// Opérateur d'affectation.
// Gère l'affectation d'une Materia à une autre.
AMateria& AMateria::operator=(const AMateria& rhs) {
    // std::cout << "AMateria Assignment Operator called" << std::endl; // Optionnel
    if (this != &rhs) { // Protection contre l'auto-affectation (ex: materia1 = materia1)
        // L'énoncé original disait : "copier son type n’a pas grand intérêt."
        // On pourrait donc choisir de ne pas copier le type, ou de le faire pour la cohérence.
        // this->_type = rhs._type; // Si on décide de copier le type.
        // Pour cet exercice, on peut considérer que les Materias sont principalement définies
        // par leur type à la construction et clonées, donc l'affectation directe
        // entre AMateria est moins critique que le clonage.
    }
    return *this; // Retourne une référence à l'objet courant.
}

// Destructeur virtuel.
// Le corps est vide car AMateria ne gère pas directement de ressources allouées dynamiquement
// qui lui sont propres (son type est un std::string géré automatiquement).
// Sa virtualité est cruciale pour les classes dérivées.
AMateria::~AMateria() {
    // std::cout << "AMateria Destructor (type: " << this->_type << ") called" << std::endl; // Optionnel
}

// --- Méthodes Publiques ---

// Retourne une référence constante vers le type de la Materia.
std::string const & AMateria::getType() const {
    return this->_type;
}

// Méthode use() de base pour AMateria.
// Fournit un comportement par défaut si une classe dérivée ne la redéfinit pas
// ou si elle est appelée directement sur un objet AMateria (ce qui ne devrait pas arriver
// si AMateria est utilisée comme une classe purement abstraite pour cette fonction).
// Les classes concrètes (Ice, Cure) fourniront l'implémentation spécifique.
void AMateria::use(ICharacter& target) {
    // Comportement par défaut. target.getName() nécessite que ICharacter soit défini.
    std::cout << "* AMateria " << this->_type << " used on " << target.getName()
              << ", but it has no specific effect by default *" << std::endl;
    // Si aucun comportement par défaut n'est souhaité, on peut utiliser (void)target;
    // pour indiquer que le paramètre est intentionnellement non utilisé et éviter un avertissement.
    // (void)target;
}

// Note : AMateria::clone() est une fonction virtuelle pure (virtual ... = 0; dans le .hpp),
// donc elle n'a PAS de définition dans AMateria.cpp.
// Chaque classe dérivée concrète (Ice, Cure) DOIT fournir sa propre implémentation de clone().