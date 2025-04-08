/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/08 17:52:18 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <cmath>
# include <cstdlib>
# include <iostream>
# include <string>

class ClapTrap
{
  private:
    std::string _name;
    unsigned int _hit;
    unsigned int _energy;
    unsigned int _attack;

  public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &clapTrap);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &value);
    
    const std::string& getName( void ) const;
    const unsigned int& getHit( void ) const;
    const unsigned int& getEnergy( void ) const;
    const unsigned int& getAttack( void ) const;
    
    void setName(const std::string &name);
    void setHit(unsigned int hit);
    void setEnergy(unsigned int energy);
    void setAttack(unsigned int attack);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &ClapTrap);

#endif