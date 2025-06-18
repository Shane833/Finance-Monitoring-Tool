#include <FinanceManager.hpp>

FinanceManager::FinanceManager()
:total(0),path("data")
{
	// check if the data directory exists
	if(std::filesystem::exists(path)){
		load(); // load the data upon startup
		//update(); // load in the right total amount
	}else{
		std::filesystem::create_directory(path);
	}	
}

void FinanceManager::addFinanceCategory(std::string title)
{
	categories.push_back(new FinanceCategory(title,path));
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

std::string FinanceManager::getPath()
{
	return path;
}

void FinanceManager::list()
{
	for(auto fc : categories){ // Going through Finance Categories
		for(int i = 0;i < fc->getSize();i++){ // Going through Managers
			// Print the name of the category
			std::cout << "------***" << fc->getTitle() << "***------"<< std::endl;
			// Print the various transactions
			fc->getTransactionManager(i)->displayTransactions();
		}
	}

}

void FinanceManager::load(){
	// Lets go looping through each of the available subdirectories
	for(const auto &entry : std::filesystem::directory_iterator(path)){
		addFinanceCategory(entry.path().filename().string());
	}
}

void FinanceManager::save()
{
	// Now I want to create subdirectories by the name of the various categories	
	for(auto fcat : categories){
		// only create the subdirectories if they don't exists
		if(!std::filesystem::exists(path + "/" + fcat->getTitle())){
			std::filesystem::create_directory(path + "/" + fcat->getTitle());
		}
	}
}

FinanceManager::~FinanceManager()
{
	save(); // save the data when closing 

	for(auto fc: categories){
		delete fc;
	}
}