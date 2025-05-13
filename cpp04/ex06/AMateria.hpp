/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:48:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:15:05 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP // Garde d'inclusion pour éviter les inclusions multiples
#define AMATERIA_HPP

#include <string> // Pour l'utilisation de std::string

// Déclaration anticipée (forward declaration) de ICharacter.
// Nécessaire car AMateria::use() prend un ICharacter& en paramètre.
// Cela évite d'avoir à inclure ICharacter.hpp ici, réduisant les dépendances cycliques
// et les temps de compilation si seul un pointeur ou une référence est utilisé.
class ICharacter;

// Classe de base abstraite pour les Materias.
// Elle sert d'"interface" et définit le contrat commun pour toutes les Materias.
class AMateria
{
protected:
    // Le type de la Materia (ex: "ice", "cure").
    // Protégé pour que les classes dérivées puissent y accéder directement.
    std::string _type;

public:
    // --- Constructeurs et Destructeur ---

    // Constructeur paramétrique: initialise le type de la Materia.
    // Déclaration seulement. La définition sera dans AMateria.cpp.
    AMateria(std::string const & type);

    // Constructeur par copie.
    // Déclaration seulement.
    AMateria(const AMateria& src);

    // Opérateur d'affectation.
    // Déclaration seulement.
    AMateria& operator=(const AMateria& rhs);

    // Destructeur virtuel.
    // ESSENTIEL pour les classes de base avec des fonctions virtuelles
    // afin d'assurer l'appel correct des destructeurs des classes dérivées
    // lors de la suppression via un pointeur de base.
    // Déclaration seulement. La définition (même vide) sera dans AMateria.cpp.
    virtual ~AMateria();

    // --- Méthodes Publiques ---

    // Retourne le type de la Materia.
    // 'const' car cette méthode ne modifie pas l'état de l'objet.
    // Déclaration seulement.
    std::string const & getType() const;

    // Méthode virtuelle pure: clone.
    // Doit être implémentée par toutes les classes dérivées concrètes.
    // Elle retourne un pointeur vers une nouvelle instance du même type que l'objet cloné.
    // 'const' car cloner ne modifie pas l'original.
    // Le "= 0" la rend purement virtuelle et fait de AMateria une classe abstraite.
    virtual AMateria* clone() const = 0;

    // Méthode virtuelle: use.
    // Permet à une Materia d'agir sur un personnage (ICharacter).
    // Les classes dérivées fourniront l'implémentation spécifique.
    // Déclaration seulement.
    virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP