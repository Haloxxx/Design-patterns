#pragma once
#include "Memento.h"
#include <string>
class Originator
{
public:
	std::string query;

	void Restore(Memento m);
	Memento* Save();
	void SetState(std::string q);
};

