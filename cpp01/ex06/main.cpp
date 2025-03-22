/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:59:55 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/22 11:33:52 by rhanitra         ###   ########.fr       */
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
		std::cout << "Enter a good parameter: <./Harl> <level>";
		return (0);
	}
	tmp = argv[1];
	level = tmp.c_str();
	harl.complain(level);
	return (0);
}
