/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:47:29 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/13 19:20:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class GradeTooHighException : public std::exception
{
    public:
        const char* what() const noexcept override;
};

class GradeTooLowException : public std::exception
{
    public:
        const char* what() const noexcept override;
};

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void GradeTooHighException();
        void GradeTooLowException();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif