#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Widget
{
protected:
    string name;

public:
    virtual void identify() const
    {
        cout << "I am a widget!  My name is " << name << "!" << endl;
    }
    Widget(const string &name) : name{name} {}
    Widget(const Widget &other) : name{other.name}
    {
        cout << "I am a widget being copied!" << endl;
    }
    Widget(Widget &&other) : name{other.name}
    {
        other.name = "";
        cout << "I am a widget being moved!" << endl;
    }

    virtual ~Widget() {}

    // Virtual copy method
    virtual Widget *copy() const
    {
        return new Widget(*this);
    }
};

class Wudget : public Widget
{
protected:
    string nickname;

public:
    Wudget(string &nickname, string &name) : Widget(name), nickname(nickname) {};
    ~Wudget() {};
    Wudget(Wudget &other) : Widget(other.name), nickname(other.nickname) {};
    Wudget(Wudget &&other) : Widget(move(other.name)), nickname(other.nickname) {};

    void identify()
    {
        cout << "there is a wugdet" << endl;
    };
};

class WidgetGathering
{
    Widget chiefWidget;
    Wudget chiefWudget;
    int numAttendees;
    Widget **attendees;

public:
};

int main()
{
}
