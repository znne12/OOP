#include <iostream>
using namespace std;
//task 1 ------------------------------------------------------
template <class T>
class Pair1 {
private:
    T x1;
    T x2;
public:
    Pair1(T _x1, T _x2) : x1(_x1), x2(_x2){}
    T first() const {return x1; }
    T second() const {return x2; }
    ~Pair1(){}
};
// task 2-------------------------------------------------------
template <class T, class U>
class Pair {
private:
    T x1;
    U x2;
public:
    Pair(T _x1, U _x2) : x1(_x1), x2(_x2){}
    T first() const {return x1; }
    U second() const {return x2; }
    ~Pair(){}
};
  //task 3 ------------------------------------------------------
template <class U>
class Pair<string, U> {
private:
    string x1;
    U x2;
public:
    Pair(string _x1, U _x2) : x1(_x1), x2(_x2){ }
    string first() const {return x1; }
    U second() const {return x2; }
    ~Pair(){ }
};
template < class U>
class StringValuePair : public Pair<string, U>{
public:
    StringValuePair(string _x1, U _x2) : Pair<string, U>(_x1, _x2){}
    ~StringValuePair(){}
}; 


int main()
{
  //task 1 ------------------------------------------------------  
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
  //task 2 ------------------------------------------------------  
        Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
  //task 3 ------------------------------------------------------
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
