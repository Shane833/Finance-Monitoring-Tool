#include <Transaction.hpp>

Transaction::Transaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense)
:activity(activity), amount(amount), tmode(tmode), ttype(ttype), expense(expense)
{
	std::time_t t = std::time(nullptr); // Create a Time Object
	time = std::asctime(std::localtime(&t)); // stores the local time as a string
}

// Function to get the amount
int Transaction::getAmount()
{
	return amount;
}

// Function to get the activity
std::string Transaction::getActivity()
{
	return activity;
}
std::string Transaction::getTime()
{
	return time;
}

std::string Transaction::getTransactionType()
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

std::string Transaction::getExpenditure()
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

// Function to get the transaction mode
std::string Transaction::getTransactionMode()
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