#include <FinanceManager.hpp>
#include <cctype> // used for checking the inputs
#include <limits> // used for clearing the stream

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
			
			// flush newline, so that none of the output from last command gets copied
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 			
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 			
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 			
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
	tmgr->displayTotal();
	std::cout << "c - create a Transaction" << std::endl;
	std::cout << "l - list all Transactions" << std::endl;
	std::cout << "b - back to Category menu" << std::endl;
	std::cout << "Enter your choice : ";
} 

// Create a category
void FM_createCategory(FinanceManager * fmgr)
{
	std::string input;
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
	std::cout << "\nEnter the name of category : ";
	std::cin >> input;
	
	// checking the input
	if(!input.empty()){
		// Check if the string alpha num or underscore
		for(char c : input){
			if(!(isalnum(c) || c == '_')){
				input = "Invalid Category Name! (Alphabets, Numbers and Underscores only)";
				goto error;
			}
		}
			fmgr->addFinanceCategory(input);
	}else{
		input = "Empty Input!"; // set the error message
		goto error;
	}

	std::cout << "[INFO] : Added Category - " << input << std::endl;
	std::cout << std::endl;
	return;
error:
	std::cout << "[ERROR] : Failed to add Category - " << input << std::endl;
	std::cout << std::endl;
}

// Create a Manager
void FC_createManager(FinanceCategory * fcat)
{
	std::string input;
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
	std::cout << "\nEnter the name of Manager : ";
	std::cin >> input;
	
	// checking the input
	if(!input.empty()){
		// Check if the string alpha num or underscore
		for(char c : input){
			if(!(isalnum(c) || c == '_')){
				input = "Invalid Manager Name! (Alphabets, Numbers and Underscores only)";
				goto error;
			}
		}
			fcat->addTransactionManager(input);
	}else{
		input = "Empty Input!"; // set the error message
		goto error;
	}

	std::cout << "[INFO] : Added Manager - " << input << std::endl;
	std::cout << std::endl;
	return;
error:
	std::cout << "[ERROR] : Failed to add Manager - " << input << std::endl;
	std::cout << std::endl;
}

// Create a transaction
void TMgr_createTransaction(TransactionManager * tmgr)
{
	std::string input; // string which will hold the input for type checking
					  // also for displaying error messages if encountered
	std::string activity;
	unsigned int amount; 
	int tmode;
	int ttype; 
	int expense; 
	
	std::cout << "\nEnter the Activity Name : ";
	std::cin >> input;
	// checking the input
	if(!input.empty()){
		// Check if the string alpha num or underscore
		for(char c : input){
			if(!(isalnum(c) || c == '_')){
				input = "Invalid Activity Name! (Alphabets, Numbers and Underscores only)";
				goto error;
			}
		}
		activity = input; // simply copy the data
		
	}else{
		input = "Empty Input!"; // set the error message
		goto error;
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
	
	std::cout << "Enter the amount : ";
	std::cin >> input; 
	// check the input
	if(!input.empty()){
		for(char c : input){
			if(!isdigit(c)){
				input = "Invalid Amount!";
				goto error;
			}
		}
		// Set the value
		amount = std::stoi(input); // returns the absolute amount i.e. +ve4
								   // However I won't be needing abs since '-' character is not a digit
								   // which gets checked above
	} else{
		input = "Empty Input!";
		goto error;
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
	
	std::cout << "Choose the Transaction Mode \n(0 : ONLINE, 1 : CASH)\n";
	std::cout << "Your choice : ";
	std::cin >> input;
	// check the input
	if(!input.empty() && input.size() == 1 && isdigit(input[0]) && abs(std::stoi(input)) < TM_TOTAL){
		tmode = std::stoi(input);
	}else{
		input = "Invalid Transaction Mode!";
		goto error;
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
	
	std::cout << "Enter the Transaction Type \n(0 : CREDIT, 1 : DEBIT)\n";
	std::cout << "Your choice : ";
	std::cin >> input;
	// check the input
	if(!input.empty() && input.size() == 1 && isdigit(input[0]) && abs(std::stoi(input)) < TT_TOTAL){
		ttype = std::stoi(input);
	}else{
		input = "Invalid Transaction Type!";
		goto error;
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush newline
	
	std::cout << "Enter the Expenditure Category \n(0 : FOOD, 1 : TRAVEL, 2 : BOOKS, 3 : TECH, 4 : MOVIES, 5 : CLOTHES, 6 : DEBT, 7 : BANK)\n";
	std::cout << "Your choice : ";
	std::cin >> input;
	// check the input
	if(!input.empty() && input.size() == 1 && isdigit(input[0]) && abs(std::stoi(input)) < EC_TOTAL){
		expense = std::stoi(input);
	}else{
		input = "Invalid Expenditure Category!";
		goto error;
	}
	
	tmgr->addTransaction(activity, amount, (TransactionMode)tmode, (TransactionType)ttype, (Expenditure)expense);
	std::cout << "[INFO] : Added Transaction - " << activity << std::endl;
	std::cout << std::endl;
	return;
	
error: // incase the input is invalid
	std::cout << "[ERROR] : Failed to add Transaction - " << input << std::endl;
	std::cout << std::endl;
}

// Lists all the categories
void FM_listCategories(FinanceManager * fmgr)
{
	// List all the categories by name
	// Check if the categories are already loaded
	// and If not then load them
	if(!fmgr->getSize()) fmgr->load();

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
	// First check if the categories are there
	if(!fmgr->getSize()) fmgr->load();
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
