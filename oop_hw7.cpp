#include <iostream>
#include <memory>
using namespace std;

template <class T>
class Auto_ptr{
private:
    T* ptr;
public:
    Auto_ptr(T* p) : ptr(p) { }
    Auto_ptr(const Auto_ptr& p) = delete;
    Auto_ptr& operator= (const Auto_ptr& p) = delete;
    Auto_ptr (Auto_ptr&& p) : ptr(p.ptr) { p.ptr = nullptr;}
    Auto_ptr& operator= (Auto_ptr&& p){
        if (&p == this) return *this;
        delete ptr;
        ptr = p.ptr;
        p.ptr = nullptr;
        return *this;
    }
    ~Auto_ptr() { delete ptr; }
   // T& operator*() const { return *ptr;}
    operator T*() const { return ptr;}
    T* operator->() const { return ptr;}
};

class Date {
private:
    int day, month, year;
public:
    Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year){}
    Date(){}
    ~Date(){}
    int getDay() const { return day;}
    int getMonth() const { return month;}
    int getYear() const { return year;}
    void setDay(int _day) { day = _day; }
    void setMonth(int _month) { month = _month; }
    void setYear(int _year) { year = _year; }
    friend ostream& operator<<(ostream& out, const Date& date) {
        out << date.day << "." << date.month << "." << date.year;
        return out;
    } 
};

Date& func1(Date& dt1, Date& dt2) {
    if (dt1.getYear() > dt2.getYear()) return dt1;
    else if (dt1.getYear() < dt2.getYear()) return dt2;
    else if (dt1.getMonth() > dt2.getMonth()) return dt1;
    else if (dt1.getMonth() < dt2.getMonth()) return dt2;
    else if (dt1.getDay() > dt2.getDay()) return dt1;
    else if (dt1.getDay() < dt2.getDay()) return dt2;
    else {
        cout << "Dates are equal !" << endl;
    }
}

void func2(Date& dt1, Date& dt2) {
    int tmp;
    tmp = dt1.getDay();
    dt1.setDay(dt2.getDay());
    dt2.setDay(tmp);
    tmp = dt1.getMonth();
    dt1.setMonth(dt2.getMonth());
    dt2.setMonth(tmp);
    tmp = dt1.getYear();
    dt1.setYear(dt2.getYear());
    dt2.setYear(tmp);
}

int main(){
    Auto_ptr<Date> today(new Date(12,02,2020));
    Auto_ptr<Date> date(new Date);
    cout << today->getDay() << "." << today->getMonth() << "." << today->getYear() << endl;
    cout << *today << endl;
    date = move(today);
    if (today == nullptr) cout <<" today = nullptr" << endl; 
    if (date == nullptr) cout <<" date = nullptr" << endl; 

    unique_ptr<Date> date1 = make_unique<Date>(12,02,2020);
    unique_ptr<Date> date2 = make_unique<Date>(12,07,2020);

    cout << func1(*date1, *date2) << endl;
    cout <<"date1: "<<*date1 << endl << "date2: "<< *date2 << endl;
    func2(*date1, *date2);
    cout <<"date1: "<<*date1 << endl << "date2: "<< *date2 << endl;
    getchar();
}