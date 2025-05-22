/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:37:34 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/22 18:00:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _formSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:        
        Form();
        Form(const std::string name, int gts, int gte);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool isFormSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif