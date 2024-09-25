

/*
Liste d'initialisation :

_accountIndex est initialisé avec la valeur de _nbAccounts, ce qui permet de donner à chaque compte un index unique lors de sa création.
_amount est initialisé avec initial_deposit, ce qui signifie que le montant du compte est défini lors de la création.
_nbDeposits et _nbWithdrawals sont tous deux initialisés à 0, car il s'agit d'un nouveau compte.
Bloc de code :

_displayTimestamp() est appelé pour afficher l'horodatage du moment où le compte est créé.
_nbAccounts est incrémenté pour que le nombre total de comptes augmente de 1 à chaque création de compte.
_totalAmount est mis à jour pour refléter le montant total de tous les dépôts dans les comptes, y compris celui du nouveau compte.
Enfin, un message est affiché avec l'index et le montant du nouveau compte.
*/

/*
void	Account::displayAccountsInfos( void ) // Display total accounts infos
{
	_displayTimestamp();
	std:: cout << "accounts:" << getNbAccounts() << ";total:"
		<< getTotalAmount() << ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}
*\