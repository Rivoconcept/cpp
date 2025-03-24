/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:11 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:16:51 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORDE_HPP
# define HORDE_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Zombie
{
	private:
	
		std::string	_name;
		
	public:

		Zombie();
		Zombie( std::string name );
		~Zombie();

		std::string 	getName(void) const;
		void 			setName(std::string name);
		void			announce(void);
		
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
