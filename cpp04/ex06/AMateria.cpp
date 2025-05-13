/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:49:05 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:19:40 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp" // Header pour AMateria
#include "ICharacter.hpp" // Nécessaire pour le paramètre de use()
#include <iostream>      // Pour std::cout, si AMateria::use avait un message par défaut

// Constructeur de AMateria
// Initialise le membre protégé _type avec la valeur passée en paramètre.
AMateria::AMateria(std::string const & type) : _type(type) {
    // std::cout << "AMateria constructor called for type: " << this->_type << std::endl; // Optionnel: pour le débogage
}

// Constructeur par copie de AMateria
// Il est généralement implicitement défini, mais si on le définit explicitement :
// Note : Le sujet ne demande pas explicitement de gérer la copie d'AMateria de cette manière,
// mais c'est une bonne pratique si on le rend copiable. Typiquement, on se concentre sur clone().
AMateria::AMateria(const AMateria& src) : _type(src._type) {
    // std::cout << "AMateria copy constructor called for type: " << this->_type << std::endl; // Optionnel
    // *this = src; // Une autre façon de faire, si l'opérateur d'affectation est bien défini.
}

// Opérateur d'affectation de AMateria
// Gère l'affectation. Comme pour le constructeur par copie, le sujet se concentre sur clone().
// "Quand on assigne une Materia à une autre, copier son type n’a pas grand intérêt."
// Cela suggère que cet opérateur ne devrait peut-être rien faire de spécial ou copier le type.
AMateria& AMateria::operator=(const AMateria& rhs) {
    // std::cout << "AMateria assignment operator called" << std::endl; // Optionnel
    if (this != &rhs) {
        // Normalement, on ne copie pas le type directement selon l'énoncé.
        // Cependant, si on doit copier quelque chose, ce serait le type.
        // this->_type = rhs._type; // Le sujet dit que cela n'a pas grand intérêt.
        // Pour cet exercice, on peut le laisser vide ou juste copier le type.
        // Par cohérence, si on a un constructeur par copie qui copie le type, l'opérateur devrait aussi.
        // Mais respectons l'esprit de l'énoncé : la copie se fait via clone().
    }
    return *this;
}


// Destructeur virtuel de AMateria
// Il est essentiel pour assurer que les destructeurs des classes dérivées sont appelés.
// Même s'il est vide, sa présence en tant que virtuel est cruciale.
AMateria::~AMateria() {
    // std::cout << "AMateria destructor called for type: " << this->_type << std::endl; // Optionnel
}

// Getter pour le type de la Materia.
// Retourne une référence constante vers la chaîne _type.
// 'const' à la fin signifie que cette méthode не modifie l'état de l'objet.
std::string const & AMateria::getType() const {
    return this->_type;
}

// Méthode use() de base pour AMateria.
// Dans cet exercice, les classes dérivées (Ice, Cure) fourniront l'implémentation spécifique.
// Cette version de base pourrait être vide ou afficher un message générique si AMateria
// n'est pas purement une interface pour cette fonction.
// L'énoncé ne précise pas de comportement par défaut ici.
void AMateria::use(ICharacter& target) {
    // Comportement par défaut pour use(), si nécessaire.
    // Par exemple, un message indiquant qu'une Materia générique est utilisée,
    // ou rien du tout si seules les classes dérivées doivent agir.
    // Pour cet exercice, on peut supposer qu'il ne fait rien ou affiche un message générique
    // qui sera masqué par la redéfinition dans les classes filles.
    std::cout << "* AMateria " << this->_type << " used on " << target.getName() << " but has no specific effect *" << std::endl;
    // Ou simplement : (void)target; // Pour éviter un avertissement de variable non utilisée si le corps est vide.
}