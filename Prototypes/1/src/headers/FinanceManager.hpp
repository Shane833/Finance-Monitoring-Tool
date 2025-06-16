#ifndef __FINANCE_MANAGER_H__
#define __FINANCE_MANAGER_H__

#include <FinanceCategory.hpp>

// This class will maintain a list of various expenses and maintain an overall total
// Also this is the main application that will handle everything
class FinanceManager{
	public:
		FinanceManager(); // Constructor
		~FinanceManager(); // Destructor
		void load(); // Function to load the data
		void save(); // Function to save the data
		void update(); // Function to update the amount
		int getTotal(); 
		void addFinanceCategory(std::string title); // Adds a category (like year)
		FinanceCategory* getFinanceCategory(int index);
		FinanceCategory* removeFinanceCategory(std::string title); // removes an expense collection
		
	private:
		int total; // maintains overall total
		std::vector<FinanceCategory*> categories;
		std::vector<TransactionManager*> managers;
		std::vector<Transaction*> transactions;
};

#endif