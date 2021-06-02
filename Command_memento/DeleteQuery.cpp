#include "DeleteQuery.h"

void DeleteQuery::Execute()
{
	std::cout << "Usuwam dane z tabeli..." << std::endl;
	std::string sqlDelete, value;

	std::cout << "Ktory rekord chcesz usunac (a - wszystkie): ";
	std::cin >> value;


	if (value != "a")
	{ 
		std::string helper = "SELECT value FROM test WHERE id ='";
		helper.append(value);
		helper.append("';");

		char** results = NULL;
		int rows, columns;

		sqlite3_get_table(db, helper.c_str(), &results, &rows, &columns, &error);

		std::string query = "INSERT INTO test VALUES('";
		query.append(value);
		query.append("','");
		query.append(results[1]);
		query.append("');");

		mem->query = query;

		sqlite3_free_table(results);
	
	}
	else
	{
		std::vector<std::string> ids;
		std::vector<std::string> values;

		char** results = NULL;
		int rows, columns;

		std::string helper = "SELECT id, value FROM test;";

		sqlite3_get_table(db, helper.c_str(), &results, &rows, &columns, &error);

		for (int rowCtr = 0; rowCtr <= rows; ++rowCtr) {
			for (int colCtr = 0; colCtr < columns; ++colCtr) {
				// Oblicz pozycjê komórki
				int cellPosition = (rowCtr * columns) + colCtr;

				if (cellPosition % 2)
				{
					values.push_back(results[cellPosition]);
				}

				else
				{
					ids.push_back(results[cellPosition]);
				}
			}
		}


		std::string query = "INSERT INTO test VALUES";

		for (int i = 1; i < ids.size(); i++) {
			query.append(" ('");
			query.append(ids[i]);
			query.append("','");
			query.append(values[i]);
			query.append("')");

			if (i < ids.size()-1)
			{ 
				query.append(",");
			}
		}

		query.append(";");

		mem->query = query;

		sqlite3_free_table(results);
	}

	

	
	sqlDelete = "DELETE FROM test WHERE ID ='";
	sqlDelete.append(value);
	sqlDelete.append("';");
	if (value == "a")
	{
		sqlDelete = "DELETE FROM test;";
	}
	rc = sqlite3_exec(db, sqlDelete.c_str(), NULL, NULL, &error);
	if (rc) {
		std::cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_free(error);
	}
	else {
		std::cout << "Rekord/y usuniety/e poprawnie." << std::endl << std::endl;
	}
}

