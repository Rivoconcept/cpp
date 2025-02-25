/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:46:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/25 19:22:06 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    
    if (argc == 1 || (argc == 2 && !argv[0]))
    {
        std::cout  << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    
    return (0);
}