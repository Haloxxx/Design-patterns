#include "IQuery.h"


IQuery::IQuery(sqlite3* d, int r, char* e, Memento* m) 
{
	db = d;
	rc = r;
	error = e;
	mem = m;
}