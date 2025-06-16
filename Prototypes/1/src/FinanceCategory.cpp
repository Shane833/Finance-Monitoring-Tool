#include <FinanceCategory.hpp>

FinanceCategory::FinanceCategory(std::string title)
:title(title)
{}

void FinanceCategory::addTransactionManager(std::string title)
{
	managers.push_back(new TransactionManager(title));
}

TransactionManager* FinanceCategory::getTransactionManager(int index)
{
	return managers[index];
}

size_t FinanceCategory::getSize()
{
	return managers.size();
}
