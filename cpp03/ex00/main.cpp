/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:58:35 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/04/02 13:58:41 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Warrior");
    ClapTrap clap2("Defender");

    std::cout << "\n--- Initial Status ---\n";
    std::cout << clap1 << std::endl;
    std::cout << clap2 << std::endl;

    std::cout << "\n--- Combat Begins! ---\n";

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());

    clap2.attack(clap1.getName());
    clap1.takeDamage(clap2.getAttackDamage());

    std::cout << "\n--- Repair Phase ---\n";
    clap1.beRepaired(5);
    clap2.beRepaired(5);

    std::cout << "\n--- Final Status ---\n";
    std::cout << clap1 << std::endl;
    std::cout << clap2 << std::endl;

    return 0;
}
