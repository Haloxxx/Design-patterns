#ifndef ICoordinates_H
#define ICoordinates_H

#include <string>

class ICoordinates
{
    public:
        virtual ~ICoordinates(){};
        virtual int setCoordinates(std::string kordy) = 0;
        virtual void printCoordinates() = 0;
};


using ICoordinatesFactory = std::function<std::unique_ptr<ICoordinates>()>;

#endif