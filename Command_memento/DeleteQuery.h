#pragma once
#include "IQuery.h"
#include "vector"

class DeleteQuery :
    public IQuery
{
public:
    using IQuery::IQuery;
    void Execute() override;
};

