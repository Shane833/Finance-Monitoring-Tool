#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#include <string>
#include <ctime> // Helps to handle date and time
#include <iostream>

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
	BANK,
	EC_TOTAL
};

// A Class that defines the transaction itself
class Transaction
{
	public:
		Transaction(std::string activity, unsigned int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		Transaction(std::string activity, unsigned int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time);
		// Get Functions
		unsigned int getAmount();
		std::string getActivity();
		TransactionMode getTransactionMode();
		std::string getTime();
		TransactionType getTransactionType();
		Expenditure getExpenditure();
		// Set Functions
		void setAmount(unsigned int amount);
		// Display Function
		void displayTransaction();	
		
		
		
	private:
		std::string sgetTransactionMode();
		std::string sgetExpenditure();
		std::string sgetTransactionType();
		
		std::string activity; // This defines what activity caused that transaction
		unsigned int amount; // It can be either positive or negative depicting credit or debit
		TransactionMode tmode; // This tells how the transaction was conveyed digital or physical means
		std::string time; // stores the time of the transaction
		TransactionType ttype; // stores the type of the transaction
		Expenditure expense; // Defines the various types of expenditures
		
		
};

#endif