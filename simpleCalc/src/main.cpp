#include <iostream>
#include "../include/calc.h"

using namespace std;

int main() {
    char choice;
    start:

        cout << "Simple calculatur\n"
                "Dzialania:\n"
                "A-add [a] [b]\n"
                "    Dodawanie dwoch liczb ([a] i [b]) calkowitych.  \n "
                "B-subtract [a] [b] \n"
                "    Odejmowanie dwoch liczb ([a] i [b] calkowitych\n"
                "C-volume [a] [b]\n"
                "    Obliczanie objetosci graniastoslupa o podstawie trapeza\n"
                "D-help\n"
                "E-Exit\n"
                "Wybierz dzialanie podajac liczby 1-5\n"
             << endl;
        cin >> choice;

        switch  (choice) {
            case 'A':
                int a,b;
                cout << "podaj dwie liczby calkowite do dodawania"<<endl;
                cin >> a ;
                cin >> b ;
                cout << add(a,b) << endl;
                break;
            case 'a':
                cout << "podaj dwie liczby calkowite do dodawania"<<endl;
                cin >> a ;
                cin >> b ;
                cout << add(a,b) << endl;
                break;
            case 'B':
                cout << "podaj dwie liczby calkowite do odejmowania"<<endl;
                cin >> a ;
                cin >> b ;
                cout << subtract(a,b) << endl;
                break;
            case 'b':
                cout << "podaj dwie liczby calkowite do odejmowania"<<endl;
                cin >> a ;
                cin >> b ;
                cout << subtract(a,b) << endl;
                break;
            case 'C':
                int h,H;
                cout << "podaj dlugosc podstawy trapeza"<<endl;
                cin >> a ;
                cout << "podaj druga dlugosc podstawy trapeza"<<endl;
                cin >> b ;
                cout << "podaj wysokosc podstawy trapeza"<<endl;
                cin >> h ;
                cout << "podaj wysokosc graniastoslupa"<<endl;
                cin >> H ;
                cout << volume(5, 3, 4, 6) << endl;
                break;
            case 'c':
                cout << "podaj dlugosc podstawy trapeza"<<endl;
                cin >> a ;
                cout << "podaj druga dlugosc podstawy trapeza"<<endl;
                cin >> b ;
                cout << "podaj wysokosc podstawy trapeza"<<endl;
                cin >> h ;
                cout << "podaj wysokosc graniastoslupa"<<endl;
                cin >> H ;
                cout << volume(5, 3, 4, 6) << endl;
                break;
            case 'D':
                help();
                break;
            case 'd':
                help();
                break;
            default:
                cout << "Nie dokonano poprawnego wyboru\n prosze wybrac jedna z opcji 1-5\n"<< endl;
                break;
            case 'E':
                exit(0);
                break;
            case 'e':
                exit(0);
                break;



        }
        goto start;


    return 0;
}