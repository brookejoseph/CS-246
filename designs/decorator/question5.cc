#include <iostream>
#include <string>
using namespace std;

// main class
class GameObject
{
public:
    virtual void update() = 0;
};

// basic implmentation

class BasicGame : public GameObject
{
    void update() override
    {
        cout << "Welcome to the game!" << endl;
    };
};

class GameDec : public GameObject
{
protected:
    GameObject *next;

public:
    GameDec(GameObject *ptr) : next{ptr} {};
    virtual ~GameDec() { delete next; };
    void update() override { next->update(); };
};

class AddSheild : public GameDec
{
    AddSheild(GameObject *val) : GameDec(val) {};
    void update() override
    {
        next->update();
    };
};
