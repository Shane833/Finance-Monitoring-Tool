#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#include <MonetaryUnit.hpp>
#include <string>
#include <ctime> // Helps to handle date and time

// An Enumeration that defines the Transaction Type
enum TransactionType
{
	TT_CREDIT,
	TT_DEBIT,
	TT_TOTAL
};

// A Class that defines the transaction itself
class Transaction
{
	public:
		Transaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype);
		std::string getTime();
		TransactionType getTransactionType();
		
		MonetaryUnit mu;
		
	private:
		std::string time; // stores the time of the transaction
		TransactionType ttype; // stores the type of the transaction
};

#endif