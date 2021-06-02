#pragma once
#include "Memento.h"

class Caretaker
{
private:
	Memento* db = new Memento("");

public:
	void AddMemento(Memento* d);
	Memento* GetMemento();
};

