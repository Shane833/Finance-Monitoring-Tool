#include <ExpenseCollection.hpp>

ExpenseCollection::ExpenseCollection()
{}

void ExpenseCollection::addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense)
{
	collection.push_back(new Transaction(activity,amount,tmode,ttype,expense));
}

void ExpenseCollection::displayTransactions()
{
	int i = 1;
	for(Transaction* t: collection){
		std::cout << "Transaction : " << i << std::endl;
		std::cout << "Name : " << t->mu.getActivity() << std::endl;
		std::cout << "Amount : " << t->mu.getAmount() << std::endl;
		std::cout << "Transaction Mode : " << t->mu.getTransactionMode() << std::endl;
		std::cout << "Transaction Type : " << t->getTransactionType() << std::endl;
		std::cout << "Transaction Time : " << t->getTime() << std::endl;
		i++;
	}
}