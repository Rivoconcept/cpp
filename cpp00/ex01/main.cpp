/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:13:21 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/07 15:38:37 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/PhoneBook.hpp"
#include "./include/Contact.hpp"

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return ""; 
    size_t last = str.find_last_not_of(" \t\n\r");
    return (str.substr(first, last - first + 1));
}

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
    std::string temp;
    int index;

    while (1)
    {
        handleCommand(&command);
        temp = trim(command);
        if (temp == "ADD")
            phoneBook.addContact();
        else if (temp == "SEARCH")
            phoneBook.displayContacts();
        else if (temp == "EXIT")
            break;
        else
            std::cout << "Unkwon Command !" << std::endl;
    }
    return (0);
}
