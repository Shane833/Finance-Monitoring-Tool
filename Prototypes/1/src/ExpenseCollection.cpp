#include <ExpenseCollection.hpp>

ExpenseCollection::ExpenseCollection(std::string title)
:title(title)
{}

std::string ExpenseCollection::getTitle()
{
	return title;
}

void ExpenseCollection::addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense)
{
	collection.push_back(new Transaction(activity,amount,tmode,ttype,expense));
}

void ExpenseCollection::displayTransactions()
{
	int i = 1;
	
	std::cout << title + "\n" << std::endl;
	
	for(Transaction* t: collection){
		std::cout << "Transaction : " << i << std::endl;
		std::cout << "Name : " << t->getActivity() << std::endl;
		std::cout << "Amount : " << t->getAmount() << std::endl;
		std::cout << "Transaction Mode : " << t->getTransactionMode() << std::endl;
		std::cout << "Transaction Type : " << t->getTransactionType() << std::endl;
		std::cout << "Expense Category: " << t->getExpenditure() << std::endl;
		std::cout << "Transaction Time : " << t->getTime() << std::endl;
		i++;
	}
}