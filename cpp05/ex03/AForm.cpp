/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:32:27 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/22 18:05:13 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("DefaultForm"), _formSigned(false), _gradeToSign(75), _gradeToExecute(75) {}

AForm::AForm(const std::string name, int gts, int gte) : _name(name), _formSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
    if (gts < 1 || gte < 1)
        throw GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _formSigned(other._formSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

const std::string& AForm::getName() const
{
    return (this->_name);
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_formSigned = other._formSigned;
    }
    return (*this);
}

AForm::~AForm() {}

bool AForm::isFormSigned() const
{
    return (this->_formSigned);
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form has not been signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_formSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form's name is: \"" << form.getName() 
    << "\"\nIt's signed: \"" << (form.isFormSigned() ? "Yes" : "No")
    << "\"\nGrade required to sign: \"" << form.getGradeToSign() 
    << "\"\nGrade required to execute: \"" << form.getGradeToExecute() << "\"" << std::endl; 
    return (out);
}
