/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlePhoneBook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:10:32 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/05 17:24:45 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}

void PhoneBook::addContact()
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

std::string truncate_data(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void displayAllContacts(const Contact contacts[], int totalContacts)
{
    int i = 0;

    while (i < totalContacts)
    {
        std::cout << "|";
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate_data(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate_data(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate_data(contacts[i].getNickName()) 
                  << "|" << std::endl;
        i++;
    }
}


void PhoneBook::displayContacts() const
{
    if (totalContacts == 0)
    {
        std::cout << "Le répertoire est vide." << std::endl;
        return;
    }
    std::cout << std::string(45, '-') << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    displayAllContacts(contacts, totalContacts);
    std::cout << "Entrez l'index du contact à afficher : ";
    std::string input;
    std::getline(std::cin, input);
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Entrée invalide." << std::endl;
        return;
    }

    int index = std::stoi(input) - 1;
    if (index < 0 || index >= totalContacts)
    {
        std::cout << "Index hors limites." << std::endl;
        return;
    }

    contacts[index].displayContact();
}



