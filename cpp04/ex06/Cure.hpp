/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:53:20 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/09 15:10:21 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp" // Cure hérite de AMateria

// class ICharacter; // Forward declaration si AMateria.hpp ne le fait pas déjà
                   // et si ICharacter est utilisé seulement par pointeur/référence ici.
                   // Normalement, AMateria.hpp s'en charge pour la signature de use().

class Cure : public AMateria
{
public:
    Cure();                               // Constructeur par défaut
    Cure(const Cure& src);                // Constructeur par copie
    Cure& operator=(const Cure& rhs);     // Opérateur d'affectation
    virtual ~Cure();                      // Destructeur (virtuel par héritage)

    // Redéfinition (override) des méthodes virtuelles de AMateria
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target); // ICharacter doit être connu ici,
                                          // soit par inclusion de ICharacter.hpp
                                          // soit par forward declaration si AMateria.hpp ne le fait pas
                                          // pour la signature de AMateria::use.
                                          // Dans notre cas, AMateria.hpp a une forward declaration.
};

#endif // CURE_HPP
