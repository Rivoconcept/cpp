/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 12:54:11 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::val = 8;

// Constructeur par défaut
Fixed::Fixed() : _fixePointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
    _name = new char[9]; // Allouer pour "Unnamed" + '\0'
    std::strcpy(_name, "Unnamed");
}

// Constructeur de copie
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    // Nous n'utilisons plus *this = copy pour éviter une dépendance circulaire
    // avec l'opérateur d'affectation. Nous faisons la copie directement ici.
    _fixePointNumber = copy._fixePointNumber);
    
    // Allocation et copie du nom
    _name = new char[strlen(copy._name) + 1];
    std::strcpy(_name, copy._name);
}

// Destructeur
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    delete[] _name; // Libération de la mémoire allouée pour le nom
}

// Opérateur d'affectation
Fixed& Fixed::operator=(const Fixed& assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign)
    {
        _fixePointNumber = assign._fixePointNumber);
        
        // Gestion du nom : libérer l'ancien, allouer et copier le nouveau
        char* tempName = new char[strlen(assign._name) + 1];
        std::strcpy(tempName, assign._name);
        
        delete[] _name; // Libération de l'ancien nom
        _name = tempName; // Affectation du nouveau nom
    }
    return (*this);
}

// Constructeur à partir d'un entier
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixePointNumber = value << val;
    _name = new char[9]; // Allouer pour "Unnamed" + '\0'
    std::strcpy(_name, "Unnamed");
}

// Constructeur à partir d'un flottant
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixePointNumber = std::roundf(value * (1 << val));
    _name = new char[9]; // Allouer pour "Unnamed" + '\0'
    std::strcpy(_name, "Unnamed");
}

// Nouveau constructeur à partir d'un entier avec nom
Fixed::Fixed(const int value, const char* name)
{
    std::cout << "Int constructor with name called" << std::endl;
    _fixePointNumber = value << val;
    _name = new char[std::strlen(name) + 1];
    std::strcpy(_name, name);
}

// Nouveau constructeur à partir d'un flottant avec nom
Fixed::Fixed(const float value, const char* name)
{
    std::cout << "Float constructor with name called" << std::endl;
    _fixePointNumber = std::roundf(value * (1 << val));
    _name = new char[std::strlen(name) + 1];
    std::strcpy(_name, name);
}

// Conversion en flottant
float Fixed::toFloat() const
{
    return ((float)_fixePointNumber / (1 << val));
}

// Conversion en entier
int Fixed::toInt() const
{
    return (_fixePointNumber >> val);
}

// Accesseur pour les bits bruts
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixePointNumber);
}

// Mutateur pour les bits bruts
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixePointNumber = raw;
}

// Accesseur pour le nom
const char* Fixed::getName() const
{
    return _name;
}

// Mutateur pour le nom
void Fixed::setName(const char* newName)
{
    delete[] _name; // Libérer l'ancien nom
    _name = new char[std::strlen(newName) + 1];
    std::strcpy(_name, newName);
}

// Surcharge de l'opérateur de flux de sortie
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.getName() << ": " << fixed.toFloat();
    return (out);
}

