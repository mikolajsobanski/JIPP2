#include <iostream>
#include <cstdlib>
#include "lib.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

int ilosc_wierszy,ilosc_kolumn;
int** tabA;
int** tabB;
int** W;
double** tabAD;
double** tabBD;
double** WD;
int x;
int ilosc_kolumn_macierzB;
pair<int, int> matrixSize;
string choice;

int losuj_pare()
{
    matrixSize.first = 1 + rand() % (10 - 2);

    matrixSize.second = 1 + rand() % (10 - 2);

    return matrixSize.first,matrixSize.second;
}

int main(int argc, char *argv[]) {

    do {

       //   if ( _stricmp( argv[1], "addMatrix" ) == 0  && (argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
            if(!strcmp(argv[1], "addMatrix") && (argc == 3) && (!strcmp(argv[2], "generate"))){
            losuj_pare();
            double wybor_dolny = -100 + (double) rand() / RAND_MAX * (200);
            double wybor_gorny = -100 + (double) rand() / RAND_MAX * (200);
            odczyt_double(addMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),
                             matrixGenerate(matrixSize, wybor_dolny, wybor_gorny), matrixSize.first,  matrixSize.second),
                   matrixSize.first,  matrixSize.second);
        }
        else if (!strcmp(argv[1], "subtractMatrix") && (argc == 3) && (!strcmp(argv[2], "generate"))) {
            losuj_pare();
            double wybor_dolny = -100 + (double) rand() / RAND_MAX * (200);
            double wybor_gorny = -100 + (double) rand() / RAND_MAX * (200);

            odczyt_double(subtractMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),
                                  matrixGenerate(matrixSize, wybor_dolny, wybor_gorny), matrixSize.first,  matrixSize.second),
                   matrixSize.first,  matrixSize.second);
        }

       else if (  !strcmp(argv[1], "addMatrix")  || choice == "addMatrix") {
           /* if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                double wybor_dolny = -100 + (double) rand() / RAND_MAX * (200);

                double wybor_gorny = -100 + (double) rand() / RAND_MAX * (200);


                odczyt(addMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),
                                 matrixGenerate(matrixSize, wybor_dolny, wybor_gorny), matrixSize.first,  matrixSize.second),
                       matrixSize.first,  matrixSize.second);
            } else {*/
                do {
                    cout << "DODAWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
                        tabB = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabB, ilosc_wierszy, ilosc_kolumn);


                        odczyt(addMatrix(tabA, tabB, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabB, ilosc_wierszy);

                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);
                        tabBD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabBD, ilosc_wierszy, ilosc_kolumn);


                        odczyt_double(addMatrix(tabAD, tabBD, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy,
                                      ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabBD, ilosc_wierszy);

                    }

                } while (x != 1 && x != 2);
          //   }
        }

        else if( (!strcmp(argv[1], "subtractMatrix") || choice == "subtractMatrix"))
        {
            /*if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                int wybor_dolny = -1 + rand() % (10 - 2);

                int wybor_gorny = -1 + rand() % (10 - 2);


                odczyt(subtractMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),
                                 matrixGenerate(matrixSize, wybor_dolny, wybor_gorny), matrixSize.first,  matrixSize.second),
                       matrixSize.first,  matrixSize.second);
            } else {*/
                do {
                    cout << "ODEJMOWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
                        tabB = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabB, ilosc_wierszy, ilosc_kolumn);


                        odczyt(subtractMatrix(tabA, tabB, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabB, ilosc_wierszy);
                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);
                        tabBD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabBD, ilosc_wierszy, ilosc_kolumn);


                        odczyt_double(subtractMatrix(tabAD, tabBD, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy,
                                      ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabBD, ilosc_wierszy);


                    }

                } while (x != 1 && x != 2);
         //   }
        }
        else if ((!strcmp(argv[1], "multiplyMatrix") || choice == "multiplyMatrix"))
        {

            if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);
                ilosc_kolumn_macierzB = 1 + rand() % (10 - 2);
                int wybor_dolny = -1 + rand() % (10 - 2);

                int wybor_gorny = -1 + rand() % (10 - 2);




                odczyt(multiplyMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),matrixGenerate(matrixSize, wybor_dolny, wybor_gorny), matrixSize.first,  matrixSize.second, ilosc_kolumn_macierzB),matrixSize.first,  ilosc_kolumn_macierzB);

            } else {

                do {
                    cout << "MNOZENIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "Podaj ilosc wierszy do macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy B" << endl;
                        ilosc_kolumn_macierzB = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
                        tabB = dynamiczna_alokacja(ilosc_kolumn, ilosc_kolumn_macierzB);


                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabB, ilosc_kolumn, ilosc_kolumn_macierzB);


                        odczyt(multiplyMatrix(tabA, tabB, ilosc_wierszy, ilosc_kolumn, ilosc_kolumn_macierzB),
                               ilosc_wierszy, ilosc_kolumn_macierzB);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabB, ilosc_kolumn);

                    } else if (x == 2) {
                        cout << "Podaj ilosc wierszy do macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy B" << endl;
                        ilosc_kolumn_macierzB = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);
                        tabBD = dynamiczna_alokacja_double(ilosc_kolumn, ilosc_kolumn_macierzB);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabBD, ilosc_kolumn, ilosc_kolumn_macierzB);


                        odczyt_double(multiplyMatrix(tabAD, tabBD, ilosc_wierszy, ilosc_kolumn, ilosc_kolumn_macierzB),
                                      ilosc_wierszy, ilosc_kolumn_macierzB);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabBD, ilosc_kolumn);


                    }

                } while (x != 1 && x != 2);
           }
        }
        else if ((!strcmp(argv[1], "multiplyByScalar") || choice == "multiplyByScalar"))
        {
            if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                int wybor_dolny = -1 + rand() % (10 - 2);

                int wybor_gorny = -1 + rand() % (10 - 2);
                int x = 1 + rand() % (6 - 2);

                odczyt(multiplyByScalar(matrixGenerate(matrixSize,wybor_dolny,wybor_gorny),
                                         matrixSize.first,
                                         matrixSize.second,
                                         x),
                       matrixSize.first,
                       matrixSize.second);
            } else {

                int c;
                do {
                    cout << "MNOZENIE MACIERZY PRZEZ SKALAR\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj ilosc wierszy w macierzy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolum w macierzy" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);

                        cout << "podaj wartosc do skalaru" << endl;
                        c = wczytaj_liczbe();

                        odczyt(multiplyByScalar(tabA, ilosc_wierszy, ilosc_kolumn, c), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);

                    } else if (x == 2) {
                        cout << "podaj ilosc wierszy w macierzy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolum w macierzy" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        cout << "podaj wartosc do skalaru" << endl;
                        c = wczytaj_liczbe_double();

                        odczyt_double(multiplyByScalar(tabAD, ilosc_wierszy, ilosc_kolumn, c),ilosc_wierszy,ilosc_kolumn) ;

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);

                    }

                } while (x != 1 && x != 2);
            }
        }
        else if ((!strcmp(argv[1], "transpozeMatrix") || choice == "transpozeMatrix"))
        {
            if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                int wybor_dolny =  1 + rand() % (10 - 2);

                int wybor_gorny =  1 + rand() % (10 - 2);

                odczyt(transpozeMatrix(matrixGenerate(matrixSize,wybor_dolny,wybor_gorny), matrixSize.first, matrixSize.second), matrixSize.first, matrixSize.second);

            } else {
                do {
                    cout << "TRANSPONOWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);


                        odczyt(transpozeMatrix(tabA, ilosc_wierszy, ilosc_kolumn), ilosc_kolumn, ilosc_wierszy);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);


                    } else if (x == 2) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);


                        odczyt_double(transpozeMatrix(tabAD, ilosc_wierszy, ilosc_kolumn), ilosc_kolumn, ilosc_wierszy);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);


                    }

                } while (x != 1 && x != 2);
            }
        }
        else if ((!strcmp(argv[1], "powerMatrix") || choice == "powerMatrix"))
        {
            unsigned n;
            if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                int wybor_dolny = -1 + rand() % (10 - 2);

                int wybor_gorny = -1 + rand() % (10 - 2);
                int x = 1 + rand() % (10 - 2);

                odczyt(powerMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),
                                        x, matrixSize.first,  matrixSize.second),
                       matrixSize.first,  matrixSize.second);
            } else {
                do {
                    cout << "POTEGOWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "podaj potege" << endl;
                        cin >> n;

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);


                        odczyt(powerMatrix(tabA, ilosc_wierszy, ilosc_kolumn,n), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);

                    } else if (x == 2) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "podaj potege" << endl;
                        cin >> n;

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        odczyt_double(powerMatrix(tabAD, ilosc_wierszy, ilosc_kolumn,n), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    }

                } while (x != 1 && x != 2);
            }
        }
        else if ((!strcmp(argv[1], "determinantMatrix") || choice == "determinantMatrix"))
        {
            int   i;               // stopień macierzy
            int * WK;                    // wektor kolumn
            int ** A;                   // macierz

            if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {

                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                double wybor_dolny = -100 + (double) rand() / RAND_MAX * (200);

                double wybor_gorny = -100 + (double) rand() / RAND_MAX * (200);
                int x = 1 + rand() % (10 - 2);
                WK = new int[matrixSize.second];              // tworzymy wiersz kolumn

                for (i = 0; i < matrixSize.second; i++)         // wypełniamy go numerami kolumn
                    WK[i] = i;
                cout << determinantMatrix(matrixSize.first,0,WK, matrixGenerate(matrixSize,wybor_dolny,wybor_gorny))<<endl;

            } else {

                do {
                    cout << "WYZNACZNIK MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        A = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);          // tworzymy macierz wskaźników

                        wpisz_tabA(A, ilosc_wierszy, ilosc_kolumn);

                        WK = new int[ilosc_kolumn];              // tworzymy wiersz kolumn

                        for (i = 0; i < ilosc_kolumn; i++)         // wypełniamy go numerami kolumn
                            WK[i] = i;

                        cout << endl;

                        cout << determinantMatrix(ilosc_kolumn, 0, WK, A) << endl; // obliczamy i wyświetlamy wyznacznik

                        delete[] WK;                   // usuwamy tablice dynamiczne

                        zwalnianie_pamieci_macierz(A, ilosc_kolumn);
                    } else if (x == 2) {

                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy,
                                                           ilosc_kolumn);          // tworzymy macierz wskaźników

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        WK = new int[ilosc_kolumn];              // tworzymy wiersz kolumn

                        for (i = 0; i < ilosc_kolumn; i++)         // wypełniamy go numerami kolumn
                            WK[i] = i;

                        cout << endl;

                        cout << determinantMatrix(ilosc_kolumn, 0, WK, tabAD)
                             << endl; // obliczamy i wyświetlamy wyznacznik

                        delete[] WK;                   // usuwamy tablice dynamiczne

                        zwalnianie_pamieci_macierz(tabAD, ilosc_kolumn);
                    }

                } while (x != 1 && x != 2);
            }

        }
        else if ((!strcmp(argv[1], "matrixIsDiagonal") || choice == "matrixIsDiagonal" ))
        {

            bool ok;
            if ((argc == 3) && _stricmp( argv[2], "generate" ) == 0) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                double wybor_dolny = -100 + (double) rand() / RAND_MAX * (200);

                double wybor_gorny = -100 + (double) rand() / RAND_MAX * (200);
                int x = 1 + rand() % (10 - 2);
                cout<< matrixIsDiagonal(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),matrixSize.first,matrixSize.second)<<endl;

            } else {

                do {
                    cout << "CZY MACIERZ JEST DIAGONALNA\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);


                        ok = matrixIsDiagonal(tabA, ilosc_wierszy, ilosc_kolumn);
                        if (ok == 1) {
                            cout << "Macierz jest diagonalna" << endl;
                        } else {
                            cout << "Macierz nie jest diagonalna" << endl;
                        }

                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        // tutaj jeszcze kurwa musze dodacdouble
                        ok = matrixIsDiagonal(tabA, ilosc_wierszy, ilosc_kolumn);
                        if (ok == 1) {
                            cout << "Macierz jest diagonalna" << endl;
                        } else {
                            cout << "Macierz nie jest diagonalna" << endl;
                        }

                    }

                } while (x != 1 && x != 2);
            }
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
                cout << "SORTOWANIE TABLICY\n"
                        "---------------------\n";
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

                    sortRow(tab,ilosc_kolumn);
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

                    sortRow(tabD,ilosc_kolumn);
                    for(int i=0;i<ilosc_kolumn;i++)
                        cout<<tabD[i]<<" ";
                    cout << endl;
                    delete [ ] tabD;
                }
            }while (x!=1 && x!=2);
        }
        else if ((!strcmp(argv[1], "sortRowsInMatrix") || choice == "sortRowsInMatrix"))
        {
            if ((!strcmp(argv[1], "sortRowsInMatrix") && (argc == 3) && _stricmp( argv[2], "generate" ) == 0)) {
                matrixSize.first = 1 + rand() % (10 - 2);

                matrixSize.second = 1 + rand() % (10 - 2);

                int wybor_dolny = -1 + rand() % (10 - 2);

                int wybor_gorny = -1 + rand() % (10 - 2);

                odczyt(sortRowsInMatrix(matrixGenerate(matrixSize, wybor_dolny, wybor_gorny),
                                         matrixSize.first,  matrixSize.second),
                       matrixSize.first,  matrixSize.second);
            } else {
                do {
                    cout << "SORTOWANIE WIERSZY MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);

                        odczyt(sortRowsInMatrix(tabA,ilosc_wierszy,ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);
                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        odczyt_double(sortRowsInMatrix(tabAD, ilosc_wierszy, ilosc_kolumn),ilosc_wierszy,ilosc_kolumn);

                        odczyt_double(tabAD, ilosc_wierszy, ilosc_kolumn);
                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    }

                } while (x != 1 && x != 2);
            }
        }
        else if ((!strcmp(argv[1], "matrixGenerate") || choice == "matrixGenerate"))
        {

            do {
                cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                x=wczytaj_liczbe();
                if(x==1)
                {
                    cout << "Podaj ilosc wierzy";
                    matrixSize.first = wczytaj_liczbe();
                    cout << "Podaj ilosc kolumn";
                    matrixSize.second = wczytaj_liczbe();
                    cout<< "Podaj dolny zakres losowania liczb" << endl;
                    int wybor_dolny = wczytaj_liczbe();
                    cout<< "Podaj gorny zakres losowania liczb" << endl;
                    int wybor_gorny = wczytaj_liczbe();
                    odczyt(matrixGenerate(matrixSize,wybor_dolny,wybor_gorny),matrixSize.first, matrixSize.second);
                }
                else if(x==2)
                {
                    cout << "Podaj ilosc wierzy";
                    matrixSize.first = wczytaj_liczbe();
                    cout << "Podaj ilosc kolumn";
                    matrixSize.second = wczytaj_liczbe();
                    cout<< "Podaj dolny zakres losowania liczb" << endl;
                    double wybor_dolny = wczytaj_liczbe_double();
                    cout<< "Podaj gorny zakres losowania liczb" << endl;
                    double wybor_gorny = wczytaj_liczbe_double();
                    odczyt_double(matrixGenerate(matrixSize,wybor_dolny,wybor_gorny),matrixSize.first, matrixSize.second);
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

        do {
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
                    "matrixGenerate - wypelnienie macierzy losowymi liczbami\n"
                    "help - pomoc, dokumentacja\n"
                    "exit - wyjscie z programu\n";
            cout << "\nPodaj nazwe dzialania\n" << endl;
            cin >> choice;
            if(choice == "addMatrix")
            {
                do {
                    cout << "DODAWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
                        tabB = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabB, ilosc_wierszy, ilosc_kolumn);


                        odczyt(addMatrix(tabA, tabB, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabB, ilosc_wierszy);

                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);
                        tabBD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabBD, ilosc_wierszy, ilosc_kolumn);


                        odczyt_double(addMatrix(tabAD, tabBD, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy,
                                      ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabBD, ilosc_wierszy);

                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "subtractMatrix")
            {
                do {
                        cout << "ODEJMOWANIE MACIERZY\n"
                                "---------------------\n";
                        cout << "1-Macierze int\n"
                        "2-Macierze double\n";
                        x = wczytaj_liczbe();
                        if (x == 1) {
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();

                            tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
                            tabB = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                            wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);
                            wpisz_tabB(tabB, ilosc_wierszy, ilosc_kolumn);


                            odczyt(subtractMatrix(tabA, tabB, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);

                            zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                            zwalnianie_pamieci_macierz(tabB, ilosc_wierszy);
                        } else if (x == 2) {
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();

                            tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);
                            tabBD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                            wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);
                            wpisz_tabB(tabBD, ilosc_wierszy, ilosc_kolumn);


                            odczyt_double(subtractMatrix(tabAD, tabBD, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy,
                                          ilosc_kolumn);

                            zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                            zwalnianie_pamieci_macierz(tabBD, ilosc_wierszy);


                        }

                } while (x != 1 && x != 2);
            }
            if(choice == "multiplyMatrix")
            {
                do {
                    cout << "MNOZENIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "Podaj ilosc wierszy do macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy B" << endl;
                        ilosc_kolumn_macierzB = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
                        tabB = dynamiczna_alokacja(ilosc_kolumn, ilosc_kolumn_macierzB);


                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabB, ilosc_kolumn, ilosc_kolumn_macierzB);


                        odczyt(multiplyMatrix(tabA, tabB, ilosc_wierszy, ilosc_kolumn, ilosc_kolumn_macierzB),
                               ilosc_wierszy, ilosc_kolumn_macierzB);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabB, ilosc_kolumn);

                    } else if (x == 2) {
                        cout << "Podaj ilosc wierszy do macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn do macierzy B" << endl;
                        ilosc_kolumn_macierzB = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);
                        tabBD = dynamiczna_alokacja_double(ilosc_kolumn, ilosc_kolumn_macierzB);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);
                        wpisz_tabB(tabBD, ilosc_kolumn, ilosc_kolumn_macierzB);


                        odczyt_double(multiplyMatrix(tabAD, tabBD, ilosc_wierszy, ilosc_kolumn, ilosc_kolumn_macierzB),
                                      ilosc_wierszy, ilosc_kolumn_macierzB);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                        zwalnianie_pamieci_macierz(tabBD, ilosc_kolumn);


                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "multiplyByScalar")
            {
                int c;
                do {
                    cout << "MNOZENIE MACIERZY PRZEZ SKALAR\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj ilosc wierszy w macierzy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolum w macierzy" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);

                        cout << "podaj wartosc do skalaru" << endl;
                        c = wczytaj_liczbe();

                        multiplyByScalar(tabA, ilosc_wierszy, ilosc_kolumn, c);

                        odczyt(tabA, ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);

                    } else if (x == 2) {
                        cout << "podaj ilosc wierszy w macierzy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolum w macierzy" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        cout << "podaj wartosc do skalaru" << endl;
                        c = wczytaj_liczbe_double();

                        odczyt_double(multiplyByScalar(tabAD, ilosc_wierszy, ilosc_kolumn, c),ilosc_wierszy,ilosc_kolumn) ;

                        // odczyt_double(tabAD, ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);

                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "transpozeMatrix")
            {
                do {
                    cout << "TRANSPONOWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);


                        odczyt(transpozeMatrix(tabA, ilosc_wierszy, ilosc_kolumn), ilosc_kolumn, ilosc_wierszy);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);


                    } else if (x == 2) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);


                        odczyt_double(transpozeMatrix(tabAD, ilosc_wierszy, ilosc_kolumn), ilosc_kolumn, ilosc_wierszy);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);


                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "powerMatrix")
            {
                unsigned n;
                do {
                    cout << "POTEGOWANIE MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "podaj potege" << endl;
                        cin >> n;

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);


                        odczyt(powerMatrix(tabA, n, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);

                    } else if (x == 2) {
                        cout << "podaj ilosc wierszy macierzy A" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj ilosc kolumn macierzy A" << endl;
                        ilosc_kolumn = wczytaj_liczbe();
                        cout << "podaj potege" << endl;
                        cin >> n;

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);


                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);


                        odczyt_double(powerMatrix(tabAD, n, ilosc_wierszy, ilosc_kolumn), ilosc_wierszy, ilosc_kolumn);

                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);

                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "determinantMatrix")
            {
                int   i;               // stopień macierzy
                int * WK;                    // wektor kolumn
                int ** A;                   // macierz
                do {
                    cout << "WYZNACZNIK MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        A = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);          // tworzymy macierz wskaźników

                        wpisz_tabA(A, ilosc_wierszy, ilosc_kolumn);

                        WK = new int[ilosc_kolumn];              // tworzymy wiersz kolumn

                        for (i = 0; i < ilosc_kolumn; i++)         // wypełniamy go numerami kolumn
                            WK[i] = i;

                        cout << endl;

                        cout << determinantMatrix(ilosc_kolumn, 0, WK, A) << endl; // obliczamy i wyświetlamy wyznacznik

                        delete[] WK;                   // usuwamy tablice dynamiczne

                        zwalnianie_pamieci_macierz(A, ilosc_kolumn);
                    } else if (x == 2) {

                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy,
                                                           ilosc_kolumn);          // tworzymy macierz wskaźników

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        WK = new int[ilosc_kolumn];              // tworzymy wiersz kolumn

                        for (i = 0; i < ilosc_kolumn; i++)         // wypełniamy go numerami kolumn
                            WK[i] = i;

                        cout << endl;

                        cout << determinantMatrix(ilosc_kolumn, 0, WK, tabAD)
                             << endl; // obliczamy i wyświetlamy wyznacznik

                        delete[] WK;                   // usuwamy tablice dynamiczne

                        zwalnianie_pamieci_macierz(tabAD, ilosc_kolumn);
                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "matrixIsDiagonal")
            {
                bool ok;
                do {
                    cout << "CZY MACIERZ JEST DIAGONALNA\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);


                        ok = matrixIsDiagonal(tabA, ilosc_wierszy, ilosc_kolumn);
                        if (ok == 1) {
                            cout << "Macierz jest diagonalna" << endl;
                        } else {
                            cout << "Macierz nie jest diagonalna" << endl;
                        }

                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        if (ilosc_wierszy != ilosc_kolumn) {
                            cout << "macierz nie jest kwadratowa\n";
                            cout << "podaj liczbe wierszy" << endl;
                            ilosc_wierszy = wczytaj_liczbe();
                            cout << "podaj liczbe kolumn" << endl;
                            ilosc_kolumn = wczytaj_liczbe();
                            while (ilosc_wierszy != ilosc_kolumn) {
                                cout << "macierz nie jest kwadratowa\n";
                                cout << "podaj liczbe wierszy" << endl;
                                ilosc_wierszy = wczytaj_liczbe();
                                cout << "podaj liczbe kolumn" << endl;
                                ilosc_kolumn = wczytaj_liczbe();
                            }
                        }

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        // tutaj jeszcze kurwa musze dodacdouble
                        ok = matrixIsDiagonal(tabA, ilosc_wierszy, ilosc_kolumn);
                        if (ok == 1) {
                            cout << "Macierz jest diagonalna" << endl;
                        } else {
                            cout << "Macierz nie jest diagonalna" << endl;
                        }

                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "swap")
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
            if(choice == "sortRow")
            {
                int *tab;
                double *tabD;
                do {
                    cout << "SORTOWANIE TABLICY\n"
                            "---------------------\n";
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

                        sortRow(tab,ilosc_kolumn);
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

                        sortRow(tabD,ilosc_kolumn);
                        for(int i=0;i<ilosc_kolumn;i++)
                            cout<<tabD[i]<<" ";
                        cout << endl;
                        delete [ ] tabD;
                    }
                }while (x!=1 && x!=2);
            }
            if(choice == "sortRowInMatrix")
            {
                do {
                    cout << "SORTOWANIE WIERSZY MACIERZY\n"
                            "---------------------\n";
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x = wczytaj_liczbe();
                    if (x == 1) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabA = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabA, ilosc_wierszy, ilosc_kolumn);

                        sortRowsInMatrix(tabA, ilosc_wierszy, ilosc_kolumn);

                        odczyt(tabA, ilosc_wierszy, ilosc_kolumn);
                        zwalnianie_pamieci_macierz(tabA, ilosc_wierszy);
                    } else if (x == 2) {
                        cout << "podaj liczbe wierszy" << endl;
                        ilosc_wierszy = wczytaj_liczbe();
                        cout << "podaj liczbe kolumn" << endl;
                        ilosc_kolumn = wczytaj_liczbe();

                        tabAD = dynamiczna_alokacja_double(ilosc_wierszy, ilosc_kolumn);

                        wpisz_tabA(tabAD, ilosc_wierszy, ilosc_kolumn);

                        odczyt_double(sortRowsInMatrix(tabAD, ilosc_wierszy, ilosc_kolumn),ilosc_wierszy,ilosc_kolumn);

                        odczyt_double(tabAD, ilosc_wierszy, ilosc_kolumn);
                        zwalnianie_pamieci_macierz(tabAD, ilosc_wierszy);
                    }

                } while (x != 1 && x != 2);
            }
            if(choice == "matrixGenerate")
            {
                do {
                    cout << "1-Macierze int\n"
                            "2-Macierze double\n";
                    x=wczytaj_liczbe();
                    if(x==1)
                    {
                        cout << "Podaj ilosc wierzy";
                        matrixSize.first = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn";
                        matrixSize.second = wczytaj_liczbe();
                        cout<< "Podaj dolny zakres losowania liczb" << endl;
                        int wybor_dolny = wczytaj_liczbe();
                        cout<< "Podaj gorny zakres losowania liczb" << endl;
                        int wybor_gorny = wczytaj_liczbe();
                        odczyt(matrixGenerate(matrixSize,wybor_dolny,wybor_gorny),matrixSize.first, matrixSize.second);
                    }
                    else if(x==2)
                    {
                        cout << "Podaj ilosc wierzy";
                        matrixSize.first = wczytaj_liczbe();
                        cout << "Podaj ilosc kolumn";
                        matrixSize.second = wczytaj_liczbe();
                        cout<< "Podaj dolny zakres losowania liczb" << endl;
                        double wybor_dolny = wczytaj_liczbe_double();
                        cout<< "Podaj gorny zakres losowania liczb" << endl;
                        double wybor_gorny = wczytaj_liczbe_double();
                        odczyt_double(matrixGenerate(matrixSize,wybor_dolny,wybor_gorny),matrixSize.first, matrixSize.second);
                    }
                }while (x!=1 && x!=2);
            }
            if(choice == "help")
            {
                help();
            }
        }while(choice != "exit");

    } while ( _stricmp( argv[1], "exit" ) == 1  || choice != "exit");

  return 0;
}

