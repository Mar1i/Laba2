#include "TRAIN.h"

TRAIN::TRAIN(): number(0),locate(""),time("")
{
}

TRAIN::TRAIN(const TRAIN& obj)
{
    this->number = obj.number;
    this->locate = obj.locate;
    this->time = obj.time;
}

TRAIN::TRAIN(int _number, string _locate, string _time)
{
    this->number = _number;
    this->locate = _locate;
    this->time = _time;
}

int TRAIN::getNumber()
{
    return this->number;
}

string TRAIN::getLoacate()
{
    return this->locate;
}

string TRAIN::getTime()
{
    return this->time;
}

void TRAIN::setNumber(int _number)
{
    this->number = _number;
}

void TRAIN::setLocate(string _locate)
{
    this->locate = _locate;
}

void TRAIN::setTime(string _time)
{
    this->time = _time;
}

TRAIN& TRAIN::operator=(const TRAIN& obj)
{
    this->number = obj.number;
    this->locate = obj.locate;
    this->time = obj.time;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const TRAIN& other)
{
    out << other.locate << "\tN:" << other.number << "\tstart: " << other.time << "\n";

    return out;
}

bool operator<(const TRAIN& ob1, const TRAIN& ob2)
{
    return (ob1.number < ob2.number)?true:false;
}

bool operator>(const TRAIN& ob1, const TRAIN& ob2)
{
    return (ob1.number > ob2.number) ? true : false;
}

bool operator==(const TRAIN& ob1, const TRAIN& ob2)
{
    return (ob1.number == ob2.number) ? true : false;
}

bool operator!=(const TRAIN& ob1, const TRAIN& ob2)
{
    return (ob1.number != ob2.number) ? true : false;
}
