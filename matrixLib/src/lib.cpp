#include <iostream>
#include "../include/lib.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int **addMatrix(int **tabA,int **tabB,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw,ik;
    int **W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
            W [ iw ][ ik ] = tabA [ iw ][ ik ] + tabB [ iw ][ ik ];

    return  W;
}
double **addMatrix(double **tabA,double **tabB,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw,ik;
    double **W = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
            W [ iw ][ ik ] = tabA [ iw ][ ik ] + tabB [ iw ][ ik ];

    return  W;
}
int** dynamiczna_alokacja(int ilosc_wierszy,int ilosc_kolumn)
{
    int** macierz;
    int iw,ik;
    macierz = new int * [ ilosc_wierszy ];

    for( iw = 0; iw < ilosc_wierszy; iw++ )
    {
        macierz [ iw ] = new int [ ilosc_kolumn ];
    }
    return macierz;
}
double** dynamiczna_alokacja_double(int ilosc_wierszy,int ilosc_kolumn)
{
    double** macierz;
    int iw,ik;
    macierz = new double * [ ilosc_wierszy ];

    for( iw = 0; iw < ilosc_wierszy; iw++ )
    {
        macierz [ iw ] = new double [ ilosc_kolumn ];
    }
    return macierz;
}
void odczyt (int **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw,ik;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
    {
        for( ik = 0; ik < ilosc_kolumn; ik++ )
            cout  << tabA [ iw ][ ik ] << "\t";
        cout << endl;
    }
}
void odczyt_double (double **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw,ik;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
    {
        for( ik = 0; ik < ilosc_kolumn; ik++ )
            cout << tabA [ iw ][ ik ] << "\t";
        cout << endl;
    }
}
void zwalnianie_pamieci_macierz(int** tabA, int ilosc_wierszy)
{
    int iw;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
    {
        delete [ ] tabA [ iw ];
    }
    delete [ ] tabA;
}
void zwalnianie_pamieci_macierz(double** tabA, int ilosc_wierszy)
{
    int iw;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
    {
        delete [ ] tabA [ iw ];
    }
    delete [ ] tabA;
}

int wpisz_tabA (int** tabA,int ilosc_wierszy , int ilosc_kolumn)
{
    int iw,ik;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
        {
            cout << "dodaj wartosc do macierzy A"<< endl;
            tabA [ iw ][ ik ]=wczytaj_liczbe();

        }
    return **tabA;
}
double wpisz_tabA (double** tabA,int ilosc_wierszy , int ilosc_kolumn)
{
    int iw,ik;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
        {
            cout << "dodaj wartosc do macierzy A"<< endl;
            tabA [ iw ][ ik ]=wczytaj_liczbe_double();

        }
    return **tabA;
}

int wpisz_tabB (int** tabB,int ilosc_wierszy , int ilosc_kolumn)
{
    int iw,ik;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
        {
            cout << "dodaj wartosc do macierzy B"<< endl;
            tabB [ iw ][ ik ]=wczytaj_liczbe();

        }
    return **tabB;
}
double wpisz_tabB (double** tabB,int ilosc_wierszy , int ilosc_kolumn)
{
    int iw,ik;
    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
        {
            cout << "dodaj wartosc do macierzy B"<< endl;
            tabB [ iw ][ ik ]=wczytaj_liczbe_double();

        }
    return **tabB;
}

int swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    return  (a),(b);
}
double swap(double &a,double &b){
    double temp;
    temp=a;
    a=b;
    b=temp;
    return (a),(b);
}

int **subtractMatrix (int **tabA,int **tabB,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw,ik;
    int **W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
            W [ iw ][ ik ] = tabA [ iw ][ ik ] - tabB [ iw ][ ik ];

    return  W;
}

double **subtractMatrix (double **tabA,double **tabB,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw,ik;
    double **W = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ )
            W [ iw ][ ik ] = tabA [ iw ][ ik ] - tabB [ iw ][ ik ];

    return  W;
}

int **multiplyMatrix(int **tabA,int **tabB,int ilosc_wierszy,int ilosc_kolumn,int ilosc_kolumn_macierzB)
{
    int i, j, k, s;
    int **W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn_macierzB);

    for( i = 0; i < ilosc_wierszy; i++ )
        for( j = 0; j < ilosc_kolumn_macierzB; j++ )
        {
            s = 0;
            for( k = 0; k <  ilosc_kolumn; k++ ) s += tabA [ i ][ k ] * tabB [ k ][ j ];
            W [ i ][ j ] = s;
        }

    return W;

}

