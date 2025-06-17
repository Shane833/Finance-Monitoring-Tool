#include <FinanceManager.hpp>

FinanceManager::FinanceManager()
:total(0)
{
	load(); // load the data upon startup
	// update(); // load in the right total amount
}

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

void FinanceManager::load(){
	// load the file named data.fmgr and create the objects with their respective names
	// and sizes
	std::ifstream in("data.fmgr", std::ifstream::in);
	
	if(in){		
		std::string title;
		while(in >> title){ // loop until the end of file
			addFinanceCategory(title);
		}
	}
}

void FinanceManager::save()
{
	// I want to save the name of the Finance Categories and their sizes
	std::ofstream out("data.fmgr",std::ofstream::out);
	
	if(out){		
		for(auto fcat : categories){
			out << fcat->getTitle() << "\n";
			// out << fcat->getSize() << "\n"; I figured I didn't need to save their sizes
		}
	}
	
	out.close();
}

FinanceManager::~FinanceManager()
{
	save(); // save the data when closing 

	for(auto fc: categories){
		delete fc;
	}
}