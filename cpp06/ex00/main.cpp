/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:31:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/07 15:35:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || (argc == 2 && !argv[1][0]))
    {
        std::cout << "Bad parameter! Use: ./convert <literal>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string literal;

    literal = static_cast<std::string>(argv[1]);
    
    try
    {
        ScalarConverter::convert(literal);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
