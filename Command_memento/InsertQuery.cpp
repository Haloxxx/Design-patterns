#include "InsertQuery.h"


void InsertQuery::Execute() 
{
	std::cout << "Wstawiam dane do tabeli..." << std::endl;
	std::string sqlInsert, value;
	
	std::cout << "Podaj wartosc: ";
	std::cin >> value;


	sqlInsert = "INSERT INTO test VALUES(NULL, '";
	sqlInsert.append(value);
	sqlInsert.append("');");
	rc = sqlite3_exec(db, sqlInsert.c_str(), NULL, NULL, &error);
	if (rc) {
		std::cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_free(error);
	}
	else {
		std::cout << "Rekord wstawiony poprawnie." << std::endl << std::endl;

		std::string helper = "SELECT MAX(ID) FROM test;";

		char** results = NULL;
		int rows, columns;

		sqlite3_get_table(db, helper.c_str(), &results, &rows, &columns, &error);

		std::string query = "DELETE FROM test WHERE ID ='";
		query.append(results[1]);
		query.append("';");

		mem->query = query;

		sqlite3_free_table(results);
	}
}
