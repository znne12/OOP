#include <iostream>
#include <cmath>
using namespace std;


// task 1--------------------------------------------------------------------
class Figure{
public:
    Figure(){
    }
    virtual int area(){
        return 0;
    }
};
class Parallelogram : public Figure{
public:
    Parallelogram(int x, int h){
        this->h = h;
        this->x = x;
    }
    int area() override { return x * h; }
protected:
    int x, h;
};
class Rectangle : public Parallelogram{
public:
    Rectangle(int x, int h) : Parallelogram(x, h){
    }
    int area() override { return x * h; }
};

class Square : public Parallelogram{
public:
    Square(int x) : Parallelogram(x, 0){
    }
    int area() override{ return x * x; }
};
class Rhombus : public Parallelogram{
public:
    Rhombus(int x, int h) : Parallelogram(x, h){
    }
    int area() override { return x * h; }
};
class Circle : public Figure{
public:
    Circle(int r){
        this->r = r;
    }
    int area() override{ return ((int)2*asin(1)) * r * r; }
private:
    int r;

};
// task 2---------------------------------------------------
class Car{
public:
    Car(string a1, string a2) : company(a1), model(a2){
        cout << "class Car constructor work" << endl;
        cout << "Company:" << company << endl;
        cout << "Model:" << model << endl;
        cout << endl;
    }

    string company, model;
};
class PassengerCar : virtual public Car {
public:
    PassengerCar(string a1, string a2) : Car(a1, a2){
        cout << "class PassengerCar constructor work" << endl;
        cout << "Company:" << company << endl;
        cout << "Model:" << model << endl;
        cout << endl;
    }
};
class Bus : virtual public Car {
public:
    Bus(string a1, string a2) : Car(a1, a2) {
        cout << "class Bus constructor work" << endl;
        cout << "Company:" << company << endl;
        cout << "Model:" << model << endl;
        cout << endl;
    }
};
class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string a1, string a2) : Car(a1, a2), PassengerCar(a1, a2), Bus(a1, a2){
        cout << "class Minivan constructor work" << endl;
        cout << "Company:" << company << endl;
        cout << "Model:" << model << endl;
        cout << endl;
    }

};
// task 3---------------------------------------------------
class Fraction {
public:
    Fraction(int x1, int x2){
        dividend = x1;
        divider = x2;
        }
    Fraction operator+(const Fraction &f2){
        int _lcm = lcm(divider, f2.divider);
        int _divider = _lcm;
        int _dividend =dividend*(_lcm / divider) + f2.dividend*(_lcm / f2.divider);
        return Fraction(_dividend, _divider);
    }
    Fraction operator-(const Fraction &f2){
        int _lcm = lcm(divider, f2.divider);
        int _divider = _lcm;
        int _dividend =dividend*(_lcm / divider) - f2.dividend*(_lcm / f2.divider);
        return Fraction(_dividend, _divider);
    }
    Fraction operator*(const Fraction &f2){
        int _divider = divider * f2.divider;
        int _dividend = dividend * f2.dividend;
        int tmp = _dividend;
        _dividend /= gcd(_divider, tmp);
        _divider /= gcd(_divider, tmp);

        return Fraction(_dividend, _divider);
    }
    Fraction operator/(const Fraction &f2){
        int _divider = divider * f2.dividend;
        int _dividend = dividend * f2.divider;
        if (gcd(_divider, _dividend) > 1) {
            int tmp = _dividend;
            _dividend /= gcd(_divider, tmp);
            _divider /= gcd(_divider, tmp);
        }
        return Fraction(_dividend, _divider);
    }
        Fraction operator-(){
        return Fraction(-dividend, divider);
    }
        bool operator==(const Fraction &f2){
        int _lcm = lcm(divider, f2.divider);
        int _divider = _lcm;
        if (dividend*(_lcm / divider) == f2.dividend*(_lcm / f2.divider)) return true;
        else return false;
    }
        bool operator!=(const Fraction &f2){
        int _lcm = lcm(divider, f2.divider);
        int _divider = _lcm;
        if (dividend*(_lcm / divider) != f2.dividend*(_lcm / f2.divider)) return true;
        else return false;
    }
        bool operator<(const Fraction &f2){
        int _lcm = lcm(divider, f2.divider);
        int _divider = _lcm;
        if (dividend*(_lcm / divider) < f2.dividend*(_lcm / f2.divider)) return true;
        else return false;
    }
        bool operator>=(const Fraction &f2){
        if (*this < f2) return false;
        else return true;
    }
        bool operator>(const Fraction &f2){
        int _lcm = lcm(divider, f2.divider);
        int _divider = _lcm;
        if (dividend*(_lcm / divider) > f2.dividend*(_lcm / f2.divider)) return true;
        else return false;
    }
        bool operator<=(const Fraction &f2){
        if (*this > f2) return false;
        else return true;}
    void setDividend(int x){ dividend = x;}
    bool setDivider(int x){
        if (x == 0) {cout << "Divider !=0"; return true;}
        else {divider = x; return false;}
        }
    void print() const{
        cout << dividend << endl;
        cout << "---"<< endl;
        cout << divider << endl<< endl;
    }
    int gcd(int a, int b){
        while (b) {
            a %= b;
            swap (a, b);
        }
	return a ;
    }
    int lcm(int a, int b){
        return a/gcd(a,b)*b;
    }
private:
    int dividend;
    int divider;
};
// task 4-------------------------------------------------------
class Card {
public:
    Card()  {
        cardPos = false; // faco down

    }

