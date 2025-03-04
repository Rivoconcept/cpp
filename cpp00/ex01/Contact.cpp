/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:29:26 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 16:14:46 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"



std::string Contact::getfirstName() const
{
    return (firstName);
}

void Contact::setfirstName(std::string first_name)
{  
    firstName = first_name;
}

std::string Contact::getlastName() const
{
    return (lastName);
}

std::string Contact::getheight() const
{
    return (height);
} 



void Contact::setheight(double height)
{
    this->height = height;
}