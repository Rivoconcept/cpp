/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:58:53 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/24 18:11:47 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
    private:
        std::string tab[100];

    public:
        Brain();
        ~Brain();

        const std::string* getTab() const;
        void setTab(int index, const std::string& value);
        

};


#endif