double **multiplyMatrix(double **tabA,double **tabB,int ilosc_wierszy,int ilosc_kolumn,int ilosc_kolumn_macierzB)
{
    int i, j, k;
    double s;
    double **W = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn_macierzB);

    for( i = 0; i < ilosc_wierszy; i++ )
        for( j = 0; j < ilosc_kolumn_macierzB; j++ )
        {
            s = 0;
            for( k = 0; k < ilosc_kolumn; k++ ) s += tabA [ i ][ k ] * tabB [ k ][ j ];
            W [ i ][ j ] = s;
        }

    return W;

}

int **powerMatrix(int **tabA,int ilosc_wierszy,int ilosc_kolumn,unsigned n)
{
    int **W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

    for( int i = 0 ; i < ilosc_wierszy ; ++ i )
        for( int j = 0 ; j < ilosc_kolumn ; ++ j )
            W[i][j] = ( i == j ) ;

    int **temp = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

    for(int w=0;w<n;w++)
    {
        for(int i=0;i<ilosc_wierszy;i++)
        {
            for(int j=0;j<ilosc_kolumn;j++)
            {
                temp[i][j]=0;
                for(int k=0;k<ilosc_kolumn;k++)
                {
                    temp[i][j]+=W[i][k]*tabA[k][j];
                }
            }
        }

        for(int i=0;i<ilosc_wierszy;i++){
            for(int j=0;j<ilosc_kolumn;j++)
            {
                W[i][j]=temp[i][j];
            }
        }
    }

    return W ;
}

double **powerMatrix(double **tabA,int ilosc_wierszy,int ilosc_kolumn,unsigned n)
{
    double **W = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
    for( int i = 0 ; i < ilosc_wierszy ; ++ i )
        for( int j = 0 ; j < ilosc_kolumn ; ++ j )
            W[i][j] = ( i == j ) ;

    double **temp = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);

    for(int w=0;w<n;w++)
    {
        for(int i=0;i<ilosc_wierszy;i++)
        {
            for(int j=0;j<ilosc_kolumn;j++)
            {
                temp[i][j]=0;
                for(int k=0;k<ilosc_kolumn;k++)
                {
                    temp[i][j]+=W[i][k]*tabA[k][j];
                }
            }
        }

        for(int i=0;i<ilosc_wierszy;i++){
            for(int j=0;j<ilosc_kolumn;j++)
            {
                W[i][j]=temp[i][j];
            }
        }
    }

    return W ;
}

int **multiplyByScalar(int **tabA,int ilosc_wierszy,int ilosc_kolumn,int c)
{
    int  iw, ik;
    int **W = dynamiczna_alokacja( ilosc_wierszy, ilosc_kolumn);

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ ) W [ iw ][ ik ] = tabA [iw][ik] * c;

    return W;
}
double **multiplyByScalar(double **tabA,int ilosc_wierszy,int ilosc_kolumn,double c)
{
    int  iw, ik;
    double **W = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ ) W [ iw ][ ik ] = tabA [iw][ik] *  c;

    return W;
}
int **transpozeMatrix(int **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw, ik;
    int **W = dynamiczna_alokacja( ilosc_kolumn, ilosc_wierszy);

    // transponujemy macierz A w B

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ ) W [ ik ][ iw ] = tabA [ iw ][ ik ];


    return W;
}

double **transpozeMatrix(double **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
    int iw, ik;
    double **W = dynamiczna_alokacja_double( ilosc_kolumn, ilosc_wierszy);

    // transponujemy macierz A w B

    for( iw = 0; iw < ilosc_wierszy; iw++ )
        for( ik = 0; ik < ilosc_kolumn; ik++ ) W [ ik ][ iw ] = tabA [ iw ][ ik ];


    return W;
}

