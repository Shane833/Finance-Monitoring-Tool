#include <FinanceManager.hpp>

void FC(FinanceCategory * fcat); // The whole loop for accessing Finance Category features
void TMgr(TransactionManager * tmgr); // The whole loop for accessing the Transaction Manager Features

// Menu Functions
void FM_menu(FinanceManager * fmgr);
void FC_menu(FinanceCategory * fcat);
void TMgr_menu(TransactionManager * tmgr);

// List Functions
void FM_listCategories(FinanceManager * fmgr);
void FC_listManagers(FinanceCategory * fcat);
void TMgr_listTransactions(TransactionManager * tmgr);

// Create Functions
void FM_createCategory(FinanceManager * fmgr);
void FC_createManager(FinanceCategory * fcat);
void TMgr_createTransaction(TransactionManager * tmgr);

// Select Functions
void FM_selectCategory(FinanceManager * fmgr);
void FC_selectManager(FinanceCategory * fcat);

int main(int argc, char* argv[])
{
	
	// I feel this application should be more menu based
	// So, I'll start an infinite loop with options to select from
	FinanceManager fmgr;
	char ch = '\0'; // for choosing various options
	bool quit = false; // variale to quit the application
	
	// Print the menu
	FM_menu(&fmgr);
	
	while(!quit){
		
		while(std::cin >> ch){ // Keep scanning the character
			
			switch(ch){
				case 'a':{ // Quickly adds transactions 
					TMgr_createTransaction(fmgr.getDefaultManager());
					break;
				}
				case 'd':{ // quickly displays those transactions
					TMgr_listTransactions(fmgr.getDefaultManager());
					break;
				}
				case 'c':{ // option to create a category
					// Just learned that we should enclose the statements in switch cases
					// within a block as they are implemented using jump tables and there is
					// no guarantee that the varible you mean to declare will get declared
					FM_createCategory(&fmgr);
					break;
				}
				case 's':{ // option to select a category
					FM_selectCategory(&fmgr);
					break;
				}
				case 'l':{
					FM_listCategories(&fmgr);
					break;
				}
			}
			
			if(ch == 'q') {
				quit = true; // set the quit flag and break the loop
				break;
			} 
			
			// Print the menu
			FM_menu(&fmgr);
		}
	}
	
	return 0;
}

void FC(FinanceCategory * fcat)
{
	// Give a bunch of options as to what you wish to do
	char fch = '\0'; // variable to select options

	// Print the menu
	FC_menu(fcat);
	
	while(std::cin >> fch){
		switch(fch){
			case 'c':{
				FC_createManager(fcat);
				break;
			}
			case 's':{
				FC_selectManager(fcat);
				break;
			}
			case 'l':{
				// List all the managers
				FC_listManagers(fcat);
				break;
			}
		}
		if(fch == 'b') break;
		
		// Print the menu
		FC_menu(fcat);
	}
}

void TMgr(TransactionManager * tmgr)
{
	// Give a bunch of options as to what you wish to do
	char tch = '\0'; // variable to select options

	// Print the menu
	TMgr_menu(tmgr);
	
	while(std::cin >> tch){
		switch(tch){
			case 'c':{
				TMgr_createTransaction(tmgr);
				break;
			}
			case 'l':{
				// List all the managers
				TMgr_listTransactions(tmgr);
				break;
			}
		}
		if(tch == 'b') break;
		
		// Print the menu
		TMgr_menu(tmgr);
	}
}

// Prints the main menu
void FM_menu(FinanceManager * fmgr)
{
	// 1. I want to display a Welcome screen and total money
	std::cout << "\nFINANCE MONITOR v1.0" << std::endl;
	fmgr->displayTotal();
	// 2. Provide a list of options that the user can select
	std::cout << "a - quick add transaction" << std::endl;
	std::cout << "d - quick list current transactions" << std::endl;
	std::cout << "c - create a Category" << std::endl;
	std::cout << "s - select a Category" << std::endl;
	std::cout << "l - list all Categories" << std::endl;
	std::cout << "q - quit and save" << std::endl;
	std::cout << "Enter your choice : ";
}

// Print the category menu
void FC_menu(FinanceCategory * fcat)
{
	std::cout <<"\nSelected Category : " << fcat->getTitle() << std::endl;
	std::cout << "c - create a Manager" << std::endl;
	std::cout << "s - select a Manager" << std::endl;
	std::cout << "l - list all Managers" << std::endl;
	std::cout << "b - back to Monitor menu" << std::endl;
	std::cout << "Enter your choice : ";
}

