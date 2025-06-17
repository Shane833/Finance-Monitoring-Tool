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
	EC_TOTAL
};

// A Class that defines the transaction itself
class Transaction
{
	public:
		Transaction(std::string activity, unsigned int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		Transaction(std::string activity, unsigned int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time);
		unsigned int getAmount();
		std::string getActivity();
		TransactionMode getTransactionMode();
		std::string getTime();
		TransactionType getTransactionType();
		Expenditure getExpenditure();
		void displayTransaction();	
		
	private:
		// Function to get the transaction mode
		std::string sgetTransactionMode()
		{
			std::string s_tmode;
			
			switch(tmode)
			{
				case ONLINE:
					s_tmode = "ONLINE";
					break;
				
				case CASH:
					s_tmode = "CASH";
					break;
			}
			
			return s_tmode;
		}
		std::string sgetExpenditure()
		{
			std::string s_expense;
			
			switch(expense){
				case FOOD:
					s_expense = "FOOD";
					break;
				case TRAVEL:
					s_expense = "TRAVEL";
					break;
				case BOOKS:
					s_expense = "BOOKS";
					break;
				case TECH:
					s_expense = "TECH";
					break;
				case MOVIES:
					s_expense = "MOVIES";
					break;
				case CLOTHES:
					s_expense = "CLOTHES";
					break;
				case DEBT:
					s_expense = "DEBT";
					break;
			}
			
			return s_expense;
		}	
		
		std::string sgetTransactionType()
		{
			std::string s_ttype;
			
			switch(ttype){
				case CREDIT:
					s_ttype = "CREDIT";
					break;
					
				case DEBIT:
					s_ttype = "DEBIT";
					break;
			}
			
			return s_ttype;
		}
		
		std::string activity; // This defines what activity caused that transaction
		unsigned int amount; // It can be either positive or negative depicting credit or debit
		TransactionMode tmode; // This tells how the transaction was conveyed digital or physical means
		std::string time; // stores the time of the transaction
		TransactionType ttype; // stores the type of the transaction
		Expenditure expense; // Defines the various types of expenditures
		
		
};

#endif