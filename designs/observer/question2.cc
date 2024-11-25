#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update(int newBid) = 0;
    virtual ~Observer() = default;
};
class Subject
{
    int currentBid = 0;
    vector<Observer *> obs;

public:
    void notify(int newBid)
    {
        for (auto i : obs)
        {
            i->update(newBid);
        };
    };

    void updateBid(int bid)
    {
        currentBid = bid;
        notify(bid);
    };
    virtual void addObs(Observer *o)
    {
        obs.emplace_back(o);
    };
    virtual void removeObs(Observer *o)
    {
        obs.erase(remove(obs.begin(), obs.end(), o), obs.end());
    };
};

class Auctioneer : public Observer
{
public:
    void update(int newbid) override
    {
        cout << "My new bid is for " << newbid << "$" << endl;
    };
};

int main()
{
    Subject auction;
    Auctioneer auctioneer1;

    auction.addObs(&auctioneer1);

    auction.updateBid(100); // Notify all observers
    auction.updateBid(150); // Notify all observers

    return 0;
}