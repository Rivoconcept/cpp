/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:58:35 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/04/10 17:47:53 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap david("David");
    ScavTrap goliath("Goliath");
    FragTrap joseph("Joseph");

    std::cout << std::endl;

    david.attack("Goliath");
    goliath.attack("David");
    joseph.attack("david");

    std::cout << std::endl;

    david.beRepaired(5);
    goliath.beRepaired(5);
    joseph.beRepaired(2);

    std::cout << std::endl;

    david.guardGate();
    goliath.guardGate();
    joseph.highFivesGuys();

    return (0);
}


