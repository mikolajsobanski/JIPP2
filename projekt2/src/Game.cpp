#include <iostream>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

enum objects {EMPTY, WALL, SNAKE_HEAD, SNAKE_TAIL, FRUIT};
objects** Map;

int m_x = 40;
int m_y = 10;
int score=0;
bool gameOver;
int x=110;

void Snake::_KeyBoard()
{
    /*
        1                up                     w
    2       3     left        right       a            d
        4               down                    s
    */
    if (_kbhit())
    {
        char input = _getch();

        if (input == 'w')
        {
            _direction = 1;
        }
        else if (input == 'a')
        {
            _direction = 2;
        }
        else if (input == 'd')
        {
            _direction = 3;
        }
        else if (input == 's')
        {
            _direction = 4;
        }
    }
}

void Snake::_MoveSnake()
{
    _x_old = _x;
    _y_old = _y;

    switch(_direction)
    {
        case 1:
        {
            _y--;
            break;
        }
        case 2:
        {
            _x--;
            break;
        }
        case 3:
        {
            _x++;
            break;
        }
        case 4:
        {
            _y++;
            break;
        }
    }

    Map[_y_old][_x_old] = EMPTY;
    Map[_y][_x] = SNAKE_HEAD;
}

void Snake::_AddTail()
{
    if (_tsize == 0)
    {
        for (int i=0;i<2;i++)
        {
            tails.push_back(Tail());
            tails[i].x = 19 - i;
            tails[i].y = 4;
            Map[tails[i].y][tails[i].x] = SNAKE_TAIL;
            _tsize++;
        }
    }

    if (_Ate())
    {
        tails.push_back(Tail());

        switch(_direction)
        {
            case 1:
            {
                tails[_tsize].x = tails[_tsize - 1].x;
                tails[_tsize].y = tails[_tsize - 1].y - 1;
                break;
            }
            case 2:
            {
                tails[_tsize].x = tails[_tsize - 1].x + 1;
                tails[_tsize].y = tails[_tsize - 1].y;
                break;
            }
            case 3:
            {
                tails[_tsize].x = tails[_tsize - 1].x - 1;
                tails[_tsize].y = tails[_tsize - 1].y;
                break;
            }
            case 4:
            {
                tails[_tsize].x = tails[_tsize - 1].x;
                tails[_tsize].y = tails[_tsize - 1].y + 1;
                break;
            }
        }
        _tsize++;
        score++;
        if(score==10 || score==20 || score==30 || score ==40 || score==50 || score==60 || score==70|| score == 80 || score==90 || score==100){
            x-=10;
        }
    }
}

bool Snake::_Ate()
{
    if (_direction == 1 && Map[_y - 1][_x] == FRUIT)
    {
        return true;
    }
    else if (_direction == 2 && Map[_y][_x - 1] == FRUIT)
    {
        return true;
    }
    else if (_direction == 3 && Map[_y][_x + 1] == FRUIT)
    {
        return true;
    }
    else if (_direction == 4 && Map[_y + 1][_x] == FRUIT)
    {
        return true;
    }

    return false;
}

void Snake::_MoveTail()
{
    Map[tails[_tsize - 1].y][tails[_tsize - 1].x] = EMPTY;

    for (int i=_tsize - 1;i!=0;i--)
    {
        tails[i].x = tails[i-1].x;
        tails[i].y = tails[i-1].y;
    }

    tails[0].x = _x_old;
    tails[0].y = _y_old;

    Map[_y_old][_x_old] = SNAKE_TAIL;
}

void Snake::_Collision()
{
    if (_x == 0 || _x == 39)
    {
        cout << "YOU LOST, SCORE : " << score << endl;
        gameOver = true;
    }
    if (_direction == 1 && Map[_y - 1][_x] == WALL || _direction == 4 && Map[_y + 1][_x] == WALL)
    {
        cout << "YOU LOST, SCORE : " << score << endl;
        gameOver = true;
    }
    if (_direction == 1 && Map[_y - 1][_x] == SNAKE_TAIL)
    {
        cout << "YOU LOST, SCORE : " << score << endl;
        gameOver = true;
    }
    else if (_direction == 2 && Map[_y][_x - 1] == SNAKE_TAIL)
    {
        cout << "YOU LOST, SCORE : " << score << endl;
        gameOver = true;
    }
    else if (_direction == 3 && Map[_y][_x + 1] == SNAKE_TAIL)
    {
        cout << "YOU LOST, SCORE : " << score << endl;
        gameOver = true;
    }
    else if (_direction == 4 && Map[_y + 1][_x] == SNAKE_TAIL)
    {
        cout << "YOU LOST, SCORE : " << score << endl;
        gameOver = true;
    }
}

void Snake::update()
{
    _KeyBoard();
    _AddTail();
    _Collision();
    _MoveSnake();
    _MoveTail();
}

