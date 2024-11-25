#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Device
{
public:
    virtual void operate() = 0;
    virtual ~Device() = default;
};

class Light : public Device
{
public:
    void operate() override
    {
        std::cout << "Light is turned on.\n";
    }
};

class SchedulerDecorator : public Device
{
private:
    Device *next;
    std::string schedule;

public:
    SchedulerDecorator(Device *d, const std::string &time) : next(d), schedule(time) {}
    void operate() override
    {
        std::cout << "Scheduled at: " << schedule << "\n";
        next->operate();
    }
};

class EnergySavingDecorator : public Device
{
private:
    Device *next;

public:
    EnergySavingDecorator(Device *d) : next(d) {}
    void operate() override
    {
        std::cout << "Operating in energy-saving mode.\n";
        next->operate();
    }
};

int main()
{
    Device *light = new Light();
    light = new SchedulerDecorator(light, "6:00 PM");
    light = new EnergySavingDecorator(light);
    light->operate();
    delete light;
}