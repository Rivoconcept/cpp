/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessorPhoneBook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:03:27 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 18:59:40 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
