#include "../include/firstClass.h"

FirstClass::FirstClass(string productName, unsigned int price, unsigned int weight, unsigned int amount):
        price(price), weight(weight), amount(amount){
    this->productName = productName;
}

void FirstClass::showBasicData() {
    cout << productName << " " << price << " gr" << endl;
}

void FirstClass::showDetails() {
    cout << weight << " kg, " << amount << " pcs." <<endl;
}

void FirstClass::showAllData() {
    showBasicData();
    showDetails();
}

void FirstClass::setPrice(unsigned int price) {
    this->price = price;
}

unsigned int FirstClass::getPrice() {
    return price;
}

Prostopadlo::Prostopadlo(double p1, double p2, double p3):
p1(p1),p2(p2),p3(p3){

}
void Prostopadlo::wynik()
{
    double w;
    w=p1*2+p2*2+p3*2;
    cout << w << endl;
}
Kula::Kula(double r):r(r){

}
void Kula::V()
{
    double w;
    w=4/3*3,141592*r*r*r;
    cout << w << endl;
}

FunkcjaKwadratowa::FunkcjaKwadratowa(double a,double b,double c):a(a),b(b),c(c)
{

}
void FunkcjaKwadratowa::Z()
{
    cout << "f(x) = " << a << "x^2 + " << b << "x + " << c << endl;
}

Student::Student(string imie,string nazwisko,int numer_albumu, double pytania,double poprawne):imie(imie),nazwisko(nazwisko),
numer_albumu(numer_albumu),pytania(pytania),poprawne(poprawne){

}
void Student::X()
{
    cout << "podaj imie,nazwisko,numer albumu,liczbe pytan,liczbe poprawnych odpowiedzi"<< endl;
    cin >> imie >> nazwisko >> numer_albumu >> pytania >> poprawne;
}
void Student::procent()
{
    double w;
    w= (poprawne/pytania)*100;
    cout << "procent poprawnych odpowiedzi  " << w << "%" <<endl;
}