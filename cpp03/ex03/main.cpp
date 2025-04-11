/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:58:35 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/04/11 09:44:36 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n--- Creating DiamondTrap Bob ---" << std::endl;
    DiamondTrap bob("Bob");

    std::cout << "\n--- Bob attacks target 'Target_1' ---" << std::endl;
    bob.attack("Target_1");

    std::cout << "\n--- Bob introduces himself ---" << std::endl;
    bob.whoAmI();

    std::cout << "\n--- Copying Bob into Alice ---" << std::endl;
    DiamondTrap alice(bob);
    alice.setName("Alice");

    std::cout << "\n--- Alice attacks target 'Target_2' ---" << std::endl;
    alice.attack("Target_2");

    std::cout << "\n--- Alice introduces herself ---" << std::endl;
    alice.whoAmI();

    std::cout << "\n--- End of program: destructors called ---" << std::endl;
    return 0;
}



