//#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS #endif
#include <iostream>
#include "sqlite3.h"
#include <string>
using namespace std;
int main() {
      int rc;
      char *error;
      // Otwórz bazę danych
      cout << "Otwieram baze bazacpp.db..." << endl; sqlite3 *db;
      rc = sqlite3_open("bazacpp.db", &db);
      if (rc) {
            cerr << "Blad: " << sqlite3_errmsg(db) << endl; 
            sqlite3_close(db);
            return 1;
      } else {
            cout << "Baza otwarta poprawnie." << endl << endl; 
      }
      // Wykonaj SQL z utworzeniem tabeli
      cout << "Tworze tabele test ..." << endl; const char *sqlCreateTable =
            "CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, value STRING);"; rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
      if (rc) {
            cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << endl;
            sqlite3_free(error);
      }
      else {
            cout << "Tabela utworzona." << endl << endl;
      }
      // Wykonaj SQL ze wstawieniem danych (piec rekordow)
      cout << "Wstawiam dane do tabeli..." << endl; 
      string sqlInsert, value;
      for (int i = 0; i < 5; i++){
            cout << "Podaj wartosc: ";
            cin >> value;
            sqlInsert = "INSERT INTO test VALUES(NULL, '"; sqlInsert.append(value);
            sqlInsert.append("');");
            rc = sqlite3_exec(db, sqlInsert.c_str(), NULL, NULL, &error); 
            if (rc) {
                  cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << endl;
                  sqlite3_free(error);
            }
            else {
            cout << "Rekord wstawiony poprawnie." << endl << endl;
            } 
      }
      // Wykonaj SQL z pobraniem danych
      cout << "Pobieram dane z tabeli test..." << endl; 
      const char *sqlSelect = "SELECT * FROM test;"; 
      char **results = NULL;
      int rows, columns;
      sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error); 
      if (rc) {
            cerr << "Blad wykonania zapytania: " << sqlite3_errmsg(db) << endl;
            sqlite3_free(error);
      }
      else {
            // Wyświetl tabelę
            for (int rowCtr = 0; rowCtr <= rows; ++rowCtr) {
                  for (int colCtr = 0; colCtr < columns; ++colCtr) {

                        // Oblicz pozycję komórki
                        int cellPosition = (rowCtr * columns) + colCtr; 
                        // Wyświetl zawartość komórki
                        cout.width(12);
                        cout.setf(ios::left);
                        cout << results[cellPosition] << " ";
                  }
                  cout << endl;
                  // Wyświetl separator dla nagłówka
                  if (0 == rowCtr) {
                        for (int colCtr = 0; colCtr < columns; ++colCtr) {
                              cout.width(12);
                              cout.setf(ios::left);
                              cout << "------------ ";
                        }
                  cout << endl;
                  }
            }
      }

sqlite3_free_table(results);
// Zamknij bazę
cout << "Zamykam baze bazacpp.db ..." << endl; 
sqlite3_close(db);
// Zakończ program
cout << "Nacisnij klawisz, aby kontynuowac..." << endl; 
cin.get();
return 0; }