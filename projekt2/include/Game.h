#ifndef JIPP2_GAME_H
#define JIPP2_GAME_H
#include <vector>

using namespace std;

/**
 * @class GameObject
 * @details klasa wirtualna przechowujaca updaty snake oraz fruit
 */
class GameObject
{
public:
    virtual void update() = 0;
};
/**
 * @class Points
 * @details klasa obliczajaca punkty
 * @param int x - parametr przypisywany przeciazonemu konstruktorowi
 * @details przeciazanie operatora mnozenia
 */
class Points{
public:
    int x;
    Points(){};
    Points(int a) : x(a){
    }
    Points operator* (Points &obj)
    {
        Points wynik;
        wynik = x * obj.x;
        return wynik;
    }
};
/**
 * @class Snake
 * @details klasa snake
 * @param _x - polozenie x weza
 * @param _y - polozenie y weza
 * @param _direction - kierunek poruszania sie weza
 * @struct tail - ogon weza
 * @method update() - zbior funkcji [_KeyBoard(), _MoveSnake(), _AddTail(), _MoveTail(), _Collision()]
 * @method _KeyBoard() - obsluga klawiatry, poruszanie wezem
 * @method _MoveSnake() - ruch weza
 * @method _AddTail() - dodanie kolejnej czesci weza
 * @method _Ate() - zjedzenie owocu
 * @method _MoveTail() - poruszanie ogona
 * @method _Collision() - zderzenie, zakonczenie gry
 */
class Snake : public GameObject
{
public:
    void update();
private:
    int _x = 19;
    int _y = 4;
    int _x_old, _y_old;
    int _direction = 3;
    int _tsize = 0;

    struct Tail
    {
        int x;
        int y;
    };

    vector<Tail>tails;

    void _KeyBoard();
    void _MoveSnake();
    void _AddTail();
    bool _Ate();
    void _MoveTail();
    void _Collision();
};
/**
 * @class Fruit
 * @method update() - zbior funkcji [ _spawnFruit(), _chceck_for_fruit()]
 * @method _spawnFruit() - wygenerowanie owoca
 * @method _check_for_fruit() - sprawdzenie czy jest na mapie owoc
 */
class Fruit : public GameObject
{
public:
    void update();
private:
    int _x;
    int _y;
    void _spawnFruit();
    bool _check_for_fruit();
};
/**
 * @class Game
 * @constructor Game() - inicjalizuje mape
 * @destructor ~Game()
 * @method draw() - funkcja rysujaca mape gry
 * @method Scene(vector<GameObject*>&updates) - funkcja odswiezajaca scene
 * @method play() - funkcja obslugujaca granie w snake
 * @method save() - funkcja odpowiadajaca za zapis rezultatu gry poprzez podanie swojego niku wraz z uzyskanym wynikiem
 * @method load() - funkcja odpowiadajaca za odczyt z pliku danych
 * @method level_m(int x) - funkcja wyswietlajaca biezacy level gry
 * @method level_m(double x) - przeciazona metoda funkcji level_m()
 * @method options() - funkcja wyswietlajaca menu opcji
 * @method change_map() - funkcja ktora zmienia rozmiar mapy gry
 * @method help() - funkcja wyswietlajaca dokumentacje
 *@template <class T> T q(T a, T b) - szablon funkcji mnozacej dwa podane parametry, wykorzystana do obliczania powierzchni mapy
 */
class Game : Snake{
public:
    Snake snake;
    Fruit fruit;
    void draw();
    void Scene(vector<GameObject*>&updates);
    Game();
    void play();
    void save();
    void load();
    ~Game();
    void level_m(int x);
    void level_m(double x);
    void options();
    void change_map();
    void help();
    template<class T>
    T q(T a, T b)
    {
        return a * b;
    }
};
#endif //JIPP2_GAME_H
