/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/31 18:21:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H


# include <cmath>
# include <cstdint>
# include <cstdlib>
# include <iostream>
# include <string>

class ClapTrap
{
  private:
    std::string _name;
    int         _hitPoints;
    int         _EnergyPoints;
    int         _attackDamage;

  public:
	ClapTrap();
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap(const int value);
	ClapTrap(const std::string name);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &value);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

std::ostream &operator<<(std::ostream &out, const ClapTrap &ClapTrap);


#endif