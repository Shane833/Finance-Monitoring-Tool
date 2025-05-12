#include <ExpenseCollection.hpp>

int main()
{
	ExpenseCollection ec("Expenses May 2025");
	ec.addTransaction("Biscuit",10,ONLINE,DEBIT,FOOD);
	ec.addTransaction("Noodles",60,CASH,DEBIT,FOOD);
	ec.addTransaction("Pizza",100,ONLINE,DEBIT,FOOD);
	ec.addTransaction("Movies",180,ONLINE,CREDIT,DEBT);
	ec.displayTransactions();

	return 0;
}