/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:36:29 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/09 07:58:47 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &fragTrap);
		~FragTrap();
		
		FragTrap &operator=(const FragTrap &value);
		
		void attack(const std::string &target);
		void guardGate();
};

std::ostream &operator<<(std::ostream &out, const FragTrap &fragTrap);

#endif