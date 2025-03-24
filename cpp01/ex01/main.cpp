/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:05:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/24 17:25:49 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int size = 10;

    Zombie* horde = zombieHorde(size, "player");

    if (horde)
    {
        for (int i = 0; i < size; i++)
            horde[i].announce();
        delete[] horde;
    }

    return (0);
}
