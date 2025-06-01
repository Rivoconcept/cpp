/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:31:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/01 14:58:04 by rhanitra         ###   ########.fr       */
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
    
    ScalarConverter::convert(literal);
        
    return (0);
}
