/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:11:45 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/06 20:07:26 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

typedef struct s_params
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
}   t_params;

class Contact
{
    private:
        std::string    firstName;
        std::string    lastName;
        std::string    nickName;
        std::string    phoneNumber;
        std::string    darkestSecret;
        
    public:
        Contact();
        
        std::string getFirstName() const;
        void setFirstName(std::string first_name);

        std::string getLastName() const;
        void setLastName(std::string first_name);

        std::string getNickName() const;
        void setNickName(std::string nick_name);

        std::string getPhoneNumber() const;
        void setPhoneNumber(std::string phone_number);
        
        std::string getDarkestSecret() const;
        void setDarkestSecret(std::string darkest_secret);

        void setContact(t_params& params);
        void displayContact(void) const;
};

#endif