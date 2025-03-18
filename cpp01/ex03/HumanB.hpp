/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/18 16:49:25 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB
{
	private:
	
		std::string	_name;
		Weapon* _weapon;
		
	public:

		HumanB(std::string name);
		~HumanB();

        const std::string& getName(void) const;
		void setName(std::string Name);
		
		const std::string& getWeapon(void) const;
		void setWeapon(Weapon& weapon);
		
        void attack() const;

};


#endif
