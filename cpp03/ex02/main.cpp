/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:58:35 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/04/08 18:17:03 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap david("David");
    ScavTrap goliath("Goliath");

    std::cout << std::endl;

    david.attack("Goliath");
    goliath.attack("David");

    std::cout << std::endl;

    david.beRepaired(5);
    goliath.beRepaired(5);

    std::cout << std::endl;

    david.guardGate();
    goliath.guardGate();

    return (0);
}