int determinantMatrix ( int ilosc_kolumn, int w, int * WK, int ** tabA ) {
    int i, j, k, m, *KK;
    int s;

    if (ilosc_kolumn == 1)                     // sprawdzamy warunek zakończenia rekurencji

        return tabA[w][WK[0]];    // macierz 1 x 1, wyznacznik równy elementowi

    else {

        KK = new int[ilosc_kolumn - 1];        // tworzymy dynamiczny wektor kolumn

        s = 0;                         // zerujemy wartość rozwinięcia
        m = 1;                         // początkowy mnożnik

        for (i = 0; i < ilosc_kolumn; i++)       // pętla obliczająca rozwinięcie
       {

            k = 0;                       // tworzymy wektor kolumn dla rekurencji

            for (j = 0; j < ilosc_kolumn - 1; j++) // ma on o 1 kolumnę mniej niż WK
            {
                if (k == i) k++;          // pomijamy bieżącą kolumnę
                KK[j] = WK[k++];     // pozostałe kolumny przenosimy do KK
            }

            s += m * tabA[w][WK[i]] * determinantMatrix(ilosc_kolumn - 1, w + 1, KK, tabA);

            m = -m;                      // kolejny mnożnik

        }

        delete[] KK;                 // usuwamy zbędną już tablicę dynamiczną

        return s;                      // ustalamy wartość funkcji

    }

}

double determinantMatrix ( int ilosc_kolumn, int w,int * WK, double ** tabA ) {
    int i, j, k, m;
    double s;
    int *KK;

    if (ilosc_kolumn == 1)                     // sprawdzamy warunek zakończenia rekurencji

        return tabA[w][WK[0]];    // macierz 1 x 1, wyznacznik równy elementowi

    else {

        KK = new int [ilosc_kolumn - 1];        // tworzymy dynamiczny wektor kolumn

        s = 0;                         // zerujemy wartość rozwinięcia
        m = 1;                         // początkowy mnożnik

        for (i = 0; i < ilosc_kolumn; i++)       // pętla obliczająca rozwinięcie
        {

            k = 0;                       // tworzymy wektor kolumn dla rekurencji

            for (j = 0; j < ilosc_kolumn - 1; j++) // ma on o 1 kolumnę mniej niż WK
            {
                if (k == i) k++;          // pomijamy bieżącą kolumnę
                KK[j] = WK[k++];     // pozostałe kolumny przenosimy do KK
            }

            s += m * tabA[w][WK[i]] * determinantMatrix(ilosc_kolumn - 1, w + 1, KK, tabA);

            m = -m;                      // kolejny mnożnik

        }

        delete[] KK;                 // usuwamy zbędną już tablicę dynamiczną

        return s;                      // ustalamy wartość funkcji

    }

}


bool matrixIsDiagonal(int **tabA,int ilosc_wierszy,int ilosc_kolumn)
{

    int i,j;
    bool ok=true;

    for (i = 0; i < ilosc_wierszy; i++)
        for (j = 0; j < ilosc_kolumn; j++)
            if (i == j)
            {
                if (tabA[i][j] == 0)
                    ok=false;
            }
            else
            {
                if (tabA[i][j] != 0)
                    ok=false;
            }

    return ok;
}

bool matrixIsDiagonal(double **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
    int i,j;
    bool ok=true;

    for (i = 0; i < ilosc_wierszy; i++)
        for (j = 0; j < ilosc_kolumn; j++)
            if (i == j)
            {
                if (tabA[i][j] == 0)
                    ok=false;
            }
            else
            {
                if (tabA[i][j] != 0)
                    ok=false;
            }

    return ok;
}
int *sortRow(int *t , int ilosc_kolumn)
{
    for (int pocz=0; pocz < ilosc_kolumn-1; pocz++)
        for (int i=0; i < ilosc_kolumn-pocz-1; i++)
            if (t[i] > t[i+1])
                swap(t[i],t[i+1]);
    return t;
}
double *sortRow(double *t ,int ilosc_kolumn)
{
    for (int pocz=0; pocz < ilosc_kolumn-1; pocz++)
        for (int i=0; i < ilosc_kolumn-pocz-1; i++)
            if (t[i] > t[i+1])
                swap(t[i],t[i+1]);
    return t;
}
int **sortRowsInMatrix (int **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
   int tmp;
   int **W = dynamiczna_alokacja(ilosc_wierszy, ilosc_kolumn);
   for(int x=0; x<ilosc_wierszy;x++){
       for (int z = 0; z < ilosc_kolumn; ++z) {
           W[x][z]=tabA[x][z];
       }
   }
    for (int i=0; i<ilosc_wierszy; i++)
        for (int j=0; j<ilosc_kolumn-1; j++)
            for (int k=0; k<ilosc_kolumn-1-j; k++)
                if (W[i][k] > W[i][k+1])
                {
                    tmp=W[i][k+1];
                    W[i][k+1]=W[i][k];
                    W[i][k]=tmp;
                }

    return W;
}
double **sortRowsInMatrix (double **tabA,int ilosc_wierszy,int ilosc_kolumn)
{
    double tmp;
    double **W = dynamiczna_alokacja_double( ilosc_wierszy, ilosc_kolumn);
    for(int x=0; x<ilosc_wierszy;x++){
        for (int z = 0; z < ilosc_kolumn; ++z) {
            W[x][z]=tabA[x][z];
        }
    }
    for (int i=0; i<ilosc_wierszy; i++)
        for (int j=0; j<ilosc_kolumn-1; j++)
            for (int k=0; k<ilosc_kolumn-1-j; k++)
                if (W[i][k] > W[i][k+1])
                {
                    tmp=W[i][k+1];
                    W[i][k+1]=W[i][k];
                    W[i][k]=tmp;
                }
    return W;
}

