/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:55 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/26 16:00:27 by rivoinfo         ###   ########.fr       */
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
