#include <iostream>
#include "../include/calc.h"
using namespace std;



int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
return a - b;
}

int volume(int a, int b, int h, int H){
    return ((a+b)*h/2)*H;

}
void help(){
    cout << "help\n" << endl;
    cout << "\"Simple calculatur\\n\"\n"
            "                \"Dzialania:\\n\"\n"
            "                \"A-add [a] [b]\\n\"\n"
            "                \"    Dodawanie dwoch liczb ([a] i [b]) calkowitych.  \\n \"\n"
            "                \"B-subtract [a] [b] \\n\"\n"
            "                \"    Odejmowanie dwoch liczb ([a] i [b] calkowitych\\n\"\n"
            "                \"C-volume [a] [b]\\n\"\n"
            "                \"    Obliczanie objetosci graniastoslupa o podstawie trapeza\\n\"\n"
            "                \"D-help\\n\"\n"
            "                \"E-Exit\\n\"\n"
            "                \"Wybierz dzialanie podajac liczby 1-5\\n\"" << endl;
}