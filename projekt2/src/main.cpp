#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "../include/Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    string arg;
    system("Color E4");

    if((argc == 2) && _stricmp( argv[1], "play" ) == 0 ){
        Game game;
        game.play();
    }
    if((argc == 2) && _stricmp( argv[1], "load" ) == 0 ){
        Game game;
        game.load();
    }
    bool run = true;

    /*****************************/
    /*          Menu system       */
    /********************************/

    while (run) {
        Game game;
        char op;
        cout
                << "\nP: Play"
                << "\nL: Load Event"
                << "\nO: Options"
                << "\nQ: Quit"
                << "\nInput your command ";
        cin >> op;
        if (op >= 'a' && op <= 'z')
            op += ('A' - 'a');

        switch (op) {
            case 'P':
                system("cls");
                game.play();
                break;
            case 'L':
                game.load();
                break;
            case 'O':
                game.options();
                break;
            case 'Q':
                run = false;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
    return 0;
}