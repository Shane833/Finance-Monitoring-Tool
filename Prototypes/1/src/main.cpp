#include <FinanceManager.hpp>

int main()
{
	FinanceManager fmgr;
	fmgr.addFinanceCategory("2025");
	fmgr.getFinanceCategory(0)->addTransactionManager("June");
	TransactionManager* tmgr = fmgr.getFinanceCategory(0)->getTransactionManager(0);
	
	tmgr->addTransaction("Biscuit",10,ONLINE,DEBIT,FOOD);
	tmgr->addTransaction("Noodles",60,CASH,DEBIT,FOOD);
	tmgr->addTransaction("Pizza",100,ONLINE,DEBIT,FOOD);
	tmgr->addTransaction("Movies",180,ONLINE,CREDIT,DEBT);
	tmgr->displayTransactions();

	fmgr.update();

	std::cout << fmgr.getTotal() << std::endl;

	return 0;
}