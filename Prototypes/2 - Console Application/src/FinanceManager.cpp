#include <FinanceManager.hpp>

FinanceManager::FinanceManager()
:path("data")
{
	// check if the data directory exists
	if(!std::filesystem::exists(path)){
		std::filesystem::create_directory(path);
	}
	// however do the default transaction Manager
	tmgr = new TransactionManager("default",path);
}

void FinanceManager::addFinanceCategory(std::string title)
{
	categories.push_back(new FinanceCategory(title,path));
}

FinanceCategory* FinanceManager::getFinanceCategory(int index)
{
	return categories[index];
}
	
std::string FinanceManager::getPath()
{
	return path;
}

size_t FinanceManager::getSize()
{
	return categories.size();
}

TransactionManager* FinanceManager::getDefaultManager()
{
	return tmgr;
}

void FinanceManager::displayTotal()
{
	std::cout << "Total : " << tmgr->getTotalCash() + tmgr->getTotalOnline() 
			  << " (Cash : " << tmgr->getTotalCash() << ", Online : " << tmgr->getTotalOnline()
			  << ")" << std::endl;	
}


void FinanceManager::load(){
	// Lets go looping through each of the available subdirectories
	for(const auto &entry : std::filesystem::directory_iterator(path)){
		// Only load it in if its a directory
		if(std::filesystem::is_directory(entry.path())){
			addFinanceCategory(entry.path().filename().string());
		}
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

	delete tmgr;
	
	for(auto fc: categories){
		delete fc;
	}
}