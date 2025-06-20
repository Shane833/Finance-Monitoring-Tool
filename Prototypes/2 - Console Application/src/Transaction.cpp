#include <Transaction.hpp>

Transaction::Transaction(std::string activity, unsigned int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense)
:activity(activity), amount(amount), tmode(tmode), ttype(ttype), expense(expense)
{
	std::time_t t = std::time(nullptr); // Create a Time Object
	time = std::asctime(std::localtime(&t)); // stores the local time as a string
}

Transaction::Transaction(std::string activity, unsigned int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time)
:activity(activity), amount(amount), tmode(tmode), ttype(ttype), expense(expense), time(time)
{}

// Function to get the amount
unsigned int Transaction::getAmount()
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

TransactionMode Transaction::getTransactionMode()
{
	return tmode;
}

TransactionType Transaction::getTransactionType()
{
	return ttype;
}

Expenditure Transaction::getExpenditure()
{
	return expense;
}

void Transaction::setAmount(unsigned int amount){
	this->amount = amount;
}


void Transaction::displayTransaction()
{
	std::cout << "Name : " << getActivity() << std::endl;
	std::cout << "Amount : " << getAmount() << std::endl;
	std::cout << "Transaction Mode : " << sgetTransactionMode() << std::endl;
	std::cout << "Transaction Type : " << sgetTransactionType() << std::endl;
	std::cout << "Expense Category: " << sgetExpenditure() << std::endl;
	std::cout << "Transaction Time : " << getTime() << std::endl;
}

std::string Transaction::sgetTransactionMode()
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

std::string Transaction::sgetExpenditure()
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
		case BANK:
			s_expense = "BANK";
			break;
	}
	
	return s_expense;
}	

std::string Transaction::sgetTransactionType()
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
