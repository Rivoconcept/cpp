/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:11:45 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/07 17:31:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>

class Rectangle
{
    private:
        double width;
        double height;
        
    public:
        Rectangle(void);
        ~Rectangle(void);
        double surface() const;
        double getwidth() const;
        double getheight() const;
        void setwidth(double w);
        void setheight(double h);
};

#endif