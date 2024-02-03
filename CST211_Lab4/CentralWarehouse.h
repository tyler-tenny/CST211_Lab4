#pragma once
#include "LocalStore.h"

class CentralWarehouse
{
	char data;
	public: CentralWarehouse* next;
	LocalStore* edgeCase;

public :
	CentralWarehouse();
	CentralWarehouse(char input);
	void Link(LocalStore*& newStore);
	void PrintStores();
	void PrintAll();
	void LinkWarehouse(char input);
	void LinkWarehouse(CentralWarehouse* newWarehouse);
	char Name();
	~CentralWarehouse();
};

