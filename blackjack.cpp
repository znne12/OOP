#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Card {
protected:
    bool cardPos;

public:
    enum cardSuit { Hearts, Diamonds, Clubs, Spades };
    enum cardNum { Ace = 1, Two = 2, Three = 3, Four = 4, Fife = 5, Six = 6,
        Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11,
        Queen = 12, King = 13};
        cardSuit suit;
        cardNum num;
    Card(cardSuit _suit, cardNum _num, bool _face) : suit(_suit), num(_num), cardPos(_face)  { 
    }
    Card() {
    }
    void Flip() {
        if (cardPos == true) cardPos = false;
        else cardPos = true;
    }
    friend ostream& operator<< (ostream& out, Card &card){
        if (card.cardPos) {
            switch(card.num){
                case Ace : out << " Ace of";break;
                case Two : out << " Two of";break;
                case Three : out << " Three of";break;
                case Four : out << " Four of";break;
                case Fife : out << " Fife of";break;
                case Six : out << " Six of";break;
                case Seven : out << " Seven of";break;
                case Eight : out << " Eight of";break;
                case Nine : out << " Nine of";break;
                case Ten : out << " Ten of";break;
                case Jack : out << " Jack of";break;
                case Queen : out << " Queen of";break;
                case King : out << " King of";break; 
            }
            switch(card.suit){
                case  Hearts : out << " Hearts";break;
                case  Diamonds :  out << " Diamonds";break;
                case  Clubs :  out << " Clubs";break;
                case  Spades :  out << " Spades";break;
            } 
        } else out << "xx";
         return out;
    }
    int GetValue() const{
        if (cardPos) {
            if (num >= Ace && num <= Ten) return num;
            else return 10;
        }
        else return 0;
    }
};
class Hand{
protected:
    vector <Card*> m_Cards;
public:
    Hand(){}
    void Clear(){
        for (auto ind : m_Cards) delete ind;
        m_Cards.clear();
    }
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    int GetTotal() const{
        int sumTotal = 0;
        int  acesInHand= 0;
        for (auto ind : m_Cards) {
            sumTotal += ind->GetValue();
            if (ind->GetValue() == Card::Ace && acesInHand == 0) { acesInHand++; sumTotal += 10; }
        }
        return sumTotal;
    }
    virtual ~Hand(){
        Clear();
    }
};
class GenericPlayer : public Hand {
protected:
    string name;
public: 
    GenericPlayer(string _name) : name(_name){}
    virtual bool IsHitting() const = 0;    
    bool IsBoosted() const{
        if (Hand :: GetTotal() > 21) return true;
        else return false;
    }
    void Bust() const{
        cout << name << " is Boosted !"<< endl;
    }
    friend ostream& operator<< (ostream& out, GenericPlayer &gp){
        out << gp.name << " with cards:";
        for (auto ind : gp.m_Cards){
            out << *ind;
            if (ind != gp.m_Cards.back()) out << ", ";
        }
        out << " and total points: "<< gp.GetTotal();
        return out;
    }
    ~GenericPlayer(){}
};
class Player : public GenericPlayer {
    private:

    public:
    Player(string _name) : GenericPlayer(_name){}
    bool IsHitting() const override{
        char answer = '0';
        while(!(answer == 'y' || answer == 'Y' || answer =='n' || answer == 'N')){
            cout << "Do you want one more card? (y/Y - yes, n/N - no):";
            cin >> answer;
            cout << endl;
        }
        if (answer == 'y' || answer == 'Y') return true;
        else return false;
    }  
    void Win() const{
        cout << name << " win!" << endl;
    }
    void Lose()const {
        cout << name << " lose!" << endl;
    }
    void Push() const{
        cout << name << " played a draw!" << endl;
    }
};

class House : public GenericPlayer {
    private:

    public:
    House(string _name) : GenericPlayer(_name) {}
    bool IsHitting() const override{
        if (GetTotal() < 16) return true;
        else return false;
    }  
    void FlipFirstCard(){
        m_Cards[0]->Flip();
    }
};
int main (){

    Card *card1 = new Card(Card::Diamonds, Card::Three, true);
    Card *card2 = new Card(Card::Clubs, Card::Ace, true);
    Card *card3 = new Card(Card::Clubs, Card::Ace, true);
    Player player("Alex");
    player.Add(card1);
    player.Add(card2);
    player.Add(card3);
     cout << player;
     getchar();

}
