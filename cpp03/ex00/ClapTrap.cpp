/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:04:25 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/31 18:19:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
    out << clapTrap;
    return (out);
}