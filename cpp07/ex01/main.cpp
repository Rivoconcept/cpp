/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:41:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/16 18:33:23 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    {
        std::string* ptr1 = NULL;
        std::string* ptr2 = NULL;
        try
        {
            ::swap(ptr1, ptr2);
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Erreur: " << e.what() << std::endl;
            return (1);
        }
        
        std::cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << std::endl;
        delete ptr1; delete ptr2;
    }

    return (0);
}