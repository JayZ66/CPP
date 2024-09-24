
#include "Account.hpp"

static int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

static int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

static int	getNbDeposits( void )
{
    return _totalNbDeposits;
}

static int	getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}


static void	displayAccountsInfos( void );

Account( int initial_deposit );

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;

static void	_displayTimestamp( void );

Account( void );