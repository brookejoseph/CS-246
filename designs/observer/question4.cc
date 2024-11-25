#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(string title) = 0;
};

class Subject
{
protected:
    vector<Observer *> obs;
    string title;

public:
    virtual void addObs(Observer *o) {};
    virtual void removeObs(Observer *o) {};
    virtual void update(string title) {};
    virtual void notify(string title) {};
};

class NewsAgency : public Subject
{
public:
    void addObs(Observer *o) override
    {
        obs.emplace_back(o);
    };

    void removeObs(Observer *o) override
    {
        obs.erase(remove(obs.begin(), obs.end(), o), obs.end());
    };

    void notify(string title) override
    {
        for (auto i : obs)
        {
            i->update(title);
        };
    };

    void update(string title) override
    {
        title = title;
    };
};

class Email : public Observer
{
public:
    void update(string title)
    {
        cout << "I received via email" << endl;
        cout << "The article has name" << title << endl;
    };
};

class AppSubscriber : public Observer
{
public:
    void update(string title)
    {
        cout << "I received via email" << endl;
        cout << "The article has name" << title << endl;
    };
};

int main()
{
    NewsAgency newNews;
    AppSubscriber ap1, ap2;
    Email em1, em2;
    newNews.addObs(&ap1);
    newNews.addObs(&ap2);
    newNews.addObs(&em1);
    newNews.addObs(&em2);
    newNews.notify("Dancing With the Stars");
    newNews.notify("Cat and Dog");
    return 0;
};
