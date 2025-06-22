#ifndef __TRANSACTION_MANAGER_H__
#define __TRANSACTION_MANAGER_H__

#include <Transaction.hpp>
#include <vector>
#include <fstream>
#include <filesystem> // Help us create various directories

// This will repesent the collection of transactions for a given period of time 
class TransactionManager
{
	public:
		TransactionManager(std::string title, std::string parent_path);
		~TransactionManager();
		std::string getTitle();
		int getTotalCash();
		int getTotalOnline();
		void addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		void addExistingTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time);
		Transaction* getTransaction(int index);
		size_t getSize();
		void displayTransactions();
		void displayTotal();
		void save();
		void load();
		void updateTotal(); // checks if the total in the file is equal to the total from transactions
						   // If not then simply update the total 
	private:
		// Also a change I wish to include is :
		// The first entry in the transactions will be the total
		// and cannot be updated by the user only by the program
		
		std::string title; // Represents the title of the collection
		std::vector<Transaction*> transactions; // Collection of various transactions
		int total_cash; // maintains a running total of the money in cash
		int total_online; // maintains a running total of the money online
		std::string path; // holds the current location of the manager file
};

#endif