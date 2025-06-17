#ifndef __FINANCE_CATEGORY_H__
#define __FINANCE_CATEGORY_H__

#include <TransactionManager.hpp>
// This class repesents a category which will be a collection of various Transaction Managers
class FinanceCategory{
	public:
		FinanceCategory(std::string title);
		FinanceCategory(std::string title,size_t size);
		~FinanceCategory();
		std::string getTitle();
		void addTransactionManager(std::string title); // adds a transaction manager (like month)
		TransactionManager* getTransactionManager(int index);
		TransactionManager* removeTransactionManager(std::string title);
		size_t getSize();
		void save();
		void load(size_t size);
		
	private:
		std::string title;
		std::vector<TransactionManager*> managers;
};

#endif