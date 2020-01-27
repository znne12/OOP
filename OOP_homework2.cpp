#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

  //-------------task 1--------------------------------------------------------------------------------------------------------
class Book {
private:
    int price;
    string title;
    string author;
       
public:
    Book(string _title, string _author, int _price)
    { 
        setTitle(_title);
        setAuthor(_author);
        setPrice(_price);
    }
    Book() {
        price = 0;
    }
    string getAuthor() const {return author;}
    string getTitle() const {return title;}
    int getPrice() const {return price;}
    bool setAuthor(string author) {
        int count = 0;
        for (int i = 0; i < author.size(); i++) {
            if (author[i] == ' ') count++;
            if (count > 1) { cout << "Wrong Author!" << "\n"; return false; }
        }
        this->author = author;
    }
    bool setTitle(string title) {
        if (title[0] >= '0' && title[0] <= '9') { cout << "Wrong title!" << "\n"; return false; }
        this->title = title;
        return true;
    }
    bool setPrice(int price) {
        if (price < 0) { cout << "Wrong price!" << "\n"; return false; }
        this->price = price;
        return true;
    }
};
class GoldenEditionBook : public Book {
public:
    GoldenEditionBook(const Book &parrent) {
        setTitle(parrent.getTitle());
        setAuthor(parrent.getAuthor());
        setPrice(parrent.getPrice() * 1.3);
    }

    void setParrentBook(const Book &parrent) {
        setTitle(parrent.getTitle());
        setAuthor(parrent.getAuthor());
        setPrice(parrent.getPrice() * 1.3);
    }
};
  //-------------task 2--------------------------------------------------------------------------------------------------------
class Human {
private:
    string firstName;
    string lastName;
public:
    Human(string _fn, string _ln) : firstName(_fn), lastName(_ln) {}
    void setFirstName(string _fn) {
        firstName = _fn;
    }
    void setLastName(string _ln) {
        lastName = _ln;
    }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
};
class Student : public Human {
private:
    string facultyNumber;
    int &Count() {
        static int c = 0;
        return c; 
    }
public:
    Student(string _fn, string _ln, string _facnum) : Human(_fn, _ln), facultyNumber(_facnum) { Count()++; }
    void setFacultyNumber(string _facnum) {
        facultyNumber = _facnum;
    }
    string getFacultyNumber() { return facultyNumber; }
    int getCount() { return Count(); }
    ~Student() { Count()--; }
};
class Worker : public Human {
private:
    double weekSalary;
    double workHoursPerDay;
    int& Count() {
        static int c = 0;
        return c;
    }
public:
    Worker(string _fn, string _ln, double _ws, double _whpd) : 
        Human(_fn, _ln), weekSalary(_ws), workHoursPerDay(_whpd) { Count()++; }
    void setWeekSalary(double _ws) {
        weekSalary = _ws;
    }
    void setWorkHoursPerDay(double _whpd) {
        workHoursPerDay = _whpd;
    }
    double getWeekSalary() { return weekSalary; }
    double getWorkHoursPerDay() { return workHoursPerDay; }
    int getCount() { return Count(); }
    ~Worker(){ Count()--; }
};
  //-------------task 3--------------------------------------------------------------------------------------------------------
class Deck {
public:
    Deck() {
        srand(time(NULL));
        random_shuffle(cards.begin(), cards.end());
    }
    string getCard() {
        if (cards.size() == 0) { cout << "There are no cards left in the deck 1" << endl; return 0; }
        string tmp = cards.back();
        cards.pop_back();
        return tmp;
    }
private:
    vector <string> cards = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",
                              "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",
                              "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",
                              "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
};

class Player {
public:
    Player(string _name) : name(_name) {};
    int getSum() {
        int sum = 0;
        int tuz = 0;
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i] == "2") { sum = sum + 2; }
            else if (cards[i] == "3") { sum = sum + 3; }
            else if (cards[i] == "4") { sum = sum + 4; }
            else if (cards[i] == "5") { sum = sum + 5; }
            else if (cards[i] == "6") { sum = sum + 6; }
            else if (cards[i] == "7") { sum = sum + 7; }
            else if (cards[i] == "8") { sum = sum + 8; }
            else if (cards[i] == "9") { sum = sum + 9; }
            else if (cards[i] == "A") { sum = sum + 11; tuz = tuz + 1; }
            else { sum = sum + 10; }
        }
        for (int i = 1; i <= tuz; i++) {
            if (sum > 21) { sum = sum - 10; }
        }
        return sum;
    }
    void addCard(string _card) {
        cards.push_back(_card);
    }
    string getName() { return name; }
    string printCards() {
        string tmp;
        for (int i = 0; i < cards.size(); i++) { tmp += cards[i] + " "; }
        return tmp;
    }

    
