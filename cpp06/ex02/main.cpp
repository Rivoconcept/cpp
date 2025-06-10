/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:31:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/10 19:03:44 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    Base* ptrBase = generate();

    std::cout << "Identification by Pointer: ";
    identify(ptrBase);

    std::cout << "Identification by Reference: ";
    identify(*ptrBase);

    delete ptrBase;
    return (0);
}

