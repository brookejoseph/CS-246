#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

class Video
{
public:
    virtual ~Video() {}
    virtual void getDesc() = 0;
};

class BasicVideo : public Video
{
public:
    void getDesc() override
    {
        cout << "The video is playing";
    }
};

class VideoDesc : public Video
{
protected:
    Video *next;

public:
    VideoDesc(Video *next) : next(next) {}
    virtual ~VideoDesc() { delete next; }
    void getDesc() override
    {
        if (next)
            next->getDesc();
    }

    Video *getNext() const { return next; }
};

class Blurry : public VideoDesc
{
public:
    Blurry(Video *next) : VideoDesc(next) {}
    void getDesc() override
    {
        if (next)
            next->getDesc();
        cout << " and blurry";
    }
};

class Gray : public VideoDesc
{
public:
    Gray(Video *next) : VideoDesc(next) {}
    void getDesc() override
    {
        if (next)
            next->getDesc();
        cout << " and gray";
    }
};

class Rose : public VideoDesc
{
public:
    Rose(Video *next) : VideoDesc(next) {}
    void getDesc() override
    {
        if (next)
            next->getDesc();
        cout << " and rose";
    }
};

class Iterator
{
    Video *current;

public:
    Iterator(Video *start) : current(start) {}

    Iterator &operator++()
    {
        if (VideoDesc *desc = dynamic_cast<VideoDesc *>(current))
        {
            current = desc->getNext();
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Video &operator*()
    {
        return *current;
    }

    bool operator!=(const Iterator &other) const
    {
        return current != other.current;
    }
};

// Main Function
int main()
{
    Video *video = new BasicVideo();
    video = new Blurry(video);
    video = new Gray(video);
    video = new Rose(video);

    Iterator begin(video);
    Iterator end(nullptr);

    cout << "Iterating through video descriptions:" << endl;
    for (Iterator it = begin; it != end; ++it)
    {
        (*it).getDesc();
        cout << endl;
    }

    // Clean up
    delete video;

    return 0;
}
