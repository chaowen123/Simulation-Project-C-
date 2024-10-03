#include "person.h"

Person::Person(const Position &pos, char type)
{
    this->pos = new Position(pos);
    this->type = type;
}
Position* Person::getPosition() const
{
    return this->pos;
}
 char Person::getType() const
 {
     return this->type;
 }
Person::~Person() {
    delete this->pos; 
}