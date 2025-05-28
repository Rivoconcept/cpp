/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:55:26 by rivoinfo          #+#    #+#             */
/*   Updated: 2025/05/28 14:12:52 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
#define DUMMY_HPP
#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        Dummy(const Dummy& other);
        Dummy& operator=(const Dummy& other);
        ~Dummy();

        ATarget* clone() const;


};

#endif