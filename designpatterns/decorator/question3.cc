#include <iostream>
#include <string>
#include <memory>

// Base Interface
class Drawable
{
public:
    virtual std::string draw() const = 0;
    virtual ~Drawable() = default;
};

// Text Class
class Text : public Drawable
{
    std::string content;

public:
    explicit Text(const std::string &content) : content(content) {}

    std::string draw() const override
    {
        return "Text: " + content;
    }
};

// Image Class
class Image : public Drawable
{
    std::string fileName;

public:
    explicit Image(const std::string &fileName) : fileName(fileName) {}

    std::string draw() const override
    {
        return "Image: " + fileName;
    }
};

// Base Decorator
class DrawableDecorator : public Drawable
{
protected:
    std::shared_ptr<Drawable> drawable;

public:
    explicit DrawableDecorator(std::shared_ptr<Drawable> drawable) : drawable(std::move(drawable)) {}

    std::string draw() const override
    {
        return drawable->draw();
    }
};

// Shared Decorators
class BorderDecorator : public DrawableDecorator
{
public:
    explicit BorderDecorator(std::shared_ptr<Drawable> drawable) : DrawableDecorator(std::move(drawable)) {}

    std::string draw() const override
    {
        return drawable->draw() + " with Border";
    }
};

class ShadowDecorator : public DrawableDecorator
{
public:
    explicit ShadowDecorator(std::shared_ptr<Drawable> drawable) : DrawableDecorator(std::move(drawable)) {}

    std::string draw() const override
    {
        return drawable->draw() + " with Shadow";
    }
};

// Text-Specific Decorators
class ItalicDecorator : public DrawableDecorator
{
public:
    explicit ItalicDecorator(std::shared_ptr<Drawable> drawable) : DrawableDecorator(std::move(drawable)) {}

    std::string draw() const override
    {
        return drawable->draw() + " in Italic";
    }
};

class BoldDecorator : public DrawableDecorator
{
public:
    explicit BoldDecorator(std::shared_ptr<Drawable> drawable) : DrawableDecorator(std::move(drawable)) {}

    std::string draw() const override
    {
        return drawable->draw() + " in Bold";
    }
};

// Usage
int main()
{
    // Create a text object and decorate it
    auto text = std::make_shared<Text>("Hello World");
    auto boldText = std::make_shared<BoldDecorator>(text);
    auto borderedBoldText = std::make_shared<BorderDecorator>(boldText);

    std::cout << borderedBoldText->draw() << std::endl; // Output: Text: Hello World in Bold with Border

    // Create an image object and decorate it
    auto image = std::make_shared<Image>("photo.jpg");
    auto shadowedImage = std::make_shared<ShadowDecorator>(image);
    auto borderedShadowedImage = std::make_shared<BorderDecorator>(shadowedImage);

    std::cout << borderedShadowedImage->draw() << std::endl; // Output: Image: photo.jpg with Shadow with Border

    return 0;
}
