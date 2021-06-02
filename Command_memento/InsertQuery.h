#pragma once
#include "IQuery.h"
class InsertQuery :
    public IQuery
{
public:
    void Execute() override;
    using IQuery::IQuery;
};

