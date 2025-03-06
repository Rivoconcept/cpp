#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACT];
        int index;
        int totalContacts;

    public:
        PhoneBook();
        
        int getIndex() const;
        void setIndex(int i);

        int getTotalContacts() const;
        void setTotalContacts(int total);

        void addContact();
        void displayContacts() const;

};

void handleMessage(std::string message);
void putErrorMessage(std::string message);
void displayQuestions(t_params *params);
void displayAllContacts(const Contact contacts[], int totalContacts);

#endif