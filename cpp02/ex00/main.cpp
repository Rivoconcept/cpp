/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:55 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:41:33 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	std::string tmp;
	std::string level;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		std::cout << "Enter a good parameter: <./Harl> <level>" << std::endl;
		return (0);
	}
	tmp = argv[1];
	level = tmp.c_str();
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "Bad input!" << std::endl;
	}
	harl.complain(level);
	return (0);
}
