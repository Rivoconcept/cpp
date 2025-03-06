/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessorPhoneBook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:03:27 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/06 17:48:46 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

int PhoneBook::getIndex() const
{
    return (this->index);
} 

void PhoneBook::setIndex(int i)
{  
    if (i <= 0)
    {
        std::cout << "Make sure this index is valid" << std::endl;
        return ;
    }
    else
        this->index = i;
}

int PhoneBook::getTotalContacts() const
{
    return (this->totalContacts);
} 

void PhoneBook::setTotalContacts(int total)
{  
    this->totalContacts = total;
}
