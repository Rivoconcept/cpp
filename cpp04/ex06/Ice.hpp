/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:52:10 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:42:52 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP // Garde d'inclusion
#define ICE_HPP

#include "AMateria.hpp" // Ice hérite de AMateria, donc sa définition est nécessaire.

// La classe Ice est une Materia concrète de type "glace".
class Ice : public AMateria // Héritage public de AMateria
{
public:
    // --- Constructeurs et Destructeur ---

    // Constructeur par défaut.
    // Déclaration seulement. La définition sera dans Ice.cpp.
    Ice();

    // Constructeur par copie.
    // Déclaration seulement.
    Ice(const Ice& src);

    // Opérateur d'affectation.
    // Déclaration seulement.
    Ice& operator=(const Ice& rhs);

    // Destructeur.
    // Automatiquement virtuel car ~AMateria() est virtuel.
    // Déclaration seulement.
    virtual ~Ice();

    // --- Méthodes Publiques (Redéfinitions) ---

    // Implémentation concrète de la méthode clone pour Ice.
    // Retourne une nouvelle instance de Ice.
    // Déclaration seulement.
    virtual AMateria* clone() const;

    // Implémentation concrète de la méthode use pour Ice.
    // Applique l'effet "glace" sur la cible.
    // ICharacter doit être connu ici (via AMateria.hpp qui a une forward declaration
    // ou inclurait ICharacter.hpp si AMateria::use était définie ici).
    // Déclaration seulement.
    virtual void use(ICharacter& target);
};

#endif // ICE_HPP