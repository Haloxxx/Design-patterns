#include "Originator.h"

Memento* Originator::Save()
{
	return new Memento(query);
};

void Originator::Restore(Memento m)
{
	query = m.query;
}

void Originator::SetState(std::string q)
{
	query = q;
}
