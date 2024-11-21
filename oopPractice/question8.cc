#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Racer
{
    unsigned int distance;

public:
    Racer() : distance(0) {} // initializes distance to 0
    unsigned getDistance() const { return distance; }
    virtual ~Racer() = default;

    virtual void incrementDistance(int amount)
    {
        distance += amount;
    };

    virtual void tick() = 0;
};

class Tortoise : public Racer
{
public:
    void tick() override
    {
        incrementDistance(1);
    };
};

class Hare : public Racer
{
    int time;

public:
    Hare(Racer &Racer) : time{0}, Racer{Racer} {};
    void tick() override
    {
        if (time == 10)
        {
            while (time != 40)
            {
                time++;
            };
            time = 0;
        }
        time++;
        incrementDistance(2);
    };
};
