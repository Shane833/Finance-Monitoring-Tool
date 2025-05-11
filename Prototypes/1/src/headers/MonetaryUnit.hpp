#ifndef __MONETARY_UNIT_H__
#define __MONETARY_UNIT_H__

#include <string>

// A little handy enumeration for defining the mode of transaction
enum TransactionMode{
	ONLINE,
	CASH,
	TM_TOTAL
};

// This class represents the smallest unit that is part of a transaction
// This can be either a debit or a credit
class MonetaryUnit
{
	public:
		MonetaryUnit(std::string activity, int amount, TransactionMode tmode);
		// Basic getter functions
		int getAmount();
		std::string getActivity();
		std::string getTransactionMode();
		
	private:
		std::string activity; // This defines what activity caused that transaction
		unsigned int amount; // It can be either positive or negative depicting credit or debit
		TransactionMode tmode; // This tells how the transaction was conveyed digital or physical means
};

#endif