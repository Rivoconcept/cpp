/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:33:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/24 16:21:03 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat willy("Willy", 50);
        Form formA("FormA", 45, 30);

        std::cout << formA << std::endl;
        willy.signForm(formA);
        std::cout << formA << std::endl;

        Bureaucrat alice("Alice", 40);
        alice.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
