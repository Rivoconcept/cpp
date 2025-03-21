/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:11:45 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/21 11:18:21 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>

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