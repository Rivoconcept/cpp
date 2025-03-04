/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlePhoneBook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:10:32 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/05 00:01:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}

void addContact()
{
    t_params params;

    std::cout << "First Name: ";
    std::getline(std::cin, params.firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, params.lastName);
    std::cout << "Nick Name: ";
    std::getline(std::cin, params.nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, params.phoneNumber);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, params.darkestSecret);
    if (params.firstName.empty() || params.lastName.empty() \
        || params.nickname.empty() || params.phoneNumber.empty() \
        || params.darkestSecret.empty())
    {
        std::cout << "Error:\n All fields must be completed !" << std::endl;
        return;
    }
    contacts[index].setContact(params);
    std::cout << "Contact ajouté avec succès !" << std::endl;
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}
