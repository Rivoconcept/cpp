/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:40:31 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/12 07:27:30 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int deposit) : _accountIndex(0),	_amount(0), _nbDeposits(0), _nbWithdrawals(0) {}

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