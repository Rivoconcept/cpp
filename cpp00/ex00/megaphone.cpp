/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:46:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/26 17:33:34 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{ 
    int     i;
    int     j;
    char    c;

    i = 1;
    c = 0;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
    {
        std::cout  << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            c = toupper(argv[i][j]);
            std::cout << c;
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}