private:
    string name;
    vector <string> cards;
    
};
int main()
{
  //-------------task 1--------------------------------------------------------------------------------------------------------
    Book bk1("Booook", "K. Booker", 123);
    GoldenEditionBook goldbk1(bk1);
    string author, title;
    int price;
    cout << bk1.getTitle() << "    " << bk1.getAuthor() << "     " << bk1.getPrice() << "\n";
    cout << "Gold :" << goldbk1.getTitle() << "    " << goldbk1.getAuthor() << "     " << goldbk1.getPrice() << "\n";
    cout << "Enter title" << "\n";
    do {
        cin >> title;
    } while (!bk1.setTitle(title));
    cout << "Enter author" << "\n";
    do {
        cin >> author;
    } while (!bk1.setAuthor(author));
    cout << "Enter price" << "\n";
    do {
        cin >> price;
    } while (!bk1.setPrice(price));
    cout << bk1.getTitle() << "    " << bk1.getAuthor() << "     " << bk1.getPrice() << "\n";
    goldbk1.setParrentBook(bk1);
    cout << "Gold :" << goldbk1.getTitle() << "    " << goldbk1.getAuthor() << "     " << goldbk1.getPrice() << "\n";
 //-------------task 2--------------------------------------------------------------------------------------------------------
    Student st1("Ivan", "Ivanov", "FIRT");
    Student st2("Oleg", "Olegov", "YURFAK");
    Worker w1("Konstantin", "Petrov", 24528, 8);
    Worker w2("Andrei", "Ivanov", 24528, 9);
    Worker w3("Sergei", "Petrov", 24328, 7);
    cout << "Number of students created:" << st1.getCount() << endl;
    cout << "Number of workers created:" << w1.getCount() << endl;
    cout << "Worker " << w1.getFirstName() << " " << w1.getLastName() << " has a salary of " << w1.getWeekSalary() <<
        " and works " << w1.getWorkHoursPerDay() << " hours per day" << endl << endl;
  //-------------task 3--------------------------------------------------------------------------------------------------------
    Deck Deck1;
    Player Dealer("Dealer");
    Player Human("Konstantin");
    cout << Dealer.getName() << " playing with " << Human.getName() << endl;
    Dealer.addCard(Deck1.getCard());
    Human.addCard(Deck1.getCard());
    cout << Dealer.getName() << " cards: " << Dealer.printCards() << endl;
    Human.addCard(Deck1.getCard());
    cout << Human.getName() << " cards: " << Human.printCards() << endl;
    if (Human.getSum() == 21) {
        cout << Human.getName() << " has a blackjack!" << " with cards : " << Human.printCards() << endl; 
        return 0;
    } else {
        char ans;
        do {
            cout << Human.getName() << " one more card ? 1 - YES, other - NO" << endl;
            cin >> ans;
            if (ans == '1') {
                Human.addCard(Deck1.getCard());
                cout << "Human cards: " << Human.printCards() << endl;
                if (Human.getSum() > 21) {
                    cout << "too much :( " << Human.printCards() << Human.getSum();
                    return 0;
                }else if (Human.getSum() == 21) {
                    cout << Human.getName() << " has a blackjack!" << " with cards : " << Human.printCards() << endl;
                    return 0;
                };

            }
            else {
                while (Dealer.getSum() < 17) Dealer.addCard(Deck1.getCard());
                if (Dealer.getSum() == 21) {
                    cout << Dealer.getName() << " has a blackjack!" << " with cards : " << Dealer.printCards() << endl;
                }
                else if (Dealer.getSum() > 21) {
                    cout << "too much :( for "<< Dealer.getName()<< " with cards: " << Dealer.printCards() << Dealer.getSum();
                    return 0;
                }
                else if (Human.getSum() == Dealer.getSum()) {
                    cout << "Draw" << endl;
                    cout << "Dealer cards: " << Dealer.printCards() << Dealer.getSum() << endl;
                    cout << "Human cards: " << Human.printCards() << Human.getSum() << endl;
                    return 0;
                }
                else if (Human.getSum() > Dealer.getSum()) {
                    cout << Human.getName() << " winner " << endl;
                    cout << "Dealer cards: " << Dealer.printCards() << Dealer.getSum() << endl;
                    cout << "Human cards: " << Human.printCards() << Human.getSum() << endl;
                    return 0;
                }
                else {
                    cout << Dealer.getName() << " winner " << endl;
                    cout << "Dealer cards: " << Dealer.printCards() << Dealer.getSum() << endl;
                    cout << "Human cards: " << Human.printCards() << Human.getSum() << endl;
                    return 0;
                }
            }

        } while (ans == '1');
    }

}
