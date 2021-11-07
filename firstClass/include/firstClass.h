//
// Created by mikol on 25.10.2021.
//

#ifndef JIPP2_FIRSTCLASS_H
#define JIPP2_FIRSTCLASS_H
#include <iostream>

using namespace std;

class FirstClass {
private:
    string productName;
    unsigned int price = 0;
    unsigned int weight = 0;
    unsigned int amount = 0;

    void showDetails();

public:
    FirstClass(string productName, unsigned int price, unsigned int weight, unsigned int amount);
    void showBasicData();

    void showAllData();

    void setPrice(unsigned int price);

    unsigned int getPrice();

};
class Prostopadlo {
private:
    double p1;
    double p2;
    double p3;
public:
    Prostopadlo(double p1, double p2, double p3);
    void wynik();

};
class Kula {
private:
    double r;
public:
    Kula(double r);
    void V();
};

class FunkcjaKwadratowa{
private:
    double a;
    double b;
    double c;
public:
    FunkcjaKwadratowa(double a,double b, double c);
    void Z();
};
class Student {
private:
    string imie;
    string nazwisko;
    int numer_albumu;
    double pytania;
    double poprawne;
public:
    Student(string imie, string nazwisko, int numer_albumu, double pytania, double poprawne);
    void X();
    void procent();

};
#endif //JIPP2_FIRSTCLASS_H
