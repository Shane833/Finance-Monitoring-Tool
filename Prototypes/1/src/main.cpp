#include <MonetaryUnit.hpp>
#include <iostream>

int main()
{
	MonetaryUnit x("Kurkure", 20, TM_CASH);
	
	std::cout << x.getMU_Amount() << std::endl;
	std::cout << x.getMU_Activity() << std::endl;
	std::cout << x.getMU_TransactionMode() << std::endl;
	
	return 0;
}