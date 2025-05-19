/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:33:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/19 18:31:06 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

class DrawTree
{
    public:
        DrawTree();
        ~DrawTree();

        void draw() const;
};

DrawTree::DrawTree() {}

DrawTree::~DrawTree() {}

void DrawTree::draw() const
{
    std::cout << "    *           *    \n";
    std::cout << "   ***         ***   \n";
    std::cout << "  *****       *****  \n";
    std::cout << " *******     ******* \n";
    std::cout << "*********   *********\n";
    std::cout << "   |||         |||   \n";
    std::cout << "   |||         |||   \n";
    std::cout << "   |||         |||   " << std::endl;
}

int main()
{
    try
    {
       DrawTree tree;
       tree.draw();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
