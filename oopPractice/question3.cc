class Car
{
public:
    Car();
    Car(string brand, string model, int year);
    virtual ~Car();
    void printInfo();

private:
    string brand;
    string model;
    int year;
};

Car::Car(string brand, string model, int year) : brand(brand), model(model), year(year) {};

Car::Car()
{
    this->brand = "honda";
    this->model = "x43";
    this->year = 1972;
};

Car::~Car() {};

void Car::printInfo()
{
    cout << "the brand is" << this->brand << endl;
    cout << "the model is" << this->model << endl;
    cout << "the year is" << this->year << endl;
};

int main()
{
    Car car1;
    car1.printInfo();

    Car car2("Toyota", "Corolla", 2020);
    car2.printInfo();

    return 0;
}
