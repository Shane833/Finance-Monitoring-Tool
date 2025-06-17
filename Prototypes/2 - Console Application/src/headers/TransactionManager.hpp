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
		int getTotal();
		void addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense);
		void addExistingTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time);
		Transaction* getTransaction(int index);
		size_t getSize();
		void displayTransactions();
		void save();
		void load();
		
	private:
		std::string title; // Represents the title of the collection
		std::vector<Transaction*> transactions; // Collection of various transactions
		int total; // maintains a running total of the transactions
		std::string path;
};

#endif