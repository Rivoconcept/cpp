/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:28:44 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/11 16:31:58 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook
{
	private:
		Contact _contacts[MAX_CONTACT];
		int _index;
		int _totalContacts;
		static std::string _truncate_data(const std::string &str);
		static void	_handleMessage(std::string message);
		static void	_putErrorMessage(std::string message);
		static void	_displayQuestions(Contact::t_params *params);
		static void	_displayAllContacts(const Contact _contacts[], int _totalContacts);

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


#endif