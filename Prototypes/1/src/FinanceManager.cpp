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
	if(categories.size()){
		for(auto category : categories){
			if(category->size()){
				for(int i = 0;i < category->size();i++){
					auto fc = getFinanceCategory(i);
					
					total += getFinanceCategory(i)->getTransactionManager(i)->getTotal();
				}
			}
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
}