using namespace std;
/**
 *
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details wartosci z poszczegolnych kolumn i wierszy z macierzy A i B  dodawane sa do siebie i zapisywane do macierzy wynikowej W
 * @return macierz wynikowa typu int, podwojny wskaznik
 */
int **addMatrix(int **tabA,int **tabB,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details wartosci z poszczegolnych kolumn i wierszy z macierzy A i B  dodawane sa do siebie i zapisywane do macierzy wynikowej W
 * @return macierz wynikowa typu double, podwojny wskaznik
 */
double **addMatrix(double **tabA,double **tabB,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details wartosci z poszczegolnych kolumn i wierszy z macierzy A i B  odejmowane sa do siebie i zapisywane do macierzy wynikowej W
 * @return macierz wynikowa typu int, podwojny wskaznik
 */
int **subtractMatrix (int **tabA,int **tabB,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details wartosci z poszczegolnych kolumn i wierszy z macierzy A i B  odejmowane sa od siebie i zapisywane do macierzy wynikowej W
 * @return macierz wynikowa typu double, podwojny wskaznik
 */
double **subtractMatrix (double **tabA,double **tabB,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param ilosc_kolumn_macierzB zmienna przechowujaca ilosc kolumn w macierzy B
 * @details  mnozy elementy wiersza macierzy A z kolumnami macierzy B mnozenie poszczegolnych wartosci dodajemy do siebie i zapisujemy w macierzy wynikowej
 * Wynikiem mnożenia dwóch macierzy jest nowa macierz, która posiada tyle wierszy, ile wierszy miała macierz A  oraz tyle kolumn, ile kolumn miała macierz B
 * @return macierz wynikowa typu int, podwojny wskaznik
 */
int **multiplyMatrix(int **tabA,int **tabB,int ilosc_wierszy,int ilosc_kolumn,int ilosc_kolumn_macierzB);
/**
 *
 * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz B typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param ilosc_kolumn_macierzB zmienna przechowujaca ilosc kolumn w macierzy B
 * @details mnozy elementy wiersza macierzy A z kolumnami macierzy B mnozenie poszczegolnych wartosci dodajemy do siebie i zapisujemy w macierzy wynikowej
 * Wynikiem mnożenia dwóch macierzy jest nowa macierz, która posiada tyle wierszy, ile wierszy miała macierz A  oraz tyle kolumn, ile kolumn miała macierz B
 * @return macierz wynikowa typu double, podwojny wskaznik
 */
double **multiplyMatrix(double **tabA,double **tabB,int ilosc_wierszy,int ilosc_kolumn,int ilosc_kolumn_macierzB);
/**
 * 
 * @param tabA macierz A typu int przekazywana do funkcji
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param c zmienna przechowujaca skalar typu int
 * @return W zwraca macierz pomnozona przez skalar
 */
int **multiplyByScalar(int **tabA,int ilosc_wierszy,int ilosc_kolumn,int c);
/**
 * 
 * @param tabA macierz A typu double przekazywana do funkcji
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param c zmienna przechowujaca skalar typu double
 * @return W zwraca macierz pomnozona przez skalar
 */
double **multiplyByScalar(double **tabA,int ilosc_wierszy,int ilosc_kolumn,double c);
/**
 *
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param tabB macierz B typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details Macierz transponowana do macierzy A to macierz B, która powstaje przez zamianę wierszy macierzy A na kolumny i kolumn na wiersze.
 * @return tabB, transponowana macierz A typu int
 */
int **transpozeMatrix(int **tabA,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param W  W macierz B typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details Macierz transponowana do macierzy A to macierz B, która powstaje przez zamianę wierszy macierzy A na kolumny i kolumn na wiersze.
 * @return tabB, transponowana macierz A typu double
 */
double **transpozeMatrix(double **tabA,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param W macierz wynikowa typu int, przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param n zmienna przechowujaca potege o typie unsigned
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details funkcja potegujaca macierz A przez wybrany stopien potegi
 * @return macierz wynikowa, podniesiona do potegi n
 */
int **powerMatrix(int **tabA,int ilosc_wierszy,int ilosc_kolumn,unsigned n);
/**
 *
 * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param W macierz wynikowa typu double, przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param n zmienna przechowujaca potege o typie unsigned
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details funkcja potegujaca macierz A przez wybrany stopien potegi
 * @return macierz wynikowa, podniesiona do potegi n
 */
double **powerMatrix(double **tabA,int ilosc_wierszy,int ilosc_kolumn,unsigned n);
/**
 *
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param w poczatek
 * @param WK zmienna przechowujaca wektor kolumn
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @details funkcja obliczajca wyznacznik macierzy, zwracajaca wartosc typu int
 * @return zwraca wartosc wyznacznika typu int
 */
int determinantMatrix ( int ilosc_kolumn, int w, int * WK, int ** tabA );
/**
 *
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param w poczatek
 * @param WK zmienna przechowujaca wektor kolumn
 * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @details funkcja obliczajca wyznacznik macierzy, zwracajaca wartosc typu double
 * @return zwraca wartosc wyznacznika typu double
 */
double determinantMatrix ( int ilosc_kolumn, int w, int * WK, double ** tabA );
/**
 *
 * @param tabA macierz A typu int przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details funkcja sprawdzająca czy podana macierz A jest diagonalna,
 * czyli czy macierz ma wszystkie wspolczynniki lezace poza glowna przekatna sa zerowe oraz czy na glownej przekatnej znajduja sie liczby niezerowe
 * @return zwraca wartosc bool
 */
bool matrixIsDiagonal(int **tabA,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA macierz A typu double przekazywana do funkcji o rozmiarze [ilosc_wierszy] [ilosc_kolumn]
 * @param ilosc_wierszy zmienna przechowujaca ilosc wierszy w macierzy
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @details  funkcja sprawdzająca czy podana macierz A jest diagonalna,
 * czyli czy macierz ma wszystkie wspolczynniki lezace poza glowna przekatna sa zerowe oraz czy na glownej przekatnej znajduja sie liczby niezerowe
 * @return zwraca wartosc bool
 */
bool matrixIsDiagonal(double **tabA,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param a zmienna typu int
 * @param b zmienna typu int
 * @details zamienia podany parametr a z drugim podanym parametrem b, w wyniku czego a jest rowne poczatkowej wartosci b, z koleji b jest rowne poczatkowej wartosci a
 * @return zwraca zamienione dwa parametry
 */
int swap(int &a,int &b);
/**
 *
 * @param a zmienna typu double
 * @param b zmienna typu double
 * @details zamienia podany parametr a z drugim podanym parametrem b, w wyniku czego a jest rowne poczatkowej wartosci b, z koleji b jest rowne poczatkowej wartosci a
 * @return zwraca zamienione dwa parametry
 */
double swap(double &a,double &b);
/**
 *
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param t tablica jednowymiarowa typu int
 * @details  funkcja sortujaca tablice jednowymiarowa sortowaniem babelkowym, sortowanie rosnace
 * @return zwraca tablice t posortowana
 */
int *sortRow(int*t , int ilosc_kolumn);
/**
 *
 * @param ilosc_kolumn zmienna przechowujaca ilosc kolumn w macierzy
 * @param t tablica jednowymiarowa typu double
 * @details funkcja sortujaca tablice jednowymiarowa sortowaniem babelkowym, sortowanie rosnace
 * @return zwraca tablice t posortowana
 */
double *sortRow(double *t, int ilosc_kolumn);
/**
 *
 * @param tabA
 * @param ilosc_wierszy
 * @param ilosc_kolumn
 * @details funkcja sortująca wiersze w macierzy
 * @return W posortowana macierz
 */
int **sortRowsInMatrix (int **tabA,int ilosc_wierszy,int ilosc_kolumn);
/**
 *
 * @param tabA
 * @param ilosc_wierszy
 * @param ilosc_kolumn
 * @details funkcja sortująca wiersze w macierzy
 * @return W posortowana macierz
 */

double **sortRowsInMatrix (double **tabA,int ilosc_wierszy,int ilosc_kolumn);
int **matrixGenerate(pair <int,int>,int wybor_dolny,int wybor_gorny);
double **matrixGenerate(pair <int ,int > matrixSize, double wybor_dolny, double wybor_gorny);
int wpisz_tabA (int** tabA,int ilosc_wierszy , int ilosc_kolumn);
double wpisz_tabA (double** tabA,int ilosc_wierszy , int ilosc_kolumn);
int wpisz_tabB (int** tabB,int ilosc_wierszy , int ilosc_kolumn);
double wpisz_tabB (double** tabB,int ilosc_wierszy , int ilosc_kolumn);
int** dynamiczna_alokacja(int ilosc_wierszy,int ilosc_kolumn);
double** dynamiczna_alokacja_double(int ilosc_wierszy,int ilosc_kolumn);
void odczyt (int **tabA,int ilosc_wierszy,int ilosc_kolumn);
void odczyt_double (double **tabA,int ilosc_wierszy,int ilosc_kolumn);
void zwalnianie_pamieci_macierz(int** tabA, int ilosc_wierszy);
void zwalnianie_pamieci_macierz(double** tabA, int ilosc_wierszy);
int wczytaj_liczbe (void);
int wczytaj_liczbe_double (void);
void help();
int rozmiar_macierzy();