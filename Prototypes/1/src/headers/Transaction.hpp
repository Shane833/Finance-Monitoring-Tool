#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#include <string>
#include <ctime> // Helps to handle date and time

// An Enumeration for defining the mode of transaction
enum TransactionMode{
	ONLINE,
	CASH,
	TM_TOTAL
};

// An Enumeration that defines the Transaction Type
enum TransactionType
{
	CREDIT,
	DEBIT,
	TT_TOTAL
};

// An Enumeration that defines the various categories of expenditure
enum Expenditure
{
	FOOD,
	TRAVEL,
	BOOKS,
	TECH,
	MOVIES,
	CLOTHES,
	DEBT,
	EC_TOTAL
};

// A Class that defines the transaction itself
class Transaction
{
	public:
		Transaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		int getAmount();
		std::string getActivity();
		std::string getTransactionMode();
		std::string getTime();
		std::string getTransactionType();
		std::string getExpenditure();
		
	private:
		std::string activity; // This defines what activity caused that transaction
		unsigned int amount; // It can be either positive or negative depicting credit or debit
		TransactionMode tmode; // This tells how the transaction was conveyed digital or physical means
		std::string time; // stores the time of the transaction
		TransactionType ttype; // stores the type of the transaction
		Expenditure expense; // Defines the various types of expenditures
};

#endif