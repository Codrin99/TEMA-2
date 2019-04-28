#ifndef CONTROLER_H
#define CONTROLER_H
#include "Map.h"
#include "Robot.h"
#include <iostream>
using namespace std;

class Controler
{
    int Robot_linie, Robot_coloana;
    int* deplasament_linie, *deplasament_coloana;
    Map harta;
    Robot * robotel;
public:
    Controler(Map &, Robot * &);
    ~Controler();
    void run();              //functie pebntru rularea jocului
    friend ostream& operator<<(ostream&, Map);
    void item(int line, int col);
    int getrobotL();
    int getrobotC();
};

#endif // CONTROLER_H
