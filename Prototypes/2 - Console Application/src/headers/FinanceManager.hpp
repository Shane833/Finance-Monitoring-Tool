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
		std::string getPath();
		size_t getSize();
		void addFinanceCategory(std::string title); // Adds a category (like year)
		FinanceCategory* getFinanceCategory(int index);
		FinanceCategory* removeFinanceCategory(std::string title); // removes an expense collection
		void list(); // Lists all the Transactions currently loaded
		
	// private:
		int total; // maintains overall total
		std::vector<FinanceCategory*> categories;
		std::string path; // represents our data directory
};

#endif