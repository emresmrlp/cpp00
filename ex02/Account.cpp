#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
	_totalAmount = _totalAmount - _amount;
	_totalNbDeposits = _totalNbDeposits - _nbDeposits;
	_totalNbWithdrawals = _totalNbWithdrawals - _nbWithdrawals;
	_nbAccounts--;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount;

	_displayTimestamp();
	p_amount = _amount;
	if (_amount < withdrawal)
	{
		std::cout << " index:" << _accountIndex << ";p_amount:"
		<< p_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << " index:" << _accountIndex << ";p_amount:"
			<< p_amount << ";withdrawal:" << withdrawal << ";amount:"
			<< _amount << ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
		return (true);
	}	
}

void	Account::makeDeposit(int deposit)
{
	int p_amount;

	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount
		<< ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:"
		<< _nbDeposits << std::endl;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:"
		<< _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	char	buffer[30];
	time_t	timestamp;

	timestamp = time(NULL);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localtime(&timestamp));
	std::cout << buffer;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
