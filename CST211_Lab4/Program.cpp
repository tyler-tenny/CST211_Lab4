#include <iostream>
#include "CentralWarehouse.h"
#include "LocalStore.h"

int main() {
	char tempInput;
	std::cout << "Enter identifier for Central Warehouse: ";
	std::cin >> tempInput;

	CentralWarehouse* headWarehouse = new CentralWarehouse(tempInput);

	tempInput = 'u';
	CentralWarehouse* current = headWarehouse;
	while (tempInput != '0') {
		while (tempInput != '0') {
			std::cout << "Enter a new identifier for a local store connected to warehouse " << current->Name() << ", or 0 to exit: ";
			std::cin >> tempInput;
			if (tempInput != '0') {
				LocalStore* newStore = new LocalStore(tempInput);
				current->Link(newStore);
			}
		}
		tempInput = 'u';
		std::cout << "Enter a new identifier for a new central warehouse, or 0 to exit: ";
		std::cin >> tempInput;
		if (tempInput != '0') {
			current->LinkWarehouse(tempInput);
			current = current->next;
		}
	}

	headWarehouse->PrintAll();

}

