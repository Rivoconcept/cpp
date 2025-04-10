/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:56:46 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/10 18:35:28 by rhanitra         ###   ########.fr       */
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
        
        const std::string& getName() const;
        void setName(std::string name);

        void whoAmI();
};

#endif