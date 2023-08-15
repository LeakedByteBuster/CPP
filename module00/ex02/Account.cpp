#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    std::cout << "[19920104_091532] accounts:"<< getNbAccounts() << ";total:"<< \
        getTotalAmount() << ";deposits:"<< getNbDeposits() << \
        ";withdrawals:" << getNbWithdrawals() << "\n";
    return ;
}

void	Account::_displayTimestamp( void )
{
    return ;
}

void	Account::makeDeposit( int deposit )
{
    Account::_amount += deposit;
    Account::_nbDeposits += 1;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << "[19920104_091532] index:" << _accountIndex << ";p_amount:" << \
        _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" \
        << _nbDeposits << "\n";
    return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (Account::_amount < withdrawal)
        std::cout << "[19920104_091532] index:" << _accountIndex << ";p_amount:" \
         << _amount << ";withdrawal:" << "refused\n";
    else
    {
        _amount -= withdrawal;
        Account::_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        std::cout << "[19920104_091532] index:" << _accountIndex << ";p_amount:" \
            << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << \
            _amount << ";nb_withdrawals:1" << "\n";
    }
    return (1);
}

int		Account::checkAmount( void ) const{
    return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
    std::cout << "[19920104_091532] index:"<< _accountIndex <<";amount:"<< \
    _amount <<";deposits:" << _nbDeposits << ";withdrawals:" << \
    _nbWithdrawals << "\n";
    return ;
}

Account::Account( int initial_deposit )
{
    Account::_accountIndex += _nbAccounts;
    Account::_nbAccounts += 1;
    Account::_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    std::cout << "[19920104_091532] index:" << Account::_accountIndex << \
    ";amount:" << Account::_amount << ";created\n";
    return ;
}

Account::~Account( void )
{
    std::cout << "[19920104_091532] index:" << _accountIndex << ";amount:" \
        << checkAmount() << ";closed\n";
    return ;
}