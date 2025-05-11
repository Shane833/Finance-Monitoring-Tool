#include <iostream>
#include <Transaction.hpp>

int main()
{
	Transaction x("Food",50,TM_ONLINE,TT_DEBIT);
	std::cout << x.getTime() << std::endl;
	std::cout << x.getTransactionType() << std::endl;
	std::cout << x.mu.getAmount() << std::endl;
	std::cout << x.mu.getActivity() << std::endl;
	std::cout << x.mu.getTransactionMode() << std::endl;

	
	return 0;
}