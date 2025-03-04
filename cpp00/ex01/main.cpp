/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:13:21 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 19:08:47 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::string input;
    int index;

    while (1)
    {
        std::cout << "Enter the command :" << std::endl;
        std::cout << "  - ADD (to create a contact)" << std::endl;
        std::cout << "  - SEARCH (to find a contact)" << std::endl;
        std::cout << "  - EXIT (to exit a program)" << std::endl;

        std::getline(std::cin, command);

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Entrez l'index du contact à afficher : ";
            std::getline(std::cin, input);
            index = std::atoi(input.c_str());
           // phoneBook.displayContactDetails(index);
        } 
        else if (command == "EXIT")
            break;
        else
            std::cout << "Commande inconnue !" << std::endl;
    }
    return (0);
}
