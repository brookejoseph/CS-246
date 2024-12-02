#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer
{
public:
    virtual ~Observer() {};
    virtual void notify() = 0;
};

class Subject
{
protected:
    vector<Observer *> obs;

public:
    virtual void notifyObs() = 0;
    virtual void addObs(Observer *o) = 0;
    virtual void removeObs(Observer *o) = 0;
};

class PackageA : public Observer, public Subject
{
public:
    void notify() override
    {
        cout << "PackageA ";
    };

    void addObs(Observer *o) override
    {
        obs.emplace_back(o);
    };

    void removeObs(Observer *o) override
    {
        obs.erase(std::remove(obs.begin(), obs.end(), o), obs.end());
    }
    void notifyObs() override
    {
        for (auto i : obs)
        {
            i->notify();
        };
    };
};

class PackageB : public Observer, public Subject
{
public:
    void notify() override
    {
        cout << "PackageB ";
    };

    void addObs(Observer *o) override
    {
        obs.emplace_back(o);
    };

    void removeObs(Observer *o) override
    {
        obs.erase(std::remove(obs.begin(), obs.end(), o), obs.end());
    }
    void notifyObs() override
    {
        for (auto i : obs)
        {
            i->notify();
        };
    };
};

class PackageC : public Observer, public Subject
{
public:
    void notify() override
    {
        cout << "PackageC ";
    };

    void addObs(Observer *o) override
    {
        obs.emplace_back(o);
    };

    void removeObs(Observer *o) override
    {
        obs.erase(std::remove(obs.begin(), obs.end(), o), obs.end());
    }
    void notifyObs() override
    {
        for (auto i : obs)
        {
            i->notify();
        };
    };
};

int main()
{
    PackageA a;
    PackageB b;
    PackageC c;

    a.addObs(&b);
    a.addObs(&c);

    b.addObs(&c);

    cout << "Notifying observers of PackageA: ";
    a.notifyObs();
    cout << endl;

    cout << "Notifying observers of PackageB: ";
    b.notifyObs();
    cout << endl;

    a.removeObs(&c);

    cout << "Notifying observers of PackageA after removing PackageC: ";
    a.notifyObs();
    cout << endl;

    return 0;
}
