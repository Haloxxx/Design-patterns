#pragma once
#include "IQuery.h"

class SelectQuery :
    public IQuery
{
public:
    char** results = NULL;
    int rows, columns;
    using IQuery::IQuery;
    void Execute() override;
};

