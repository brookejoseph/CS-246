#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Observer
{
public:
    virtual ~Observer() {};
    virtual void update(string val) = 0;
};

class Subject
{
    vector<shared_ptr<Observer>> obs;

public:
    virtual void addObs(shared_ptr<Observer> o)
    {
        obs.emplace_back(o);
    };

    virtual void removeObs(shared_ptr<Observer> o)
    {
        obs.erase(remove(obs.begin(), obs.end(), o), obs.end());
    };

    virtual void notifyObs(string title)
    {
        for (auto i : obs)
        {
            i->update(title);
        }
    }
};

class News : public Subject
{
private:
    string title;

public:
    News(string title) : title(title) {};
    string getTitle()
    {
        return title;
    };
};

class Informed : public Observer
{
    string desiredNews;

public:
    Informed(string val) : desiredNews(val) {};
    void update(string val) override
    {
        cout << "I love " << desiredNews << " channel" << endl;
    };
};