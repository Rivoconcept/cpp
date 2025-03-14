#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Zombie
{
	private:
	
		std::string	_name;
		
	public:

		Zombie();
		~Zombie();

		std::string 	getName(void) const;
		void 			setName(std::string name);
		void			announce(void);
		
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
