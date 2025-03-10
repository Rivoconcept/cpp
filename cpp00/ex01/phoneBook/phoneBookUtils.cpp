/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:12:02 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/10 18:26:19 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

void PhoneBook::_handleMessage(std::string message)
{
	std::cout << std::endl;
	std::cout << std::string(message.length() + 4, '*') << std::endl;
	std::cout << "* " << message << " *" << std::endl;
	std::cout << std::string(message.length() + 4, '*') << std::endl;
	std::cout << std::endl;
}

void PhoneBook::_putErrorMessage(std::string message)
{
	std::cout << std::endl;
	std::cout << "*** " << message << " ***" << std::endl;
	std::cout << std::endl;
}

std::string PhoneBook::_truncate_data(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::_displayQuestions(t_params *params)
{
	std::cout << "First Name: ";
	std::getline(std::cin, params->firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, params->lastName);
	std::cout << "Nick Name: ";
	std::getline(std::cin, params->nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, params->phoneNumber);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, params->darkestSecret);
}

void PhoneBook::_displayAllContacts(const Contact _contacts[], int _totalContacts)
{
	int	i = 0;

	while (i < _totalContacts)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << _truncate_data(_contacts[i].getFirstName()) << "|"
					<< std::setw(10) << _truncate_data(_contacts[i].getLastName()) << "|"
					<< std::setw(10) << _truncate_data(_contacts[i].getNickName()) 
					<< "|" << std::endl;
		std::cout << std::string(45, '-') << std::endl;
		i++;
	}
}