void Fruit::_spawnFruit()
{
    int x,y;
    x = 1 + rand() % 38;
    y = 1 + rand() % 8;

    Map[y][x] = FRUIT;
}

bool Fruit::_check_for_fruit()
{
    for (int i=1;i<m_y - 1;i++)
    {
        for (int j=1;j<m_x - 1;j++)
        {
            if (Map[i][j] == FRUIT)
            {
                return true;
            }
        }
    }
    return false;
}

void Fruit::update()
{
    if (!_check_for_fruit())
    {
        _spawnFruit();
    }
}

void Game ::save() {
    string nickname;
    fstream file;
    file.open("results.txt", ios::out | ios::app);
    if(file.good()==false)
    {
        cout << "error open file";
    }
    cout << "Enter your nickname"<<endl;
    cin >> nickname;
    file <<"\t|Nickname:  "<< nickname << "\t|Score:  " << score << "\t|"<< endl;
    file.close();
}
void Game ::load() {
    string line;
    fstream file;
    file.open("results.txt", ios::in);
    if(file.good()==false)
    {
        cout << "error open file";
    }
    cout << "\t\t  ALL RESULTS\n\n";
    while(getline(file,line))
    {
        cout << line;
        cout<< endl;
    }
    file.close();
}
void Game::play() {
    vector<GameObject*>updates;
    while (!gameOver)
    {
        draw();
        Scene(updates);
        Sleep(x);
    }
    if(gameOver)
    {
        Points s(score);
        Points x(x);
        Points p;
        p = x * s;
        cout<< "points: " << p.x << endl;
        save();
        gameOver=false;
        score=0;
        x=110;
    }
}
Game ::Game() {
    Map = new objects*[m_y];
    for (int i=0;i<m_y;i++)
    {
        Map[i] = new objects[m_x];
    }

    for (int i=0;i<m_y;i++)
    {
        for (int j=0;j<m_x;j++)
        {
            if (i == 0 || i == m_y-1 || j == 0 || j == m_x-1)
            {
                Map[i][j] = WALL;
            }
            else
            {
                Map[i][j] = EMPTY;
            }
        }
    }
}
void Game :: Scene(vector<GameObject*>&updates)
{
    if (updates.size() == 0)
    {
        updates.push_back(new Snake());
        updates.push_back(new Fruit());
    }

    for (vector<GameObject*>::iterator itr = updates.begin(), end = updates.end();itr != end; itr++)
    {
        (*itr)->update();
    }
}

