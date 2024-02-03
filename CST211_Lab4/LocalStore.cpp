#include "LocalStore.h"

LocalStore::LocalStore() {
	data = 'u';
	next = nullptr;
}

LocalStore::LocalStore(char input) {
	data = input;
	next = nullptr;
}