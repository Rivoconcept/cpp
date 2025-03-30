/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:19:07 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 10:30:20 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a(42, "Answer");
    Fixed b(3.14f, "Pi");
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    
    Fixed c(a);  // Test du constructeur de copie
    std::cout << "c is " << c << std::endl;
    
    Fixed d;
    d = b;       // Test de l'opérateur d'affectation
    std::cout << "d is " << d << std::endl;
    
    b.setName("Better Pi");
    std::cout << "b is now " << b << std::endl;
    std::cout << "d is still " << d << std::endl;  // Vérifier que d n'a pas changé
    
    // Test d'auto-affectation
    std::cout << "\nTest d'auto-affectation :" << std::endl;
    a = a;
    std::cout << "a après auto-affectation: " << a << std::endl;
    
    return 0;
}
