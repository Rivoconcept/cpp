/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:15:56 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/05 15:16:44 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {}

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
    std::cout << "Nom : " << this->lastName << std::endl;
    std::cout << "Prénom : " << this->firstName << std::endl;
    std::cout << "Surnom : " << this->nickName << std::endl;
    std::cout << "Numéro : " << this->phoneNumber << std::endl;
    std::cout << "Secret : " << this->darkestSecret << std::endl;
}

