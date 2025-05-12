#ifndef __EXPENSE_COLLECTION_H__
#define __EXPENSE_COLLECTION_H__

#include <Transaction.hpp>
#include <vector>
#include <iostream>

// This will repesent the collection of expenses/transaction for a given period of time 
class ExpenseCollection
{
	public:
		ExpenseCollection(std::string title);
		std::string getTitle();
		void addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		void displayTransactions();
		
	private:
		std::string title;
		std::vector<Transaction*> collection;
};

#endif