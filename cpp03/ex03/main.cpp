/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:58:35 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/04/20 13:26:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ScavTrap david("David");
    FragTrap goliath("Goliath");
    DiamondTrap bob("Bob", goliath, david);

    std::cout << std::endl;
    std::cout << "Bob's Hit point = " << bob.getHit() << std::endl;
    std::cout << "Bob's Energy point = " << bob.getEnergy() << std::endl;
    std::cout << "Bob's Attack damage = " << bob.getAttack() << std::endl;

    std::cout << std::endl;

    david.attack("Goliath");
    goliath.attack("David");
    bob.attack("Goliath");

    std::cout << std::endl;

    david.beRepaired(5);
    goliath.beRepaired(5);
    bob.beRepaired(5);

    std::cout << std::endl;

    david.guardGate();
    goliath.highFivesGuys();
    bob.whoAmI();

    return (0);
}

