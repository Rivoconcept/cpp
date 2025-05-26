/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:37:34 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/26 17:53:32 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _formSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:        
        AForm();
        AForm(const std::string name, int gts, int gte);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool isFormSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
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

        class GeneralException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif