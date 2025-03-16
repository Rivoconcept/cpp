/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/16 12:58:48 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class HumanB
{
	private:
	
		std::string	_name;
		int			_weapon;
		
	public:

		HumanB();
		~HumanB();

		std::string 	getName(void) const;
		void 			setName(std::string name);

		int				getWeapon(void) const;
		void 			setWeapon(int weapon);

		void			attack(void);

};


#endif
