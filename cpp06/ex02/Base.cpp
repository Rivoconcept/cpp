/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:10:25 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/10 19:05:23 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * generate(void)
{
    std::srand(time(NULL));
    
    int r = std::rand() % 3;

    if (r == 0)
        return (new A());
    else if (r == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    if (p == dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (p == dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (p == dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (...){}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (...) {}

    std::cout << "Unknown\n";
}



