#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    char output[50];
    strftime(output, 50, "[%Y%m%d_%H%M%S] ", &datetime);
    std::cout << output ;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _amount += deposit;
    _nbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit 
        << ";deposit" << deposit << ";amount:" << _amount << ";nb_deposits:"
            << _nbDeposits << "\n";
}

int Account::checkAmount() const
{
    return _amount > 0;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int temp = _amount;
    _amount -= withdrawal;
    if (!checkAmount())
    {
        _amount = temp;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" 
            << _amount << ";withdrawal:refused\n";
        return (0);
    }
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << temp 
        << ";withdrawal" << withdrawal << ";amount:" << _amount << ";nb_deposits:"
            << _nbWithdrawals << "\n";
    return (1);
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
        << ";created" << "\n";
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
        << ";closed" << "\n";
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _totalAmount += _amount;
    Account();
}

Account::Account()
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
    
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() + 1 << ";total:" 
        << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:"
            << getNbWithdrawals() << "\n";
}

