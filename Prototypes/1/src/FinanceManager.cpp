#include <FinanceManager.hpp>

FinanceManager::FinanceManager()
:total(0)
{
	load(); // load the data upon startup
}

void FinanceManager::load(){}

void FinanceManager::save(){}

void FinanceManager::addFinanceCategory(std::string title)
{
	categories.push_back(new FinanceCategory(title));
}

FinanceCategory* FinanceManager::getFinanceCategory(int index)
{
	return categories[index];
}

void FinanceManager::update()
{
	// Just go through the list of all transaction and add up the sum
	for(auto fc : categories){
		for(size_t i = 0;i < fc->getSize();i++){
			total += (int)fc->getTransactionManager(i)->getTotal();
		}
	}	
}
	


int FinanceManager::getTotal()
{
	return total;
}

FinanceManager::~FinanceManager()
{
	save(); // save the data when closing 

	for(auto fc: categories){
		delete fc;
	}
}