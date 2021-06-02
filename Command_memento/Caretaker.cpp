#include "Caretaker.h"

void Caretaker::AddMemento (Memento* d) {
	db = d;
}

Memento* Caretaker::GetMemento() {
	return db;
}