    void Flip(){
        if (cardPos == true) cardPos == false;
        else cardPos == true;
    }
    int GetValue(){
        return num;
    }

private:
    bool cardPos;
    enum cardSuit {hearts, diamonds, clubs, spades};
    enum cardNum {Two, Three, Four, Fife, Six, Seven, Eigth, Nine, Ten, Jack, Queen, King, Ace};
    cardSuit suit= diamonds;
    cardNum num = Four;
};

int main(){
// task 1---------------------------------------------------
    Parallelogram par1(12, 23);
    Rectangle rect1(56, 3);
    Square squ1(2);
    Rhombus rho1(3, 5);
    Circle circ1(12);
    cout << "area of Parallelogram: " << par1.area() << endl;
    cout << "area of Rectangle: " << rect1.area() << endl;
    cout << "area of Square: " << squ1.area() << endl;
    cout << "area of Rhombus: " << rho1.area() << endl;
    cout << "area of Circle: " << circ1.area() << endl;
// task 2---------------------------------------------------
    Minivan c1("Toyota", "Hi-ace");
    PassengerCar c2("Lada", "Vesta");
    Bus c3("Mercedes Benz", "Bus");
    Car c4("Audi", "TT");
// task 3---------------------------------------------------
    int dd1,dd2,dr1,dr2;
    Fraction fr1(5, 6);
    Fraction fr2(3, 4);
    Fraction fr3 = fr1 + fr2;
    fr3.print();

    cout << "Input the dividend of the fraction 1:"<< endl;
    cin >> dd1; fr1.setDividend(dd1);
    do {
    cout << "Input the divider of the fraction 1:"<< endl;
    cin >> dr1;
    } while (fr1.setDivider(dr1));
    cout << "Input the dividend of the fraction 2:"<< endl;
    cin >> dd2; fr2.setDividend(dd2);
    do {
    cout << "Input the divider of the fraction 2:"<< endl;
    cin >> dr2;
     } while (fr2.setDivider(dr2));
    cout << "+" << endl;
    fr3 = fr1 + fr2;
    fr3.print();
    cout << "-" << endl;
    fr3 = fr1 - fr2;
    fr3.print();
    cout << "*" << endl;
    fr3 = fr1 * fr2;
    fr3.print();
    cout << "/" << endl;
    fr3 = fr1 / fr2;
    fr3.print();
    cout << "unary -" << endl;
    fr3 = -fr1;
    fr3.print();
    cout << "    ==    " << endl;
    if (fr1 == fr2) cout << "Fractions are equal" << endl;
    else cout << "Fractions not equal" << endl ;
    cout << "    !=    " << endl;
    if (fr1 != fr2) cout << "Fractions not equal" << endl;
    else cout << "Fractions are equal" << endl ;
    cout << "    <    " << endl;
    if (fr1 < fr2) cout << "Fraction 1 < fraction 2" << endl;
    else cout << "Fraction 1 >= Fraction 2" << endl ;
    cout << "    >=    " << endl;
    if (fr1 >= fr2) cout << "Fraction 1 >= fraction 2" << endl;
    else cout << "Fraction 1 < Fraction 2" << endl ;
    fr1.print();
    fr2.print();
//task 4--------------------------------------------------
    Card card;
    cout << "Масть карты:" << card.GetValue() ;

    return 0;
}
