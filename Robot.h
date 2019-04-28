#ifndef ROBOT_H
#define ROBOT_H
#include "Map.h"

class Robot
{
public:
    virtual int misca( const Map&, int l, int c)const;                  //clasa principala cu functia virtuala de miscare
    Robot();
    ~Robot();


};
class RobotA:public Robot
{public:
    int misca(const Map& mapa, int l, int c)const                         //robotul de tip A ce se deplaseaza in dreapta pana nu mai poate si apoi in jos
    {
        if(c==mapa.getcoloana()-1) return 4;
        return 2;
    }
};
class RobotB:public Robot
{public:
    int misca(const Map& mapa, int l, int c)const                      //robotul de tip B ce se deplaseaza in trepte (o data dreapta o data in jos)
    {
        if(c==l) return 2;
        return 4;
    }
};

class RobotC:public Robot
{public:
    int misca(const Map& mapa, int l, int c)const
    {
        if(c==mapa.getcoloana()-1 and l==mapa.getlinie()-1)return 0;         //robotul de tip C ce se deplaseaza pe diagonala principala in dreapta jos pana nu mai poate si apoi in sus
        return 3;
    }
};
#endif // ROBOT_H
