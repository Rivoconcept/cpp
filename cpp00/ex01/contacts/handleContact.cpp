/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:15:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/11 14:00:59 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContact(Contact::t_params& params)
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

