/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:36:29 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/06 15:59:08 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap"
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
    private:
    
    public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &scavTrap);
		~ScavTrap();
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &ScavTrap);

#endif