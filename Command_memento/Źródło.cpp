#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include "sqlite3.h"
#include <string>
#include "SelectQuery.h"
#include "Caretaker.h"
#include "Originator.h"
#include "InsertQuery.h"
#include "DeleteQuery.h"
#include "UndoCommand.h"

using namespace std;
int main() {
	int rc;
	char* error;
	// Otwórz bazê danych
	cout << "Otwieram baze bazacpp.db..." << endl;
	sqlite3* db;
	rc = sqlite3_open("bazacpp.db", &db);
	if (rc) {
		cerr << "Blad: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return 1;
	}
	else {
		cout << "Baza otwarta poprawnie." << endl << endl;
	}
	// Wykonaj SQL z utworzeniem tabeli
	cout << "Tworze tabele test ..." << endl;
	const char* sqlCreateTable =
		"CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, value STRING);";
	rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
	if (rc) {
		cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << endl;
		sqlite3_free(error);
	}
	else {
		cout << "Tabela utworzona." << endl << endl;
	}

	int loop = 1;
	char key = 'a';

	Caretaker* c = new Caretaker();
	Originator* o = new Originator();

	o->SetState("");
	c->AddMemento(o->Save());

	SelectQuery* select = new SelectQuery(db, rc, error, c->GetMemento());
	InsertQuery* insert = new InsertQuery(db, rc, error, c->GetMemento());
	DeleteQuery* delete_q = new DeleteQuery(db, rc, error, c->GetMemento());
	
	UndoCommand* undo = new UndoCommand(db, rc, error, c->GetMemento());

	while (loop)
	{
		select->Execute();

		cout << "i - wstaw dane, d - usun dane, u - cofnij zmiane\n";
		cin >> key;

		switch (key)
		{
		case 'i':
			insert->Execute();
			break;
		case 'd':
			delete_q->Execute();
			break;
		case 'u':
			if (undo)
			{
				undo->Execute();
			}
			break;
		default:
			std::cout << "Nierozpoznano polecenia\n";
		}

		o->SetState(c->GetMemento()->query);
		c->AddMemento(o->Save());
	}

	// Zamknij bazê
	cout << "Zamykam baze bazacpp.db ..." << endl;
	sqlite3_close(db);
	// Zakoñcz program
	cout << "Nacisnij klawisz, aby kontynuowac..." << endl;
	cin.get();

	return 0;
}