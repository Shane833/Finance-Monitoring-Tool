#include <FinanceCategory.hpp>

FinanceCategory::FinanceCategory(std::string title, std::string parent_path)
:title(title)
{
	path = parent_path + "/" + title; // stores its current path
	// only loads data if subdirectory exists
	if(std::filesystem::exists(path)){
		load();
	}else{
		std::filesystem::create_directory(path);
	}
}

void FinanceCategory::addTransactionManager(std::string title)
{
	managers.push_back(new TransactionManager(title,path));
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
	// We will go inside the directory and list all the *.tmgr files
	for(const auto &entry : std::filesystem::directory_iterator(path)){
		if(entry.path().extension() == ".tmgr"){
			addTransactionManager(entry.path().stem().string()); // only gets the filename without extension
		}
	}
}

void FinanceCategory::save()
{
	// Actually nothing really left to save here, just have to make sure that the 
	// directory exists here
	if(!std::filesystem::exists(path)){
		std::filesystem::create_directory(path);
	}
}

FinanceCategory::~FinanceCategory()
{
	// Save the data before closing
	save();
	
	for(auto tmgr: managers){
		delete tmgr;
	}
}