#include <iostream>
#include "CentralWarehouse.h"

CentralWarehouse::CentralWarehouse() {
	data = '\0';
	next = nullptr;
	edgeCase = nullptr;
}

CentralWarehouse::CentralWarehouse(char input) {
	data = input;
	next = nullptr;
	edgeCase = nullptr;
}

void CentralWarehouse::Link(LocalStore*& newStore) {
	if (edgeCase) {
		LocalStore* temp = edgeCase;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newStore;
	}
	else {
		edgeCase = newStore;
	}
}

void CentralWarehouse::PrintStores() {
	std::cout << "Stores Connected to Warehouse " << data << ": \n";

	LocalStore* temp = edgeCase;
    if (temp) while (temp->next) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	if (temp) std::cout << temp->data;
	std::cout << "\n";
}

void CentralWarehouse::PrintAll() {
	CentralWarehouse* temp = this;
	if (temp->next) while (temp->next) {
		temp->PrintStores(); 
		temp = temp->next;
	}
	temp->PrintStores();
}

void CentralWarehouse::LinkWarehouse(char input) {
	if (!next) {
		next = new CentralWarehouse(input);
	}
	else {
		CentralWarehouse* temp = next;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new CentralWarehouse(input);
	}
}

void CentralWarehouse::LinkWarehouse(CentralWarehouse* newWarehouse) {
	if (!next) {
		next = newWarehouse;
	}
	else {
		CentralWarehouse* temp = next;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newWarehouse;
	}
}

char CentralWarehouse::Name() {
	return data;
}

CentralWarehouse::~CentralWarehouse() {
	CentralWarehouse* temp = this;

	while (temp) {
		LocalStore* tempStore = temp->edgeCase;

		while (tempStore) {
			LocalStore* tempNextStore = tempStore->next;
			delete tempStore;
			tempStore = tempNextStore;
		}

		CentralWarehouse* tempNext = temp->next;
		delete temp;
		temp = tempNext;
	}
}