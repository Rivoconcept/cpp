/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:32:27 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/24 16:22:00 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("DefaultForm"), _formSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string name, int gts, int gte) 
    : _name(name), _formSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
    if (gts < 1 || gte < 1)
        throw GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _formSigned(other._formSigned), \
        _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

const std::string& Form::getName() const
{
    return (this->_name);
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_formSigned = other._formSigned;
    }
    return (*this);
}

Form::~Form() {}

bool Form::isFormSigned() const
{
    return (this->_formSigned);
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_formSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form's name is: \"" << form.getName() 
    << "\"\nIt's signed: \"" << (form.isFormSigned() ? "Yes" : "No")
    << "\"\nGrade required to sign: \"" << form.getGradeToSign() 
    << "\"\nGrade required to execute: \"" << form.getGradeToExecute() << "\"" << std::endl; 
    return (out);
}