void Game :: draw()
{
    COORD cur = {0,0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

    for (int i=0;i<m_y;i++)
    {
        for (int j=0;j<m_x;j++)
        {
            if (Map[i][j] == WALL)
            {
                cout << "#";
            }
            else if (Map[i][j] == EMPTY)
            {
                cout << " ";
            }
            else if (Map[i][j] == SNAKE_HEAD)
            {
                cout << "O";
            }
            else if (Map[i][j] == SNAKE_TAIL)
            {
                cout << "o";
            }
            else if (Map[i][j] == FRUIT)
            {
                cout << "+";
            }
        }
        cout << endl;
    }
    cout << endl;
    int *wsk = &score;
    cout << "\n\t\tScore:" << *wsk <<endl;
    level_m(x);
}

Game::~Game() {

}

void Game::options() {
    char oo;
    cout
            << "\nP: Change size of map"
            << "\nL: Documentation"
            << "\nInput your command ";
    cin >> oo;
    if (oo >= 'a' && oo <= 'z')
        oo += ('A' - 'a');

    switch (oo) {
        case 'P':
            try {
                change_map();
            }
            catch(const char* x)
            {
                cout << "Message: " << x << endl ;
            }
            cout << "board surface: " << q(m_x,m_y) << endl;
            break;
        case 'L':
            help();
            break;
        default:
            cout << "Invalid input." << endl;
            break;
    }
}

void Game::level_m(int x) {
    int level;

    if(x==110){
        level=1;
        cout<< "\n\t\tLevel: 1" << endl;
    }
    if(x==100){
        level=2;
        cout<< "\n\t\tLevel: 2" << endl;
    }
    if(x==90){
        level=3;
        cout<< "\n\t\tLevel: 3" << endl;
    }
    if(x==80){
        level=4;
        cout<< "\n\t\tLevel: 4" << endl;
    }
    if(x==70){
        level=5;
        cout<< "\n\t\tLevel: 5" << endl;
    }
    if(x==60){
        level=6;
        cout<< "\n\t\tLevel: 6" << endl;
    }
    if(x==50){
        level=7;
        cout<< "\n\t\tLevel: 7" << endl;
    }
    if(x==40){
        level=8;
        cout<< "\n\t\tLevel: 8" << endl;
    }
    if(x==30){
        level=9;
        cout<< "\n\t\tLevel: 9" << endl;
    }
    if(x==20){
        level=10;
        cout<< "\n\t\tLevel: 10" << endl;
    }
    if(x==10){
        level=11;
        cout<< "\n\t\tLevel: MASTER" << endl;
    }
}
void Game::level_m(double x) {
    int level;

    if(x==110){
        level=1;
        cout<< "\n\t\tLevel: 1" << endl;
    }
    if(x==100){
        level=2;
        cout<< "\n\t\tLevel: 2" << endl;
    }
    if(x==90){
        level=3;
        cout<< "\n\t\tLevel: 3" << endl;
    }
    if(x==80){
        level=4;
        cout<< "\n\t\tLevel: 4" << endl;
    }
    if(x==70){
        level=5;
        cout<< "\n\t\tLevel: 5" << endl;
    }
    if(x==60){
        level=6;
        cout<< "\n\t\tLevel: 6" << endl;
    }
    if(x==50){
        level=7;
        cout<< "\n\t\tLevel: 7" << endl;
    }
    if(x==40){
        level=8;
        cout<< "\n\t\tLevel: 8" << endl;
    }
    if(x==30){
        level=9;
        cout<< "\n\t\tLevel: 9" << endl;
    }
    if(x==20){
        level=10;
        cout<< "\n\t\tLevel: 10" << endl;
    }
    if(x==10){
        level=11;
        cout<< "\n\t\tLevel: MASTER" << endl;
    }
}

void Game::change_map() {
    cout << "Actual size of map: HEIGHT " << m_y << " WIDTH: " << m_x << endl;
    cout << "Pass new height, height couldnt be less than 10\n";
    cin >> m_y;
    if(m_y < 10)
    {
        m_y=10;
        throw "To small!";
    }
    cout << "Pass new width, withcouldnt be less than 40\n";
    cin >> m_x;
    if(m_x < 40)
    {
        m_x=40;
        throw "To small!";
    }
}
void Game :: help()
{
    cout <<
    " /**\n"
    " * @class GameObject\n"
    " * @details klasa wirtualna przechowujaca updaty snake oraz fruit\n"
    " */"
    " /**\n"
    " * @class Points\n"
    " * @details klasa obliczajaca punkty\n"
    " * @param int x - parametr przypisywany przeciazonemu konstruktorowi\n"
    " * @details przeciazanie operatora mnozenia\n"
    " */"
    "/**\n"
    " * @class Snake\n"
    " * @details klasa snake\n"
    " * @param _x - polozenie x weza\n"
    " * @param _y - polozenie y weza\n"
    " * @param _direction - kierunek poruszania sie weza\n"
    " * @struct tail - ogon weza\n"
    " * @method update() - zbior funkcji [_KeyBoard(), _MoveSnake(), _AddTail(), _MoveTail(), _Collision()]\n"
    " * @method _KeyBoard() - obsluga klawiatry, poruszanie wezem\n"
    " * @method _MoveSnake() - ruch weza\n"
    " * @method _AddTail() - dodanie kolejnej czesci weza\n"
    " * @method _Ate() - zjedzenie owocu\n"
    " * @method _MoveTail() - poruszanie ogona\n"
    " * @method _Collision() - zderzenie, zakonczenie gry\n"
    " */"
    "/**\n"
    " * @class Fruit\n"
    " * @method update() - zbior funkcji [ _spawnFruit(), _chceck_for_fruit()]\n"
    " * @method _spawnFruit() - wygenerowanie owoca\n"
    " * @method _check_for_fruit() - sprawdzenie czy jest na mapie owoc\n"
    " */"
    "/**\n"
    " * @class Game\n"
    " * @constructor Game() - inicjalizuje mape\n"
    " * @destructor ~Game()\n"
    " * @method draw() - funkcja rysujaca mape gry\n"
    " * @method Scene(vector<GameObject*>&updates) - funkcja odswiezajaca scene\n"
    " * @method play() - funkcja obslugujaca granie w snake\n"
    " * @method save() - funkcja odpowiadajaca za zapis rezultatu gry poprzez podanie swojego niku wraz z uzyskanym wynikiem\n"
    " * @method load() - funkcja odpowiadajaca za odczyt z pliku danych\n"
    " * @method level_m(int x) - funkcja wyswietlajaca biezacy level gry\n"
    " * @method level_m(double x) - przeciazona metoda funkcji level_m()\n"
    " * @method options() - funkcja wyswietlajaca menu opcji\n"
    " * @method change_map() - funkcja ktora zmienia rozmiar mapy gry\n"
    " * @method help() - funkcja wyswietlajaca dokumentacje\n"
    " *@template <class T> T q(T a, T b) - szablon funkcji mnozacej dwa podane parametry, wykorzystana do obliczania powierzchni mapy\n"
    " */\n";
}