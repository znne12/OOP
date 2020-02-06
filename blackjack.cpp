#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Card {
protected:
    bool cardPos;

public:
    enum cardSuit { Hearts, Diamonds, Clubs, Spades };
    enum cardNum { Two = 2, Three = 3, Four = 4, Fife = 5, Six = 6,
        Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11,
        Queen = 12, King = 13, Ace = 1};
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
    int GetValue() const{
        if (cardPos)return num;
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
    virtual int GetTotal() const{
        int sumTotal = 0;
        int  acesInHand= 0;
        for (auto ind : m_Cards) {
            if (ind->num >= Card :: Ace && ind->num <= Card :: Ten) sumTotal += ind->GetValue();
            switch(ind->num){
                case Card :: Jack : sumTotal += 10;break;
                case Card :: Queen : sumTotal += 10;break;
                case Card :: King : sumTotal += 10;break;
            }
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
    string getCardNames() const{
        string cardNames;
        for (auto ind : m_Cards){
            switch(ind->num){
                case Card :: Ace : cardNames += " Ace of";break;
                case Card :: Two : cardNames += " Two of";break;
                case Card :: Three : cardNames += " Three of";break;
                case Card :: Four : cardNames += " Four of";break;
                case Card :: Fife : cardNames += " Fife of";break;
                case Card :: Six : cardNames += " Six of";break;
                case Card :: Seven : cardNames += " Seven of";break;
                case Card :: Eight : cardNames += " Eight of";break;
                case Card :: Nine : cardNames += " Nine of";break;
                case Card :: Ten : cardNames += " Ten of";break;
                case Card :: Jack : cardNames += " Jack of";break;
                case Card :: Queen : cardNames += " Queen of";break;
                case Card :: King : cardNames += " King of";break; 
            }
            switch(ind->suit){
                case  Card :: Hearts :  cardNames += " Hearts";break;
                case  Card :: Diamonds :  cardNames += " Diamonds";break;
                case  Card :: Clubs :  cardNames += " Clubs";break;
                case  Card :: Spades :  cardNames += " Spades";break;
            }
            if (ind != m_Cards.back()) cardNames += ", ";
        }
        return cardNames;
    }  
public: 
    GenericPlayer(string _name) : name(_name){}
    //virtual bool IsHitting() const = 0;    закоменчено для тестов
    bool IsBoosted() const{
        if (Hand :: GetTotal() > 21) return true;
        else return false;
    }
    void Bust() const{
        cout << name << " is Boosted !"<< endl;
    }
     int GetTotal() const override {
        cout << name << " with cards:" << getCardNames() << " ";
        cout << " and total points: "<< Hand :: GetTotal();
        return Hand :: GetTotal();
    } 
    ~GenericPlayer(){}
};
int main (){

    Card *card1 = new Card(Card::Diamonds, Card::Three, true);
    Card *card2 = new Card(Card::Clubs, Card::Ace, true);
    Card *card3 = new Card(Card::Clubs, Card::Ace, true);
    GenericPlayer player("Alex");
    player.Add(card1);
    player.Add(card2);
    player.Add(card3);
    player.GetTotal();

    getchar();

}
