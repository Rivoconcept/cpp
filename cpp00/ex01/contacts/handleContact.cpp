/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:15:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/10 16:51:31 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContact(t_params& params)
{
	this->firstName = params.firstName;
	this->lastName = params.lastName;
	this->nickName = params.nickname;
	this->phoneNumber = params.phoneNumber;
	this->darkestSecret = params.darkestSecret;
}

void Contact::displayContact() const
{
	std::cout << std::endl;
	std::cout << "First Name		: " << this->firstName << std::endl;
	std::cout << "Last Name			: " << this->lastName << std::endl;
	std::cout << "Nickname			: " << this->nickName << std::endl;
	std::cout << "Phone Number		: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret	: " << this->darkestSecret << std::endl;
	std::cout << std::endl;
}

