#include <ExpenseCollection.hpp>

int main()
{
	ExpenseCollection ec;
	ec.addTransaction("Biscuit",10,ONLINE,DEBIT,FOOD);
	ec.addTransaction("Noodles",60,CASH,DEBIT,FOOD);
	ec.addTransaction("Pizza",100,ONLINE,DEBIT,FOOD);
	ec.displayTransactions();

	
	return 0;
}