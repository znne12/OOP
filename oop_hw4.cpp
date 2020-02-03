#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
using namespace std;

class ArrayInt {
private:
    int* m_data;
    int m_length;

public:
    ArrayInt() : m_length(0), m_data(nullptr){}
    ArrayInt(int length) : m_length(length){
        assert(length >= 0);
        if (length > 0){
            m_data = new int[length];
        }
        else {
            m_data = nullptr;
        }
    }
    ~ArrayInt() {
        delete[] m_data;
    }
    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() const {
        return m_length;
    }
    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength) {
        if (newLength == m_length) return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int* data = new int[newLength];
        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }
        delete[] m_data;
        m_length = newLength;
    }
    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];
        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];
        data[index] = value;
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value) { 
        insertBefore(value, m_length); 
    }
    int pop_back() {
        int value = m_data[m_length];
        resize(m_length - 1);
        return value;
    }
    void sort() {
        if (m_length <= 1) return;
        int left = 1;
        int right = m_length - 1;
        while (left <= right) {
            for (int i = right; i >= left; --i) {
                if (m_data[i - 1] > m_data[i])
                    swap(m_data[i - 1], m_data[i]);
            }
            left++;
            for (int i = left; i <= right; ++i) {
                if (m_data[i - 1] > m_data[i])
                    swap(m_data[i - 1], m_data[i]);
            }
            right--;
        }
    }
    void insertRandom(int value) {
        srand(time(NULL));
        int rnd_index = rand() % m_length;
        insertBefore(value, rnd_index);
    }
};
  //task 3------------------------------------------------------------------------------------
class Card {
private:
    bool cardPos;
    enum cardSuit { Hearts, Diamonds, Clubs, Spades };
    enum cardNum { Two = 2, Three = 3, Four = 4, Fife = 5, Six = 6, 
        Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 10, 
        Queen = 10, King = 10, Ace = 1};
    cardSuit suit;
    cardNum num = Six;
public:
    Card() {}//(cardSuit _suit, cardNum _num, bool _face) : suit(_suit), num(_num), cardPos(_face) { }
    void Flip() {
        if (cardPos == true) cardPos = false;
        else cardPos = true;
    }
    int GetValue() {
        return num;
    }
};
class Hand {
private:
    vector <Card*> m_Cards;

public:
    Hand(){}
    void Clear(){
        m_Cards.clear();
    }
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    int GetTotal() {
        int sum = 0;
        for (auto ind : m_Cards) {
            int tuz = 0;
            sum += ind->GetValue();
            if (ind->GetValue() == 1 && tuz == 0) { tuz = 1; sum += 10; }
        }
        return sum;
    }

};
  // task 4---------------------------------
int translate(int ns, int n)
{
    int result = 0;
    for (int i = 0; n >= pow(10, i); ++i)
    {
        result += n % (int)pow(10, i + 1) / pow(10, i) * pow(ns, i);
    }
    return result;
}
vector<int> plusq(const std::vector<int>& A, int baseA, const std::vector<int>& B, int baseB, int baseResult) {
    int num1=0;
    int num2=0;
    int res=0;
    vector <int> result;
    for (int i = 0; i < A.size(); i++) {
        num1 += A[A.size() - i - 1] * pow(10, i);
    }
    num1 = translate(baseA, num1);
    for (int i = 0; i < B.size(); i++) {
        num2 += B[B.size() - i - 1] * pow(10, i);
    }
    num2 = translate(baseB, num2);
    res = num1 + num2;
    while (res) {
        res = res / baseResult;
        result.push_back(res % baseResult);
    }
    return result;
}

int main()
{
    ArrayInt arr;
    arr.push_back(32);
    arr.push_back(27);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(43);
    for (int i = 0; i < arr.getLength(); i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Sorting array..." << endl;
    arr.sort();
    for (int i = 0; i < arr.getLength(); i++) cout << arr[i] << " ";
    cout << endl;
  // task 2----------------------------------------------------------------------------------
    int n, count = 0;
    cout << "Enter the number of numbers in the vector :";
    cin >> n;
    vector <int> vect(n);
    cout << "Enter numbers:";
    for (int i = 0; i < n; i++) cin >> vect[i];

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < i && vect[j] != vect[i]) ++j;

        count += j == i;
    }
    cout << "Number of unique elements :" << count << endl;
  //task 3-----------------------------------------------------------------------------------
    Card card1;
    Card card2;
    Hand hand1;
    hand1.Add(&card1);
    hand1.Add(&card2);
    cout << "Summ cards:" <<hand1.GetTotal() << endl;

  //task 4------------------------------------------------------------------------------------
    int baseA, baseB, baseResult;
    int an, bn;
    vector <int> result;
    cout << "Enter the number system in the vector A:";
    cin >> baseA;
    cout << "Enter the number system in the vector B:";
    cin >> baseB;
    cout << "Enter the number of numbers in the vector A:";
    cin >> an; 
    cout << "Enter the number of numbers in the vector B:";
    cin >> bn;
    vector <int> A(an);
    vector <int> B(bn);
    cout << "Enter numbers vector A:";
    for (int i = 0; i < an; i++) cin >> A[i];
    cout << "Enter numbers vector B:";
    for (int i = 0; i < bn; i++) cin >> B[i];
    cout << "Enter base result:";
    cin >> baseResult;
    result = plusq(A, baseA, B, baseB, baseResult);
    for (auto ind : result) cout << ind << " ";

    
    return 0;
}
