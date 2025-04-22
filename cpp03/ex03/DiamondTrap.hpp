/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:56:46 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/20 13:16:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name, const FragTrap& fragTrap, const ScavTrap& scavTrap); 
        DiamondTrap(const DiamondTrap& DiamondTrap);
        ~DiamondTrap();

        DiamondTrap& operator=(const DiamondTrap& DiamondTrap);
        

        void whoAmI();

        using ScavTrap::attack;

};

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap);

#endif