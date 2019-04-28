#include "Map.h"

Map::Map(int line, int col):linie(line),coloana(col)
{
    harta=new char*[linie+4];
    for(int i=0; i<linie+4; i++)                   //alocarea dinamica a hartii +4 (campul vizual al robotului in cazul in care se afla aproape de margine
        harta[i]=new char[coloana+4];
    for( int i=0; i<linie; i++)
        for( int j=0; j< coloana; j++)
            harta[i][j]='0';                      //initializarea matricii cu caracterul 0
}
int Map:: getlinie() const
{
    return linie;
}
int Map:: getcoloana() const
{
    return coloana;
}
void Map::setelement(int l, int c, char s)
{
    harta[l][c]=s;
}
char Map::getelement(int line, int col)const
{
    return harta[line][col];
}

Map:: Map(const Map& other):linie{other.linie},coloana{other.coloana}      //constructorul prin copiere
{
    harta=new char*[linie+4];
    for(int i=0; i<linie+4; i++)                                    //la fel ca in constrcutorul cu parametri doar ca in plus copiem elementele
        harta[i]=new char[coloana+4];
    for( int i=0; i<linie; i++)
        for( int j=0; j< coloana; j++)
            harta[i][j]=other.harta[i][j];
}
Map Map:: centreaza(int line, int col)const
{
    Map aux(4,4);
    for(int i=0; i<4; i++)                                  //centrarea hartii
        for(int j=0; j<4; j++)
        {
            if(i+line>linie or j+col>coloana)                         //daca robotul se uita in afara hartii se va considera elementrul ca fiind capcana
                aux.harta[i][j]='C';
            else
                aux.harta[i][j]=harta[i+line][j+col];
        }
    return aux;
}
Map::~Map()
{
    for(int i=0; i<linie; i++)
        delete[] harta[i];                 //dezalocarea hartii
    delete[] harta;
}
