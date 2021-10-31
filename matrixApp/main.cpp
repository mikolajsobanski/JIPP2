#include <iostream>
#include <cstdlib>
#include "lib.h"

using namespace std;

int ilosc_wierszy,ilosc_kolumn;
int** tabA;
int** tabB;
int** W;
double** tabAD;
double** tabBD;
double** WD;
int x;

int main(int argc, char *argv[]) {

    string choice;

    do {

        if ((!strcmp(argv[1], "addMatrix") || choice == "addMatrix")) {
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabA = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);
                    tabB = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);
                    W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);
                    wpisz_tabB(tabB,ilosc_wierszy,ilosc_kolumn);

                    addMatrix(tabA,tabB,W,ilosc_wierszy,ilosc_kolumn);

                    odczyt(W,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabB, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(W, ilosc_wierszy);
                }
                else if(x==2)
                {
                    cout << "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabAD = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
                    tabBD = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
                    WD = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);
                    wpisz_tabB(tabBD,ilosc_wierszy,ilosc_kolumn);

                    addMatrix(tabAD,tabBD,WD,ilosc_wierszy,ilosc_kolumn);

                    odczyt_double(WD,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabBD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(WD, ilosc_wierszy);
                }

            }while (x!=1 && x!=2);
        }

        else if( (!strcmp(argv[1], "subtractMatrix") || choice == "substractMatrix"))
        {
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabA = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);
                    tabB = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);
                    W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);
                    wpisz_tabB(tabB,ilosc_wierszy,ilosc_kolumn);

                    subtractMatrix(tabA,tabB,W,ilosc_wierszy,ilosc_kolumn);

                    odczyt(W,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabB, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(W, ilosc_wierszy);
                }
                else if(x==2)
                {
                    cout << "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabAD = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
                    tabBD = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
                    WD = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);
                    wpisz_tabB(tabBD,ilosc_wierszy,ilosc_kolumn);

                    subtractMatrix(tabAD,tabBD,WD,ilosc_wierszy,ilosc_kolumn);

                    odczyt_double(WD,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabBD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(WD, ilosc_wierszy);

                }

            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "multiplyMatrix") || choice == "multiplyMatrix"))
        {

            int ilosc_kolumn_macierzB;
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "Podaj ilosc wierszy do macierzy A" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "Podaj ilosc kolumn do macierzy A" << endl;
                    ilosc_kolumn=wczytaj_liczbe();
                    cout << "Podaj ilosc kolumn do macierzy B" << endl;
                    ilosc_kolumn_macierzB=wczytaj_liczbe();

                    tabA = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);
                    tabB = dynamiczna_alokacja(ilosc_kolumn,ilosc_kolumn_macierzB);
                    W = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn_macierzB);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);
                    wpisz_tabB(tabB,ilosc_kolumn,ilosc_kolumn_macierzB);
                    multiplyMatrix(tabA,tabB,W,ilosc_wierszy,ilosc_kolumn,ilosc_kolumn_macierzB);

                    odczyt(W,ilosc_wierszy,ilosc_kolumn_macierzB);

                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabB, ilosc_kolumn);
                    zwalnianie_pamieci_macierz(W, ilosc_wierszy);
                }
                else if(x==2)
                {
                    cout << "Podaj ilosc wierszy do macierzy A" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "Podaj ilosc kolumn do macierzy A" << endl;
                    ilosc_kolumn=wczytaj_liczbe();
                    cout << "Podaj ilosc kolumn do macierzy B" << endl;
                    ilosc_kolumn_macierzB=wczytaj_liczbe();

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);
                    tabBD = dynamiczna_alokacja_double(ilosc_kolumn,ilosc_kolumn_macierzB);
                    WD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn_macierzB);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);
                    wpisz_tabB(tabBD,ilosc_kolumn,ilosc_kolumn_macierzB);
                    multiplyMatrix(tabAD,tabBD,WD,ilosc_wierszy,ilosc_kolumn,ilosc_kolumn_macierzB);

                    odczyt_double(WD,ilosc_wierszy,ilosc_kolumn_macierzB);

                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabBD, ilosc_kolumn);
                    zwalnianie_pamieci_macierz(WD, ilosc_wierszy);

                }

            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "multiplyByScalar") || choice == "multiplyByScalar"))
        {
            int c;
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "podaj ilosc wierszy w macierzy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj ilosc kolum w macierzy" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabA = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);

                    cout << "podaj wartosc do skalaru" << endl;
                    c=wczytaj_liczbe();

                    multiplyByScalar(tabA,ilosc_wierszy,ilosc_kolumn,c);

                    odczyt(tabA,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);

                }
                else if(x==2)
                {
                    cout << "podaj ilosc wierszy w macierzy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj ilosc kolum w macierzy" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);

                    cout << "podaj wartosc do skalaru" << endl;
                    c=wczytaj_liczbe_double();

                    multiplyByScalar(tabAD,ilosc_wierszy,ilosc_kolumn,c);

                    odczyt_double(tabAD,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);

                }

            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "transpozeMatrix") || choice == "transpozeMatrix"))
        {
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "podaj ilosc wierszy macierzy A" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj ilosc kolumn macierzy A" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabA = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);
                    tabB = dynamiczna_alokacja(ilosc_kolumn,ilosc_wierszy);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);

                    transpozeMatrix(tabA,tabB,ilosc_wierszy,ilosc_kolumn);

                    odczyt(tabB,ilosc_kolumn,ilosc_wierszy);

                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabB, ilosc_kolumn);

                }
                else if(x==2)
                {
                    cout << "podaj ilosc wierszy macierzy A" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj ilosc kolumn macierzy A" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);
                    tabBD = dynamiczna_alokacja_double(ilosc_kolumn,ilosc_wierszy);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);

                    transpozeMatrix(tabAD,tabBD,ilosc_wierszy,ilosc_kolumn);

                    odczyt_double(tabBD,ilosc_kolumn,ilosc_wierszy);

                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(tabBD, ilosc_kolumn);

                }

            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "powerMatrix") || choice == "powerMatrix"))
        {
            unsigned n;
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "podaj ilosc wierszy macierzy A" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj ilosc kolumn macierzy A" << endl;
                    ilosc_kolumn=wczytaj_liczbe();
                    cout << "podaj potege" << endl;
                    cin >> n;

                    tabA = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);
                    W = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);

                    powerMatrix(tabA,W,n,ilosc_wierszy,ilosc_kolumn);

                    odczyt(W,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(W, ilosc_wierszy);
                }
                else if(x==2)
                {
                    cout << "podaj ilosc wierszy macierzy A" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout << "podaj ilosc kolumn macierzy A" << endl;
                    ilosc_kolumn=wczytaj_liczbe();
                    cout << "podaj potege" << endl;
                    cin >> n;

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);
                    WD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);

                    powerMatrix(tabAD,WD,n,ilosc_wierszy,ilosc_kolumn);

                    odczyt_double(WD,ilosc_wierszy,ilosc_kolumn);

                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    zwalnianie_pamieci_macierz(WD, ilosc_wierszy);
                }

            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "determinantMatrix") || choice == "determinantMatrix"))
        {
            int   i;               // stopień macierzy
            int * WK;                    // wektor kolumn
            int ** A;                   // macierz

            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout<< "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout<< "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    if(ilosc_wierszy!=ilosc_kolumn)
                    {
                        cout << "macierz nie jest kwadratowa\n";
                        cout<< "podaj liczbe wierszy" << endl;
                        ilosc_wierszy=wczytaj_liczbe();
                        cout<< "podaj liczbe kolumn" << endl;
                        ilosc_kolumn=wczytaj_liczbe();
                        while(ilosc_wierszy!=ilosc_kolumn)
                        {
                            cout << "macierz nie jest kwadratowa\n";
                            cout<< "podaj liczbe wierszy" << endl;
                            ilosc_wierszy=wczytaj_liczbe();
                            cout<< "podaj liczbe kolumn" << endl;
                            ilosc_kolumn=wczytaj_liczbe();
                        }
                    }

                    A = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);          // tworzymy macierz wskaźników

                    wpisz_tabA(A,ilosc_wierszy,ilosc_kolumn);

                    WK = new int [ ilosc_kolumn ];              // tworzymy wiersz kolumn

                    for( i = 0; i < ilosc_kolumn; i++ )         // wypełniamy go numerami kolumn
                        WK [ i ] = i;

                    cout << endl;

                    cout << determinantMatrix ( ilosc_kolumn, 0, WK, A ) << endl; // obliczamy i wyświetlamy wyznacznik

                    delete [ ] WK;                   // usuwamy tablice dynamiczne

                    zwalnianie_pamieci_macierz(A, ilosc_kolumn);
                }
                else if(x==2)
                {

                    cout<< "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout<< "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    if(ilosc_wierszy!=ilosc_kolumn)
                    {
                        cout << "macierz nie jest kwadratowa\n";
                        cout<< "podaj liczbe wierszy" << endl;
                        ilosc_wierszy=wczytaj_liczbe();
                        cout<< "podaj liczbe kolumn" << endl;
                        ilosc_kolumn=wczytaj_liczbe();
                        while(ilosc_wierszy!=ilosc_kolumn)
                        {
                            cout << "macierz nie jest kwadratowa\n";
                            cout<< "podaj liczbe wierszy" << endl;
                            ilosc_wierszy=wczytaj_liczbe();
                            cout<< "podaj liczbe kolumn" << endl;
                            ilosc_kolumn=wczytaj_liczbe();
                        }
                    }

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);          // tworzymy macierz wskaźników

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);

                    WK = new int [ ilosc_kolumn ];              // tworzymy wiersz kolumn

                    for( i = 0; i < ilosc_kolumn; i++ )         // wypełniamy go numerami kolumn
                        WK [ i ] = i;

                    cout << endl;

                    cout << determinantMatrix ( ilosc_kolumn, 0, WK, tabAD ) << endl; // obliczamy i wyświetlamy wyznacznik

                    delete [ ] WK;                   // usuwamy tablice dynamiczne

                    zwalnianie_pamieci_macierz(tabAD, ilosc_kolumn);
                }

            }while (x!=1 && x!=2);

        }
        else if ((!strcmp(argv[1], "matrixIsDiagonal") || choice == "matrixIsDiagonal"))
        {

            bool ok;

            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout<< "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout<< "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    if(ilosc_wierszy!=ilosc_kolumn)
                    {
                        cout << "macierz nie jest kwadratowa\n";
                        cout<< "podaj liczbe wierszy" << endl;
                        ilosc_wierszy=wczytaj_liczbe();
                        cout<< "podaj liczbe kolumn" << endl;
                        ilosc_kolumn=wczytaj_liczbe();
                        while(ilosc_wierszy!=ilosc_kolumn)
                        {
                            cout << "macierz nie jest kwadratowa\n";
                            cout<< "podaj liczbe wierszy" << endl;
                            ilosc_wierszy=wczytaj_liczbe();
                            cout<< "podaj liczbe kolumn" << endl;
                            ilosc_kolumn=wczytaj_liczbe();
                        }
                    }

                    tabA = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);


                    ok=matrixIsDiagonal(tabA,ilosc_wierszy,ilosc_kolumn);
                    if(ok==1)
                    {
                        cout << "Macierz jest diagonalna"  << endl;
                    }
                    else
                    {
                        cout << "Macierz nie jest diagonalna" << endl;
                    }

                }
                else if(x==2)
                {
                    cout<< "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout<< "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    if(ilosc_wierszy!=ilosc_kolumn)
                    {
                        cout << "macierz nie jest kwadratowa\n";
                        cout<< "podaj liczbe wierszy" << endl;
                        ilosc_wierszy=wczytaj_liczbe();
                        cout<< "podaj liczbe kolumn" << endl;
                        ilosc_kolumn=wczytaj_liczbe();
                        while(ilosc_wierszy!=ilosc_kolumn)
                        {
                            cout << "macierz nie jest kwadratowa\n";
                            cout<< "podaj liczbe wierszy" << endl;
                            ilosc_wierszy=wczytaj_liczbe();
                            cout<< "podaj liczbe kolumn" << endl;
                            ilosc_kolumn=wczytaj_liczbe();
                        }
                    }

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);

                    // tutaj jeszcze kurwa musze dodacdouble
                    ok=matrixIsDiagonal(tabA,ilosc_wierszy,ilosc_kolumn);
                    if(ok==1)
                    {
                        cout << "Macierz jest diagonalna"  << endl;
                    }
                    else
                    {
                        cout << "Macierz nie jest diagonalna" << endl;
                    }

                }

            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "swap") || choice == "swap"))
        {
            int a,b;
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "Podaj pierwsza liczbe do zamiany" << endl;
                    a=wczytaj_liczbe();
                    cout << "Podaj druga liczbe do zamiany" << endl;
                    b=wczytaj_liczbe();
                    cout << "Pierwsza podana liczba to: a =  " << a << endl << "druga podana liczba to: b = " << b << endl;
                    swap(a,b);
                    cout << "Po zamianie pierwsza liczba wynosi a = " << a << endl << "druga liczba po zamianie wynosi b = " << b << endl;
                }
                else if(x==2)
                {
                    cout << "Podaj pierwsza liczbe do zamiany" << endl;
                    a=wczytaj_liczbe_double();
                    cout << "Podaj druga liczbe do zamiany" << endl;
                    b=wczytaj_liczbe_double();
                    cout << "Pierwsza podana liczba to: a =  " << a << endl << "druga podana liczba to: b = " << b << endl;
                    swap(a,b);
                    cout << "Po zamianie pierwsza liczba wynosi a = " << a << endl << "druga liczba po zamianie wynosi b = " << b << endl;
                }
            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "sortRow") || choice == "sortRow"))
        {
            int *tab;
            double *tabD;
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout<<"Ile liczb chcesz dodac do tablicy? \n";
                    ilosc_kolumn=wczytaj_liczbe();

                    tab = new int [ilosc_kolumn];

                    for(int i=0;i<ilosc_kolumn;i++)
                    {
                        cout<< "podaj wartosci do tablicy\n";
                        tab[i]=wczytaj_liczbe();
                    }

                    sortRow(ilosc_kolumn,tab);
                    for(int i=0;i<ilosc_kolumn;i++)
                        cout<<tab[i]<<" ";
                    cout << endl;
                    delete [ ] tab;

                }
                else if(x==2)
                {
                    cout<<"Ile liczb chcesz dodac do tablicy? \n";
                    ilosc_kolumn=wczytaj_liczbe();

                    tabD = new double [ilosc_kolumn];

                    for(int i=0;i<ilosc_kolumn;i++)
                    {
                        cout<< "podaj wartosci do tablicy\n";
                        tabD[i]=wczytaj_liczbe_double();
                    }

                    sortRow(ilosc_kolumn,tabD);
                    for(int i=0;i<ilosc_kolumn;i++)
                        cout<<tabD[i]<<" ";
                    cout << endl;
                    delete [ ] tabD;
                }
            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "sortInMatrix") || choice == "sortInMatrix"))
        {
            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout<< "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout<< "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabA = dynamiczna_alokacja(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabA,ilosc_wierszy,ilosc_kolumn);

                    sortRowsInMatrix(tabA,ilosc_wierszy,ilosc_kolumn);

                    odczyt(tabA,ilosc_wierszy,ilosc_kolumn);
                    zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                }
                else if(x==2)
                {
                    cout<< "podaj liczbe wierszy" << endl;
                    ilosc_wierszy=wczytaj_liczbe();
                    cout<< "podaj liczbe kolumn" << endl;
                    ilosc_kolumn=wczytaj_liczbe();

                    tabAD = dynamiczna_alokacja_double(ilosc_wierszy,ilosc_kolumn);

                    wpisz_tabA(tabAD,ilosc_wierszy,ilosc_kolumn);

                    sortRowsInMatrix(tabAD,ilosc_wierszy,ilosc_kolumn);

                    odczyt_double(tabAD,ilosc_wierszy,ilosc_kolumn);
                    zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                }

            }while (x!=1 && x!=2);
        }
        else if((!strcmp(argv[1], "help") || choice == "help"))
        {
            help();

        }
        else if ((!strcmp(argv[1], "exit") || choice == "exit"))
        {
            continue;
        }
        else
        {
            cout << "podano zla nazwe dzialania\n\n\n";
            help();
        }
        cout << "Wybierz dzialanie ktore chcesz dokonac, wpisujac nazwe dzialania\n\n"
                "addMatrix - dodawanie dwoch macierzy\n"
                "subtractMatrix - odejmowanie dwoch macierzy\n"
                "multiplyMatrix - mnozenie dwoch macierzy\n"
                "multiplyByScalar - mnozenie macierzy przez skalar\n"
                "transpozeMatrix - transponowanie macierzy\n"
                "powerMatrix - potegowanie macierzy\n"
                "determinantMatrix - wyznacznik macierzy\n"
                "matrixIsDiagonal - sprawdzenie, czy macierz jest diagonalna\n"
                "swap - zamiana dwoch wartosci miejscami\n"
                "sortRow - sortowanie tablicy za pomoca sortowania bombelkowego\n"
                "sortRowsInMatrix - sortowanie wszystkich wierszy w macierzy\n"
                "help - pomoc, dokumentacja\n"
                "exit - wyjscie z programu\n";
        cout << "\nPodaj nazwe dzialania\n" << endl;
        cin >> choice;
    } while ((argv[1]) != "exit" && choice != "exit");
    return 0;
}
