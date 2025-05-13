/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:17:31 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 17:42:43 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP // Garde d'inclusion
#define CURE_HPP

#include "AMateria.hpp" // Cure hérite de AMateria.

// La classe Cure est une Materia concrète de type "soin".
class Cure : public AMateria // Héritage public de AMateria
{
public:
    // --- Constructeurs et Destructeur ---

    // Constructeur par défaut.
    // Déclaration seulement. La définition sera dans Cure.cpp.
    Cure();

    // Constructeur par copie.
    // Déclaration seulement.
    Cure(const Cure& src);

    // Opérateur d'affectation.
    // Déclaration seulement.
    Cure& operator=(const Cure& rhs);

    // Destructeur.
    // Automatiquement virtuel.
    // Déclaration seulement.
    virtual ~Cure();

    // --- Méthodes Publiques (Redéfinitions) ---

    // Implémentation concrète de la méthode clone pour Cure.
    // Déclaration seulement.
    virtual AMateria* clone() const;

    // Implémentation concrète de la méthode use pour Cure.
    // Déclaration seulement.
    virtual void use(ICharacter& target);
};

#endif // CURE_HPP