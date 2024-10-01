/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeguerin <jeguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:19:22 by jeguerin          #+#    #+#             */
/*   Updated: 2024/10/01 11:19:30 by jeguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"

// Need to initialize our static attributs BUT : ces variables doivent être définies dans le fichier
// source pour qu'elles soient accessibles à toutes les fonctions de la classe. => Put "Account::"
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

// [19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
void	Account::displayAccountsInfos( void ) // Display total accounts infos
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"
		<< getTotalAmount() << ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) //Need to initialize all private attributes.
{
	_displayTimestamp();
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*
Cette fonction doit ajouter le montant spécifié (deposit) au solde actuel du compte.
Il faudra aussi probablement imprimer un message confirmant le dépôt et mettre à jour un éventuel compteur de dépôts.
*/
void	Account::makeDeposit( int deposit )
{
	if (deposit > 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
		std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	}
	else
		std::cout << "You can't make a deposit without money !" << std::endl;
}
// Cette fonction retire un montant spécifié (withdrawal) du solde si le solde est suffisant.
// Si le solde est insuffisant, tu devras gérer ce cas en renvoyant false et afficher un 
// message d'erreur, sinon tu retires l'argent et renvoies true.
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount > withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const // Display personnal account info
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex  << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0); // To obtain actual time since 1970 in scs.
	char		time[16];
	std::tm     *timeinfo = std::localtime(&now); // To convert(yyyy, mm, d) we use localtime() that transforms time_t in a "tm" struct. containing separate infos(hour, day).
	strftime(time, 16, "%Y%m%d_%H%M%S", timeinfo); // To convert struct tm in a string.
	std::cout << "[" << time << "] ";
}
