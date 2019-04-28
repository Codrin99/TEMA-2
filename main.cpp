#include <iostream>
#include "Robot.h"
#include "Map.h"
#include "Controler.h"
using namespace std;

int main()
{   Map M(15,15);
    Robot *R;
    Controler C(M,R);
    C.run();         //rulam jocul
    return 0;
}
