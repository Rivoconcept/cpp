/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:07:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/10 18:35:40 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default_Diamond")
{
    std::cout << "DiamondTrap: Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : _name(name)
{
    _hit = 100;
    _energy = 50;
    _attack = 20;
    std::cout << "FragTrap: Personalized constructor called for " << _name << std::endl;
}