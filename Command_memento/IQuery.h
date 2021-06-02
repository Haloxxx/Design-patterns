#pragma once
#include <iostream>
#include "sqlite3.h"
#include <string>
#include "ICommand.h"
#include "Memento.h"
class IQuery : public ICommand
{
public:
	sqlite3* db;
	int rc;
	char* error;
	Memento* mem;

	IQuery(sqlite3* d, int r, char* e, Memento* m);
};

