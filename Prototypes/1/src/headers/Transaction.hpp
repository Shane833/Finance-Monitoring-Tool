#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#include <MonetaryUnit.hpp>
#include <string>
#include <ctime> // Helps to handle date and time

// An Enumeration that defines the Transaction Type
enum TransactionType
{
	CREDIT,
	DEBIT,
	TT_TOTAL
};

// An Enumeration that defines the various categories of expenditu3re
enum Expenditure
{
	FOOD,
	TRAVEL,
	BOOKS,
	TECH,
	MOVIES,
	CLOTHES,
	EC_TOTAL
};

// A Class that defines the transaction itself
class Transaction
{
	public:
		Transaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		std::string getTime();
		std::string getTransactionType();
		std::string getExpenditure();
		
		MonetaryUnit mu;
		
	private:
		std::string time; // stores the time of the transaction
		TransactionType ttype; // stores the type of the transaction
		Expenditure expense; // Defines the various types of expenditures
};

#endif