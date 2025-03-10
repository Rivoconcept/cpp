/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessorContact.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:29:26 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/10 16:50:23 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

void Contact::setFirstName(std::string first_name)
{  
	this->firstName = first_name;
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

void Contact::setLastName(std::string last_name)
{  
	this->lastName = last_name;
}

std::string Contact::getNickName() const
{
	return (this->nickName);
}

void Contact::setNickName(std::string nick_name)
{  
	this->nickName = nick_name;
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

void Contact::setPhoneNumber(std::string phone_number)
{  
	this->phoneNumber = phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

void Contact::setDarkestSecret(std::string darkest_secret)
{  
	this->darkestSecret = darkest_secret;
}