// Print the transaction manager menu
void TMgr_menu(TransactionManager * tmgr)
{
	std::cout <<"\nSelected Manager : " << tmgr->getTitle() << std::endl;
	std::cout << "c - create a Transaction" << std::endl;
	std::cout << "l - list all Transactions" << std::endl;
	std::cout << "b - back to Category menu" << std::endl;
	std::cout << "Enter your choice : ";
} 

// Create a category
void FM_createCategory(FinanceManager * fmgr)
{
	std::string name;
	std::cout << "Enter the name of your category : ";
	std::cin >> name;
	
	fmgr->addFinanceCategory(name);
	
	std::cout << std::endl;
}

// Create a Manager
void FC_createManager(FinanceCategory * fcat)
{
	std::string title;
	std::cout << "\nEnter the name of Manager : ";
	std::cin >> title;
	
	fcat->addTransactionManager(title);
	
	std::cout << std::endl;
}

// Create a transaction
void TMgr_createTransaction(TransactionManager * tmgr)
{
	std::string activity;
	unsigned int amount; 
	int tmode;
	int ttype; 
	int expense; 
	
	std::cout << "\nEnter the Activity Name : ";
	std::cin >> activity;
	
	std::cout << "Enter the amount : ";
	std::cin >> amount;
	
	std::cout << "Choose the Transaction Mode \n(0 : ONLINE, 1 : CASH)\n";
	std::cout << "Your choice : ";
	std::cin >> tmode;
	
	std::cout << "Enter the Transaction Type \n(0 : CREDIT, 1 : DEBIT)\n";
	std::cout << "Your choice : ";
	std::cin >> ttype;
	
	std::cout << "Enter the Expenditure Category \n(0 : FOOD, 1 : TRAVEL, 2 : BOOKS, 3 : TECH, 4 : MOVIES, 5 : CLOTHES, 6 : DEBT, 7 : BANK\n";
	std::cout << "Your choice : ";
	std::cin >> expense;
	
	tmgr->addTransaction(activity, amount, (TransactionMode)tmode, (TransactionType)ttype, (Expenditure)expense);

	std::cout << std::endl;
}

// Lists all the categories
void FM_listCategories(FinanceManager * fmgr)
{
	// List all the categories by name
	size_t i = 0;
	std::cout << "\nAll Categories : " << std::endl;
	for(i = 0;i < fmgr->getSize();i++){
		std::cout << i+1 << ". " << fmgr->getFinanceCategory(i)->getTitle() << std::endl;
	}
	std::cout << std::endl;
}

// Lists all the managers
void FC_listManagers(FinanceCategory * fcat)
{
	std::cout << "\nAll Managers : " << std::endl;
	size_t i = 0;
	for(i = 0;i < fcat->getSize();i++){
		std::cout << i+1 << ". " << fcat->getTransactionManager(i)->getTitle() << std::endl;
	}
}

// Lists all the transactions
void TMgr_listTransactions(TransactionManager * tmgr)
{
	std::cout << "\nAll Transactions : " << std::endl;
	tmgr->displayTransactions();
}

// Select a Category
void FM_selectCategory(FinanceManager * fmgr)
{
	// Ask for the correct category
	size_t i = 0;
	std::cout << "\nChoose the category(number) : ";
	std::cin >> i;
	// check if the option is correct
	if(i <= fmgr->getSize() && i > 0){
		// Create a pointer to the correct category and ask what you want it to do
		FinanceCategory * fcat = fmgr->getFinanceCategory(i-1);
		if(fcat){
			FC(fcat); // whole Finance Category Menu
		}
	}else{
		std::cout << "Invalid Choice!" << std::endl;
	}
	
	std::cout << std::endl;
}

// Select a Manager
void FC_selectManager(FinanceCategory * fcat)
{
	// Ask for the correct category
	size_t i = 0;
	std::cout << "\nChoose the manager(number) : ";
	std::cin >> i;
	// check if the option is correct
	if(i <= fcat->getSize() && i > 0){
		// Create a pointer to the correct category and ask what you want it to do
		TransactionManager * tmgr = fcat->getTransactionManager(i-1);
		if(tmgr){
			TMgr(tmgr); // whole Transaction Manager Menu
		}
	}else{
		std::cout << "Invalid Choice!" << std::endl;
	}
	
	std::cout << std::endl;
}









