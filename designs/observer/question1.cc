#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weather
{
public:
    virtual void notify(int &temp) {};
};

class WeatherDisplays
{
    vector<Weather> currentTemp;

public:
    void changeTemp(const int &temp)
    {
    }
};