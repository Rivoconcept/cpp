/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:13:21 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/06 20:26:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/PhoneBook.hpp"
#include "./include/Contact.hpp"

void handleCommand(std::string *command)
{
    std::cout << "Enter the command :" << std::endl;
    std::cout << "  - ADD (to create a contact)" << std::endl;
    std::cout << "  - SEARCH (to find a contact)" << std::endl;
    std::cout << "  - EXIT (to exit a program)" << std::endl;

    std::cout << std::endl;
    std::cout << "> ";
    std::getline(std::cin, *command);
    std::cout << std::endl;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::string input;
    int index;

    while (1)
    {
        handleCommand(&command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.displayContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unkwon Command !" << std::endl;
    }
    return (0);
}
