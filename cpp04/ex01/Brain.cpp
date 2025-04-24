/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:09:59 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/24 18:13:19 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {}

Brain::~Brain() {}

const std::string* Brain::getTab() const
{
    return (this->tab);
}

void Brain::setTab(int index, const std::string& value)
{
    if (index >= 0 && index < 100)
        tab[index] = value;
}
