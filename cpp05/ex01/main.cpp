/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:33:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/01 15:56:16 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat willy("Willy", 50);
        std::cout << willy << std::endl;
        Form formA("FormA", 45, 30);
        std::cout << formA << std::endl;
        
        willy.signForm(formA);
        std::cout << std::endl;
        std::cout << formA << std::endl;

        Bureaucrat alice("Alice", 40);
        std::cout << alice << std::endl;
        
        alice.signForm(formA);
        std::cout << std::endl;
        std::cout << formA << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
