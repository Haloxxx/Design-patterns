#include "UndoCommand.h"


UndoCommand::UndoCommand(sqlite3* d, int r, char* e, Memento* m)
{
	db = d;
	rc = r;
	error = e;
	mem = m;
}

void UndoCommand::Execute()
{
	rc = sqlite3_exec(db, mem->query.c_str(), NULL, NULL, &error);
	if (rc) {
		std::cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_free(error);
	}
	else {
		std::cout << "Poprawnie cofnieto" << std::endl << std::endl;
	}
}