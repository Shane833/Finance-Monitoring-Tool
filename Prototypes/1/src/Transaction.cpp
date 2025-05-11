#include <Transaction.hpp>

Transaction::Transaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype)
:mu(activity, amount, tmode), ttype(ttype)
{
	std::time_t t = std::time(nullptr); // Create a Time Object
	time = std::asctime(std::localtime(&t)); // stores the local time as a string
}

std::string Transaction::getTime()
{
	return time;
}

TransactionType Transaction::getTransactionType()
{
	return ttype;
}