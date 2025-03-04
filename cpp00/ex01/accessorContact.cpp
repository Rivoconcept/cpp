/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:29:26 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 17:12:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


std::string Contact::getfirstName() const
{
    return (this->firstName);
}

void Contact::setfirstName(std::string first_name)
{  
    this->firstName = first_name;
}

std::string Contact::getlastName() const
{
    return (this->lastName);
}

void Contact::setlastName(std::string last_name)
{  
    this->lastName = last_name;
}

std::string Contact::getnickName() const
{
    return (this->nickName);
}

void Contact::setnickName(std::string nick_name)
{  
    this->nickName = nick_name;
}

std::string Contact::getphoneNumber() const
{
    return (this->phoneNumber);
}

void Contact::setphoneNumber(std::string phone_number)
{  
    this->phoneNumber = phone_number;
}

std::string Contact::getdarkestSecret() const
{
    return (this->darkestSecret);
}

void Contact::setdarkestSecret(std::string darkest_secret)
{  
    this->darkestSecret = darkest_secret;
}