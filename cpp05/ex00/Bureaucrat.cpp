/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:41:28 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/14 18:34:01 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
    *this = bureaucrat;  
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (this != &bureaucrat)
    {
        this->_grade = bureaucrat._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    
}

const std::string& Bureaucrat::getName() const
{
    
}


int Bureaucrat::getGrade() const
{
    
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}