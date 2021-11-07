//
// Created by mikol on 25.10.2021.
//
#include <iostream>
#include "../include/firstClass.h"
using namespace std;

struct car {
    string marka;
    string model;
    int rok;
    string kolor;
    int przebieg;
};
int main()
{
    FirstClass product("Pass exam", 100000000, 1000, 0);
    product.showAllData();
    product.setPrice(2000000000);
    product.showAllData();
    cout << product.getPrice() << endl;
    cout << " nowe zadanie\n"
            "--------------------------------------------------\n";
    Prostopadlo s(2,5,7);
    s.wynik();
    cout << " nowe zadanie\n"
            "--------------------------------------------------\n";
    Kula k(10);
    k.V();
    FunkcjaKwadratowa z(2,4,8);
    z.Z();

    cout << " nowe zadanie\n"
            "--------------------------------------------------\n";
    Student Student("mikolaj","sobanski",1389,100,80);
    Student.X();
    Student.procent();
    cout << " nowe zadanie\n"
            "--------------------------------------------------\n";
    car sport={"Mercedes","E klasa amg 63s", 2021,"czarny", 10};
    cout<< "|marka: " << sport.marka << "|\t |model: "<< sport.model<< "|\t |rok produkcji: " << sport.rok << "|\t |kolor: "<< sport.kolor<< "|\t |przebieg: " << sport.przebieg<< "|" << endl;
    return 0;
}
