/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:11:45 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/04 18:28:30 by rhanitra         ###   ########.fr       */
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
        std::string getfirstName() const;
        void setfirstName(std::string first_name);

        std::string getlastName() const;
        void setlastName(std::string first_name);

        std::string getnickName() const;
        void setnickName(std::string nick_name);

        std::string getphoneNumber() const;
        void setphoneNumber(std::string phone_number);
        
        std::string getdarkestSecret() const;
        void setdarkestSecret(std::string darkest_secret);

        void setContact(t_params& params);
        void displayContact(void) const;
};

#endif