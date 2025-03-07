/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlePhoneBook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:10:32 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/07 18:06:52 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}

PhoneBook::~PhoneBook() {}

int isPhoneNumber(std::string str)
{
    int     i;

    if (str.empty())
        return (0);
    i = 0;
    while (str[i] != '\0' && std::isdigit(str[i]))
        i++;
    if (i == 10)
        return (1);
    return (0);
}

int isName(std::string str)
{
    int     i;

    if (str.empty())
        return (0);
    i = 0;
    while (str[i] != '\0' && (std::isalpha(str[i]) || std::isspace(str[i])))
        i++;
    if (str[i] == '\0')
        return (1);
    return (0);
}

void PhoneBook::addContact()
{
    t_params params;

    displayQuestions(&params);
    if (params.firstName.empty() || params.lastName.empty() \
        || params.nickname.empty() || params.phoneNumber.empty() \
        || params.darkestSecret.empty())
    {
        putErrorMessage("All fields must be completed!");
        return ;
    }
    if (!isPhoneNumber(params.phoneNumber))
    {
        putErrorMessage("The phone number is not valid!");
        return ;
    }
    if (!isName(params.firstName) || !isName(params.lastName))
    {
        putErrorMessage("the first or last name entry is not valid!");
        return ;
    }
    contacts[index].setContact(params);
    handleMessage("Contact added successfully!");
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void printHeadTab(void)
{
    std::cout << std::string(45, '-') << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << std::string(45, '-') << std::endl;
}

void PhoneBook::displayContacts() const
{
    int index;
    std::string input;
    
    if (totalContacts == 0)
    {
        std::cout << "Directory is empty !" << std::endl;
        return ;
    }
    printHeadTab();
    displayAllContacts(contacts, totalContacts);
    std::cout << std::endl;
    std::cout << "Enter the contact index to display : ";
    std::getline(std::cin, input);
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        putErrorMessage("Make sure this index is valid");
        return ;
    }
    index = std::stoi(input) - 1;
    if (index < 0 || index >= totalContacts)
    {
        putErrorMessage("Index out of range.");
        return ;
    }
    contacts[index].displayContact();
}