int **matrixGenerate(pair <int ,int > matrixSize, int wybor_dolny, int wybor_gorny)
{
   int **W = dynamiczna_alokacja(matrixSize.first,matrixSize.second);

    srand(time(NULL));

   for(int iw = 0; iw < matrixSize.first; iw++ )
        for(int ik = 0; ik < matrixSize.second; ik++ )
            W [ iw ][ ik ] =wybor_dolny + rand()%(wybor_gorny+wybor_dolny+1);

    return W;
}
double **matrixGenerate(pair <int ,int > matrixSize, double wybor_dolny, double wybor_gorny)
{
    double **W = dynamiczna_alokacja_double(matrixSize.first,matrixSize.second);

    srand(time(NULL));

    for(int iw = 0; iw < matrixSize.first; iw++ )
        for(int ik = 0; ik < matrixSize.second; ik++ )
            W [ iw ][ ik ] = wybor_dolny + (double) rand() / RAND_MAX * (wybor_gorny-wybor_dolny);

    return W;

}

int wczytaj_liczbe (void)
{
    int p;
    int ok, podglad;
    do
    {
        ok=1;
        cin>>p;
        if (cin.fail()) //jesli wczytanie sie nie powiodlo
        {
            ok=0;
            cin.clear(); //czysci flage bledu strumienia
            cin.ignore(INT_MAX, '\n'); //usuwa wszystkie znaki z buforu strumienia
        }
        else
        {
            while( (podglad = cin.get()) != '\n' )
            {
                if(podglad != ' ')// Szukanie zbędnych danych w strumieniu
                {
                    ok=0;
                    cin.ignore(INT_MAX, '\n'); // czyszczenie strumienia
                    break;
                }
            }
        }
        if (ok==0) cout<<"Nie podano liczby. Sprobuj wpisac ponownie...\n";
    }
    while (ok==0);
    return p;
}
int wczytaj_liczbe_double (void)
{
    double p;
    double ok, podglad;
    do
    {
        ok=1;
        cin>>p;
        if (cin.fail()) //jesli wczytanie sie nie powiodlo
        {
            ok=0;
            cin.clear(); //czysci flage bledu strumienia
            cin.ignore(INT_MAX, '\n'); //usuwa wszystkie znaki z buforu strumienia
        }
        else
        {
            while( (podglad = cin.get()) != '\n' )
            {
                if(podglad != ' ')// Szukanie zbędnych danych w strumieniu
                {
                    ok=0;
                    cin.ignore(INT_MAX, '\n'); // czyszczenie strumienia
                    break;
                }
            }
        }
        if (ok==0) cout<<"Nie podano liczby. Sprobuj wpisac ponownie...\n";
    }
    while (ok==0);
    return p;
}
void help()
{
    cout << "Wczytywanie macierzy\n\n"
            "Po podaniu wymiarow macierzy, macierz zostaje dynamicznie zalokowana i przekazywana jest do funkcji wczytujacej "
            "wartosci do macierzy o podanym rozmiarze\n" << endl;
    cout << "addMatrix \n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param W macierz wynikowa typu int, suma z dodawania macierzy A i B\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @details wartosci z poszczegolnych kolumn i wierszy z macierzy A i B  dodawane sa do siebie i zapisywane do macierzy wynikowej W\n"
            " * @return macierz wynikowa typu int, podwojny wskaznik\n"
            " */\n";
    cout << "subtractMatrix\n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param W macierz wynikowa typu int, roznica z odejmowania macierzy A i B\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @details wartosci z poszczegolnych kolumn i wierszy z macierzy A i B  odejmowane sa do siebie i zapisywane do macierzy wynikowej W\n"
            " * @return macierz wynikowa typu int, podwojny wskaznik\n"
            " */\n\n";
    cout << "multiplyMatrix\n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param tabB macierz B typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param W macierz wynikowa typu double, iloczynu macierzy A i B\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @param ilosc_kolumn_macierzB zmienna przechowujaca ilosc kolumn w macierzy B\n"
            " * @details mnozy elementy wiersza macierzy A z kolumnami macierzy B mnozenie poszczegolnych wartosci dodajemy do siebie i zapisujemy w macierzy wynikowej\n"
            " * Wynikiem mnożenia dwóch macierzy jest nowa macierz, która posiada tyle wierszy, ile wierszy miała macierz A  oraz tyle kolumn, ile kolumn miała macierz B\n"
            " * @return macierz wynikowa typu double, podwojny wskaznik\n"
            " */\n\n";
    cout << "multiplyByScalar\n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @param c  zmienna przechowujaca skalar typu int\n"
            " * @details  W mnożeniu macierzy przez skalar, każdy element macierzy zostaje pomnożony przez daną liczbę, czyli skalar.\n"
            " * @return tabA macierz A typu int po mnozeniu przez skalar\n"
            " */\n\n";
    cout<< "transpozeMatrix\n\n"
           "/**\n"
           " *\n"
           " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
           " * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
           " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
           " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
           " * @details Macierz transponowana do macierzy A to macierz B, która powstaje przez zamianę wierszy macierzy A na kolumny i kolumn na wiersze.\n"
           " * @return tabB, transponowana macierz A typu int\n"
           " */\n\n";
    cout << "powerMatrix\n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param W macierz wynikowa typu int, przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param n zmienna przechowujaca potege o typie unsigned\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @details funkcja potegujaca macierz A przez wybrany stopien potegi\n"
            " * @return macierz wynikowa, podniesiona do potegi n\n"
            " */\n\n";
    cout << "determinantMatrix\n\n"
            "/**\n"
            " *\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @param w poczatek\n"
            " * @param WK zmienna przechowujaca wektor kolumn\n"
            " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @details funkcja obliczajca wyznacznik macierzy, zwracajaca wartosc typu int\n"
            " * @return zwraca wartosc wyznacznika typu int\n"
            " */\n\n";
    cout << "matrixIsDiagonal\n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @details funkcja sprawdzająca czy podana macierz A jest diagonalna,\n"
            " * czyli czy macierz ma wszystkie wspolczynniki lezace poza glowna przekatna sa zerowe oraz czy na glownej przekatnej znajduja sie liczby niezerowe\n"
            " * @return zwraca wartosc bool\n"
            " */\n\n";
    cout << "swap\n\n"
            "/**\n"
            " *\n"
            " * @param a zmienna typu double\n"
            " * @param b zmienna typu double\n"
            " * @details zamienia podany parametr a z drugim podanym parametrem b, w wyniku czego a jest rowne poczatkowej wartosci b, z koleji b jest rowne poczatkowej wartosci a\n"
            " * @return zwraca zamienione dwa parametry\n"
            " */\n\n";
    cout << "sortRow\n\n"
            "/**\n"
            " *\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @param t tablica jednowymiarowa typu double\n"
            " * @details funkcja sortujaca tablice jednowymiarowa sortowaniem babelkowym, sortowanie rosnace\n"
            " * @return zwraca tablice t posortowana\n"
            " */\n\n";
    cout << "sortRowsInMatrix\n\n"
            "/**\n"
            " *\n"
            " * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]\n"
            " * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy\n"
            " * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy\n"
            " * @details funkcja sortujaca wszystkie wiersze w macierzy sortowaniem babelkowym, sortowanie rosnace\n"
            " * @return zwraca posortowana macierz A tabA typu double\n"
            " */\n\n";
}
