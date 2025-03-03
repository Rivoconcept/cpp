#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     index;
        int     totalContact;
    
    public:
        PhoneBook();
        void addContact();
        void displayContacts() const;
        void putDetailContact(int i) const;


};

#endif