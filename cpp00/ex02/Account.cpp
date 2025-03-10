/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:40:31 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/10 18:47:54 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int deposit) {}

Account::~Account() {}

int  Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int	 Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{

}