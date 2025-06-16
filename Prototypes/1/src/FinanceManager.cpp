#include <FinanceManager.hpp>

FinanceManager::FinanceManager()
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
	if(!categories.empty()){
		
	}
}

FinanceManager::~FinanceManager()
{
	save(); // save the data when closing 
}