#include <TransactionManager.hpp>

TransactionManager::TransactionManager(std::string title, std::string parent_path)
:title(title),total_cash(0),total_online(0)
{
	path = parent_path + "/" + title + ".tmgr";
	// only load if the file exists
	if(std::filesystem::exists(path)){
		load();
	}
}

std::string TransactionManager::getTitle()
{
	return title;
}

void TransactionManager::addTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense)
{
	transactions.push_back(new Transaction(activity,amount,tmode,ttype,expense));
	// updating the running total
	switch(ttype){
		case DEBIT:
			if(tmode == CASH) total_cash -= amount;
			else total_online -= amount;
			break;
			
		case CREDIT:
			if(tmode == CASH) total_cash += amount;
			else total_online += amount;
			break;
	}
}

void TransactionManager::addExistingTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time)
{
	transactions.push_back(new Transaction(activity,amount,tmode,ttype,expense,time));
	// don't need to update the total from here since it will be read from the file
}

Transaction* TransactionManager::getTransaction(int index)
{
	return transactions[index];
}

size_t TransactionManager::getSize()
{
	return transactions.size();
}

int TransactionManager::getTotalCash()
{
	return total_cash;
}

int TransactionManager::getTotalOnline()
{
	return total_online;
}

void TransactionManager::displayTransactions()
{
	size_t i = 1;
	
	// Update to start displaying the transactions from 1st index
	for(Transaction* t : transactions){
		std::cout << "Transaction : " << i++ << std::endl;
		t->displayTransaction();
		std::cout << std::endl;
	}
}

void TransactionManager::load()
{
	std::ifstream in(path, std::ifstream::in);
	
	if(in){
		// now first we will load in the total cash and total online amounts
		int cash = 0, online = 0;
		if(in >> cash >> online){
			total_cash = cash;
			total_online = online;
		}
		else return; // File is empty
		
		// Read the data and load it up
		std::string activity;
		int amount;
		int tmode;
		int ttype;
		int expense;
		std::string time;
		
		while(in >> activity >> amount >> tmode >> ttype >> expense){
			if(getline(in,time)){
				time.erase(0,1); // removing the excess space that gets appended at the beginning
				addExistingTransaction(activity, amount, (TransactionMode)tmode, (TransactionType)ttype, (Expenditure)expense, time);	
			}
		}
	}
}


void TransactionManager::save()
{
	std::ofstream out(path,std::ofstream::out);
	
	if(out){
		// first we will write the total cash and total online amount
		out << total_cash << " " << total_online << "\n";
		// Then write the subsequent data
		for(Transaction * t: transactions){
			out << t->getActivity() << " " << t->getAmount() 
									<< " " << t->getTransactionMode() 
									<< " " << t->getTransactionType()
									<< " " << t->getExpenditure()
									<< " " << t->getTime() << "\n";
		}
	}
	
	out.close();
}

TransactionManager::~TransactionManager()
{
	// Save the data before closing it
	save();
	for(auto t : transactions){
		delete t;
	}
}

