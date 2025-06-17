#include <FinanceCategory.hpp>

FinanceCategory::FinanceCategory(std::string title)
:title(title)
{
	load();
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

void FinanceCategory::load()
{
	// This function is called after the object has been created
	// and then I can simply use that data to read a file
	std::ifstream in(title + ".fcat", std::ifstream::in);
	
	if(in){
		std::string tmgr_title;
		while(in >> tmgr_title){
			addTransactionManager(tmgr_title);
		}
	}
}

void FinanceCategory::save()
{
	// I want to save the name of the Transaction Managers and their sizes
	std::ofstream out(title + ".fcat",std::ofstream::out);
	
	if(out){
		for(auto tmgr : managers){
			out << tmgr->getTitle() << "\n";
			// out << tmgr->getSize() << "\n"; I don't think I have to save the sizes
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