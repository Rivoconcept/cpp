/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:46:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/02/11 19:27:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BrickWall.hpp"

BrickWall::BrickWall(void)
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

BrickWall::~BrickWall()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int main(void)
{
    BrickWall Test;
    return (0);
}