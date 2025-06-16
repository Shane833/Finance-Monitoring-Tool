#include <TransactionManager.hpp>

TransactionManager::TransactionManager(std::string title)
:title(title),total(0)
{}

std::string TransactionManager::getTitle()
{
	return title;
}

void TransactionManager::addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense)
{
	transactions.push_back(new Transaction(activity,amount,tmode,ttype,expense));
	// updating the running total
	switch(ttype){
		case DEBIT:
			total -= amount;
			break;
		case CREDIT:
			total += amount;
			break;
	}
}

Transaction* TransactionManager::getTransaction(int index)
{
	return transactions[index];
}

size_t TransactionManager::getSize()
{
	return transactions.size();
}

int TransactionManager::getTotal()
{
	return total;
}

void TransactionManager::displayTransactions()
{
	int i = 1;
	
	std::cout << title + "\n" << std::endl;
	
	for(Transaction* t: transactions){
		std::cout << "Transaction : " << i++ << std::endl;
		std::cout << "Name : " << t->getActivity() << std::endl;
		std::cout << "Amount : " << t->getAmount() << std::endl;
		std::cout << "Transaction Mode : " << t->getTransactionMode() << std::endl;
		std::cout << "Transaction Type : " << t->getTransactionType() << std::endl;
		std::cout << "Expense Category: " << t->getExpenditure() << std::endl;
		std::cout << "Transaction Time : " << t->getTime() << std::endl;
	}
}

TransactionManager::~TransactionManager()
{
	for(auto t : transactions){
		delete t;
	}
}

