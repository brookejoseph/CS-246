#include <iostream>
#include <string>
#include <vector>

using namespace std;

// devices/subjects: themrostat, light switches, security cameras
// observers: homeowners, guests

// notifies when there is a change in temp

class Obs
{
public:
    virtual ~Obs() = default;
    virtual void notify(string message, int time) = 0;
};

class Subject
{
protected:
    int time;
    string message;
    vector<Obs *> oVec;

public:
    virtual void addObs(Obs *o) {};
    virtual void removeObs(Obs *o) {};
    virtual void notifyObs(string message, int time) {};
    virtual void update(string message) {};
};

class Thermostat : public Subject
{
public:
    void addObs(Obs *o) override
    {
        oVec.emplace_back(o);
    };

    void removeObs(Obs *o) override
    {
        oVec.erase(remove(oVec.begin(), oVec.end(), o), oVec.end());
    };

    void notifyObs(string message, int time) override
    {
        for (auto i : oVec)
        {
            cout << "Thermostat changed" << endl;
            i->notify(message, time);
        };
    };

    void update(string message) override
    {
        message = message;
    };
};

class LightSwitch : public Subject
{
public:
    void addObs(Obs *o) override
    {
        oVec.emplace_back(o);
    };

    void removeObs(Obs *o) override
    {
        oVec.erase(remove(oVec.begin(), oVec.end(), o), oVec.end());
    };

    void notifyObs(string message, int time) override
    {
        for (auto i : oVec)
        {
            cout << "LightSwitch changed" << endl;
            i->notify(message, time);
        };
    };

    void update(string message) override
    {
        message = message;
    };
};

class Camera : public Subject
{
public:
    void addObs(Obs *o) override
    {
        oVec.emplace_back(o);
    };

    void removeObs(Obs *o) override
    {
        oVec.erase(remove(oVec.begin(), oVec.end(), o), oVec.end());
    };

    void notifyObs(string message, int time) override
    {
        for (auto i : oVec)
        {
            cout << "Camera changed" << endl;
            i->notify(message, time);
        };
    };

    void update(string message) override
    {
        message = message;
    };
};