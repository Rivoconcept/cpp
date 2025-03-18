/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/18 17:01:00 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanA
{
	private:
	
		std::string	_name;
		Weapon& _weapon;
		
	public:

		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		const std::string& 	getName() const;
		void 				setName(std::string name);
	
		const std::string& 	getWeapon() const;

		void				attack(void) const;

};



#endif
