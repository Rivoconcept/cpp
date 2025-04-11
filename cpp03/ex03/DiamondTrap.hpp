/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:56:46 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/11 09:20:56 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        
        DiamondTrap(const DiamondTrap& DiamondTrap);
        ~DiamondTrap();

        DiamondTrap& operator=(const DiamondTrap& DiamondTrap);
        

        void whoAmI();

        void attack(const std::string &target);

};

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap);

#endif