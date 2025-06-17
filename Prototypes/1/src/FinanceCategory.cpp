#include <FinanceCategory.hpp>

FinanceCategory::FinanceCategory(std::string title)
:title(title)
{}

FinanceCategory::FinanceCategory(std::string title,size_t size)
:title(title)
{
	load(size);
}

void FinanceCategory::addTransactionManager(std::string title)
{
	managers.push_back(new TransactionManager(title));
}

TransactionManager* FinanceCategory::getTransactionManager(int index)
{
	return managers[index];
}

std::string FinanceCategory::getTitle()
{
	return title;
}

size_t FinanceCategory::getSize()
{
	return managers.size();
}

void FinanceCategory::load(size_t size)
{
	
}

void FinanceCategory::save()
{
	// I want to save the name of the Transaction Managers and their sizes
	std::ofstream out(title + ".fcat",std::ofstream::out);
	
	if(out){
		for(auto tmgr : managers){
			out << tmgr->getTitle() << "\n";
			out << tmgr->getSize() << "\n";
		}
	}
	
	out.close();
}

FinanceCategory::~FinanceCategory()
{
	// Save the data before closing
	save();
	
	for(auto tmgr: managers){
		delete tmgr;
	}
}