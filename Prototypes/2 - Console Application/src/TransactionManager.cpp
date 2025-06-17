#include <TransactionManager.hpp>

TransactionManager::TransactionManager(std::string title, std::string parent_path)
:title(title),total(0)
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
			total -= amount;
			break;
		case CREDIT:
			total += amount;
			break;
	}
}

void TransactionManager::addExistingTransaction(std::string activity, int amount, TransactionMode tmode, TransactionType ttype, Expenditure expense, std::string time)
{
	transactions.push_back(new Transaction(activity,amount,tmode,ttype,expense,time));
	// updating the running total
	switch(ttype){
		case DEBIT:
			total -= amount;
			break;
		case CREDIT:
			total += amount;
			break;
	}
}

Transaction* TransactionManager::getTransaction(int index)
{
	return transactions[index];
}

size_t TransactionManager::getSize()
{
	return transactions.size();
}

int TransactionManager::getTotal()
{
	return total;
}

void TransactionManager::displayTransactions()
{
	int i = 1;
	
	std::cout << title + "\n" << std::endl;
	
	for(Transaction* t: transactions){
		std::cout << "Transaction : " << i++ << std::endl;
		t->displayTransaction();
		std::cout << std::endl;
	}
}

void TransactionManager::load()
{
	std::ifstream in(path, std::ifstream::in);
	
	if(in){
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

