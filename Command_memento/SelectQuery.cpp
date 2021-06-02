#include "SelectQuery.h"


void SelectQuery::Execute(){
	std::cout << "Pobieram dane z tabeli test..." << std::endl;
	const char* sqlSelect = "SELECT * FROM test;";
	//char** results = NULL;
	//int rows, columns;
	sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);
	if (rc) {
		std::cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_free(error);
	}
	else {
		// Wy�wietl tabel�
		for (int rowCtr = 0; rowCtr <= rows; ++rowCtr) {
			for (int colCtr = 0; colCtr < columns; ++colCtr) {
				// Oblicz pozycj� kom�rki
				int cellPosition = (rowCtr * columns) + colCtr;
				// Wy�wietl zawarto�� kom�rki
				std::cout.width(12);
				std::cout.setf(std::ios::left);
				std::cout << results[cellPosition];
			}
			std::cout << std::endl;
			// Wy�wietl separator dla nag��wka
			if (0 == rowCtr) {
				for (int colCtr = 0; colCtr < columns; ++colCtr)
				{
					std::cout.width(12);
					std::cout.setf(std::ios::left);
					std::cout << "------------ ";
				}
				std::cout << std::endl;
			}
		}
	}
	sqlite3_free_table(results);
}

