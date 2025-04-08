/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:36:29 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/08 17:28:21 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		
		ScavTrap &operator=(const ScavTrap &value);
		
		void attack(const std::string &target);
		void guardGate();
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &ScavTrap);

#endif