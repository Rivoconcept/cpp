/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:11:45 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/26 09:38:20 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
#include <ieee754.h>
#include <cstdio>


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