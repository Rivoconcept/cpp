/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessorPhoneBook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:03:27 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/05 15:17:03 by rivoinfo         ###   ########.fr       */
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
