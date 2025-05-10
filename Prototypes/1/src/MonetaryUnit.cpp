#include <MonetaryUnit.hpp>

// Constructor
MonetaryUnit::MonetaryUnit(std::string activity, int amount, TransactionMode tmode)
:activity(activity),amount(amount),tmode(tmode){}

// Function to get the amount
int MonetaryUnit::getMU_Amount()
{
	return amount;
}

// Function to get the activity
std::string MonetaryUnit::getMU_Activity()
{
	return activity;
}

// Function to get the transaction mode
TransactionMode MonetaryUnit::getMU_TransactionMode()
{
	return tmode;
}

