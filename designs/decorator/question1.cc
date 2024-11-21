#include <iostream>
#include <string>
using namespace std;

// Interface
class Text
{
public:
    virtual string getText() = 0;
    virtual ~Text() = default; // Ensure proper cleanup for derived classes
};

// Concrete Component
class Basic : public Text
{
public:
    string getText() override
    {
        return "hello world";
    }
};

// Decorator Base Class
class TextDec : public Text
{
protected:
    Text *text;

public:
    explicit TextDec(Text *textVal) : text(textVal) {}
    virtual ~TextDec() = default;
};

// Concrete Decorators
class AddBold : public TextDec
{
public:
    explicit AddBold(Text *text) : TextDec(text) {}

    string getText() override
    {
        return "<b>" + text->getText() + "</b>"; // Add bold tags
    }
};

class AddItalic : public TextDec
{
public:
    explicit AddItalic(Text *text) : TextDec(text) {}

    string getText() override
    {
        return "<i>" + text->getText() + "</i>"; // Add italic tags
    }
};

class AddBorder : public TextDec
{
public:
    explicit AddBorder(Text *text) : TextDec(text) {}

    string getText() override
    {
        return "[ " + text->getText() + " ]"; // Add a border
    }
};
