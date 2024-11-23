#include <iostream>
#include <string>
#include <vector>
using namespace std;

// stock market is the subject
// traderApp and news outlet are the observers
// observers only receieve information on the stock they want

class StockMarket
{
private:
    string stockTicker;

public:
    virtual void notifyObs(const string &ticker) = 0;
    virtual void attachObs(Observer *o) = 0;
    virtual void detachObs(Observer *o) = 0;
    string getTicker() const { return stockTicker; }
};

class Observer
{
protected:
    vector<StockMarket *> ptr;

public:
    virtual void notify(const string &ticker) = 0;
};

class TraderApp : public Observer
{
    string ticker;

public:
    TraderApp(const string &interestedTicker) : ticker(interestedTicker) {}

    void notify(const string &ticker) override
    {
        if (this->ticker == ticker)
        {
            cout << "TraderApp received update for ticker: " << ticker << endl;
        }
    }
};
