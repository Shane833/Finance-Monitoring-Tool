#include <FinanceManager.hpp>

int main(int argc, char* argv[])
{
	// c - create
	// s - select
	// l - list
	
	// The minimum no. of arguments should be 3
	if(argc < 2){
		std::cout << "ERROR : Invalid Arguments!" << std::endl;
		std::cout << "USAGE : ./FinanceMonitor [options] [types]" << std::endl;
		std::cout << "Try \"./FinanceMonitor -h\" for help" << std::endl;
	}
	else{
		FinanceManager fmgr;

		std::string option;
		std::string types;

		switch(argc){
			
			case 2: 
				option = argv[1];

				if(option == "-h"){ // help
					std::cout << "USAGE : ./FinanceMonitor [options] [types]" << std::endl;
					std::cout << "Options : \n";
					std::cout << "-c : create\n-s : select\n-l : list\n-h : help" << std::endl;
					std::cout << "Types : \n";
					std::cout << "-cat (Category) : Defines a bigger collection (Eg - Year)\n";
					std::cout << "-mgr (Manager) : Defines a smaller collection within a Category (Eg - Month)\n";
					std::cout << "-trns (Transaction) : Individual Transaction" << std::endl;
				}
				else if(option == "-l"){ // lists all the transactions
					fmgr.list();
				}
				break;
		
			case 4:
			// Then the possile 
		} 
	}



	return 0;
}