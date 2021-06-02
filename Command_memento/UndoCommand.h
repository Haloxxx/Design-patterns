#pragma once
#include "ICommand.h"
#include "Memento.h"
#include "sqlite3.h"
#include <iostream>

class UndoCommand :
    public ICommand
{
private:
    sqlite3* db;
    int rc;
    char* error;
    Memento* mem = new Memento("");
public:
    UndoCommand(sqlite3* d, int r, char* e, Memento* m);
    void Execute() override;
};

