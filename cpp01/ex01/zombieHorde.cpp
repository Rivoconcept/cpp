/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:06:01 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/22 17:32:39 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return (NULL);
    Zombie* hordeZombie = new Zombie[N];
    for (int i = 0; i < N; i++)
        hordeZombie[i].setName(name);
    return (hordeZombie);
}
