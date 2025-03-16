/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:06:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/15 14:07:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* hordeZombie = new Zombie[N];
    if (N <= 0)
        return (NULL);
    for (int i = 0; i < N; i++)
        hordeZombie[i].setName(name);
    return (hordeZombie);
}
