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

void Transaction::displayTransaction()
{
	std::cout << "Name : " << getActivity() << std::endl;
	std::cout << "Amount : " << getAmount() << std::endl;
	std::cout << "Transaction Mode : " << sgetTransactionMode() << std::endl;
	std::cout << "Transaction Type : " << sgetTransactionType() << std::endl;
	std::cout << "Expense Category: " << sgetExpenditure() << std::endl;
	std::cout << "Transaction Time : " << getTime() << std::endl;
}