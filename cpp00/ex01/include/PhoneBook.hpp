/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:28:44 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/10 19:16:01 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		PhoneBook(void);
		~PhoneBook(void);
		
		int		getIndex(void) const;
		void	setIndex(int i);

		int		getTotalContacts(void) const;
		void	setTotalContacts(int total);

		void	addContact(void);
		void	displayContacts(void) const;

};

void	handleMessage(std::string message);
void	putErrorMessage(std::string message);
void	displayQuestions(t_params *params);
void	displayAllContacts(const Contact contacts[], int totalContacts);

#endif