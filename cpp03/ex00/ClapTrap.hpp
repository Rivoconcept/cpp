/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:44 by rhanitra         ###   ########.fr       */
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
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

  public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap &clapTrap);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &value);

    const std::string& getName( void ) const;
    const unsigned int& getHitPoints( void ) const;
    const unsigned int& getEnergyPoints( void ) const;
    const unsigned int& getAttackPoints( void ) const;
    
    void setName(std::string name);
    void setHitPoints(unsigned int hitPoints);
    void setEnergyPoints( unsigned int energyPoints );
    void setAttackPoints( unsigned int attackPoints );

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &ClapTrap);

#endif