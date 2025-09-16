#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* model;
    char* country;
    char* color;
    int year;
    double price;

public:
    Car(const char* mod, const char* cou, const char* col, int a, double b) {
        model = new char[strlen(mod) + 1];
        strcpy_s(model, strlen(mod) + 1, mod);

        country = new char[strlen(cou) + 1];
        strcpy_s(country, strlen(cou) + 1, cou);

        color = new char[strlen(col) + 1];
        strcpy_s(color, strlen(col) + 1, col);

        year = a;
        price = b;
        cout << "Constructor with parameters" << endl;
    }
	Car(const Car& obj) { // <-- ÄÇ
        model = new char[strlen(obj.model) + 1];
        strcpy_s(model, strlen(obj.model) + 1, obj.model);

        country = new char[strlen(obj.country) + 1];
        strcpy_s(country, strlen(obj.country) + 1, obj.country);

        color = new char[strlen(obj.color) + 1];
        strcpy_s(color, strlen(obj.color) + 1, obj.color);

        year = obj.year;
        price = obj.price;
    }


    Car() {
        model = nullptr;
        country = nullptr;
        color = nullptr;
        year = 0;
        price = 0.0;
        cout << "Default constructor" << endl;
    }

    void init(const char* mod, const char* cou, const char* col, int a, double b) {
        if (model != nullptr) {
            delete[] model;
        }
        model = new char[strlen(mod) + 1];
        strcpy_s(model, strlen(mod) + 1, mod);

        if (country != nullptr) {
            delete[] country;
        }
        country = new char[strlen(cou) + 1];
        strcpy_s(country, strlen(cou) + 1, cou);

        if (color != nullptr) {
            delete[] color;
        }
        color = new char[strlen(col) + 1];
        strcpy_s(color, strlen(col) + 1, col);

        year = a;
        price = b;
    }

    const char* getModel(){
        return model;
    }
    const char* getCountry(){
        return country;
    }
    const char* getColor(){
        return color;
    }
    int getYear(){
        return year;
    }
    double getPrice(){
        return price;
    }

    void setYear(int a) {
        year = a;
    }

    void setPrice(double b) {
        price = b;
    }

    void print() const {
        cout << "Car model: " << model << ", country:" << country << ", color:" << color << ", year: " << year << ", price:" << price << "$" << endl;
    }

    ~Car() {
        delete[] model;
        delete[] country;
        delete[] color;
        cout << "Destructor" << endl;
    }
};

int main() {
    const int maxLength = 52;
    char model[maxLength];
    char country[maxLength];
    char color[maxLength];
    int year;
    double price;

    cout << "Enter the model of the car: ";
    cin.getline(model, maxLength);

    cout << "Enter the country of the car: ";
    cin.getline(country, maxLength);

    cout << "Enter the color of the car: ";
    cin.getline(color, maxLength);

    cout << "Enter the year of the car: ";
    cin >> year;

    cout << "Enter the price of the car: ";
    cin >> price;

    Car car(model, country, color, year, price);
    car.print();

	Car car2 = car;
    car2.print();
}