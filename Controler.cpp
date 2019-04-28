#include "Controler.h"
#include <iostream>
using namespace std;

Controler::Controler(Map& mapa, Robot* & rob):harta(mapa),robotel(rob)
{
    harta.setelement(0, 0,'R');
    harta.setelement(14,14,'F');
    harta.setelement(1,10,'C');
    harta.setelement(3,12,'C');                             //constructor in care imi creez o harta
    harta.setelement(4,9,'C');
    harta.setelement(6,6,'C');                              //pun capcane iteme locul de start a robotului si pozitia de final pe harta
    harta.setelement(7,8,'C');
    harta.setelement(8,12,'C');
    harta.setelement(9,0,'C');
    harta.setelement(9,2,'C');
    harta.setelement(12,10,'C');
    harta.setelement(13,13,'C');
    harta.setelement(9,6,'C');
    harta.setelement(1,3,'I');
    harta.setelement(1,6,'I');
    harta.setelement(3,13,'I');
    harta.setelement(4,4,'I');
    harta.setelement(5,12,'I');
    harta.setelement(6,2,'I');
    harta.setelement(9,5,'I');
    harta.setelement(9,10,'I');
    harta.setelement(10,13,'I');
    harta.setelement(11,7,'I');
    harta.setelement(12,3,'I');
    harta.setelement(12,1,'I');

    deplasament_linie=new int[5];
    deplasament_coloana= new int[5];
    deplasament_linie[0]=-1;
    deplasament_linie[1]=-1;                //directiile de deplasare pe harta
    deplasament_linie[2]=0;
    deplasament_linie[3]=1;
    deplasament_linie[4]=1;                 //deoarece cerinta zice sa fim mai aproape de pozitia de final cu fiecare pas
    deplasament_coloana[0]=0;               //nu vom merge si in partea stanga
    deplasament_coloana[1]=1;
    deplasament_coloana[2]=1;
    deplasament_coloana[3]=1;
    deplasament_coloana[4]=0;
    Robot_linie=0;
    Robot_coloana=0;                     //initializam coordonatele robotului
}
void Controler:: item(int line, int col)
{
    harta.setelement(Robot_linie, Robot_coloana, 0);              // setam vechia pozitie a robotului ca fiind nula
    harta.setelement(line,col, 'R');                                // iar in locul itemului punem robotul
    Robot_linie=line;                                               //actualizam coordonatele robotului
    Robot_coloana=col;
    if(Robot_linie+1>harta.getlinie()-1 or Robot_coloana+1> harta.getcoloana()-1)   //verificam sa nu iesim din harta
        return;
    int linie_noua=Robot_linie+1;
    int coloana_noua=Robot_coloana+1;           //itemul muta robotul cu o casuta in directia dreapta jos
    if(harta.getelement(linie_noua, coloana_noua)=='F')
        cout<<"Am castigat";
    else if(harta.getelement(linie_noua, coloana_noua)=='C')     //verificam daca se afla ceva pe noua pozitie(final/capcana/item)
        cout<<"Am pierdut :(";
    else if (harta.getelement(linie_noua, coloana_noua)=='I')
        item(linie_noua, coloana_noua);
    else
    {
        harta.setelement(Robot_linie, Robot_coloana, 0);
        harta.setelement(linie_noua,coloana_noua, 'R');          //aceleasi actualizari ca la inceput
        Robot_linie=linie_noua;
        Robot_coloana=coloana_noua;
    }
}
int Controler:: getrobotL()
{
    return Robot_linie;
}
int Controler:: getrobotC()                      // functii pentru a obtine pozitia robotului
{
    return Robot_coloana;
}
ostream& operator<<(ostream& out, Map& mapa)
{
    out<<endl;
    for(int i=0; i<mapa.getlinie(); i++)
        {for( int j=0; j<mapa.getcoloana(); j++)      //supraincarcarea operatorului<< pentru afisarea hartii
            out<<mapa.getelement(i,j)<<" ";
        out<<endl;
        }
    return out;
}
int meniu()
{
cout<<"1)Afisarea configuratiei curente"<<endl;
cout<<"2)Runda urmatoare"<<endl;
cout<<"3)Oprire"<<endl;
cout<<"Introdu numarul ales:"<<endl;
int tasta;                                         //meniu pentru utilizator intre runde
 cin>>tasta;
return tasta;
}
void Controler:: run()
{
    cout<<"The walk"<<endl<<"Apasati tasta 1 pentru a incepe jocul:";          //inceperea jocului
    int tasta;
    cin>>tasta;
 cout<<"Introduceti tipul robotului( 1, 2 sau 3):";                  //utilizatorul alege tipul robotului dorit
    int tip;
    cin>>tip;
    RobotA A;
    RobotB B;
    RobotC C;
    if(tip==1)  robotel=&A;                             //declararea si copierea in robot tipul de robot selectat
    if(tip==2)  robotel=&B;
    if(tip==3)  robotel=&C;
    if(tasta==1)
        while(1)
            { int men=meniu();
            if(men==1) cout<<harta;
            else if (men==3) break;
            else
            {
            Map aux=harta.centreaza(Robot_linie,Robot_coloana);
            int miscare = robotel->misca(harta,Robot_linie, Robot_coloana);         //obtinem directia in care se va misca robotul
            int linie_noua=Robot_linie+deplasament_linie[miscare];
            int coloana_noua=Robot_coloana+deplasament_coloana[miscare];      //actualizam noile coordonate
            if(linie_noua>harta.getlinie()-1 or coloana_noua>harta.getcoloana()-1)
                {cout<<"Ai ieisit din harta"; break;}
            if(harta.getelement(linie_noua, coloana_noua)=='F')                     //verificam daca acea pozitie este in harta sau daca se afla capcana/item/final
                {cout<<"Am castigat"; break;}
            else if(harta.getelement(linie_noua, coloana_noua)=='C')
                {cout<<"Am pierdut :("; break;}                                     //oprim programul in cazul in care dam de capcana sau final sau iesim de pe harta
            else if (harta.getelement(linie_noua, coloana_noua)=='I')
                item(linie_noua, coloana_noua);
            else
            {
                harta.setelement(Robot_linie, Robot_coloana, 0);
                harta.setelement(linie_noua,coloana_noua, 'R');                        // actualizam coordonatele robotului si harta
                Robot_linie=linie_noua;
                Robot_coloana=coloana_noua;
            }
            }
        }

}
Controler:: ~Controler()
{
}
