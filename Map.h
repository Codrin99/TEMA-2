#ifndef MAP_H
#define MAP_H


class Map
{

    char ** harta;
    int linie;
    int coloana;
public:
    Map( const Map&);           //constructorul de copiere
    Map(int linie, int coloana); // constructorul cu parametri
    int getlinie()const;
    int getcoloana()const;
    char getelement(int line, int col)const;
    Map centreaza(int line, int col) const;       //centrarea pentru campul vizual al robotului
    void setelement(int l, int c, char s);
    ~Map();    //destructor
};

#endif // MAP_H
