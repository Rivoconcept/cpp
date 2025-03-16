/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:26:45 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/16 10:45:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cstring"


#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "The memory address of str	: " << &str << std::endl;
	std::cout << "The memory address of stringPTR	: " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF	: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "The value of str		: " << str << std::endl;
	std::cout << "The value of stringPTR		: " << *stringPTR << std::endl;
	std::cout << "The value of stringREF		: " << stringREF << std::endl;

	return 0;
}

