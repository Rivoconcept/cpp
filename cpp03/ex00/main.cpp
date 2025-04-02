/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:58:35 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/04/02 18:40:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap david("David");
    ClapTrap goliath("Goliath");

    david.setAttack(3);
    goliath.setAttack(2);

    std::cout << "\n--- Initial Status ---\n";
    std::cout << david << std::endl;
    std::cout << goliath << std::endl;

    std::cout << "\n--- Combat Begins! ---\n";
    while (david.getEnergy() > 0 && goliath.getEnergy() > 0)
    {
        david.attack(goliath.getName());
        goliath.takeDamage(david.getAttack());

        if (goliath.getHit() == 0)
            break;

        goliath.attack(david.getName());
        david.takeDamage(goliath.getAttack());

        if (david.getHit() == 0)
            break;
    }

    std::cout << "\n--- Round state ---\n";
    david.attack(goliath.getName());
    goliath.attack(david.getName());

    std::cout << "\n--- Final Status ---\n";
    std::cout << david << std::endl;
    std::cout << goliath << std::endl;

    return 0;
}

