#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

class Power {
public:
    void set(double z1, double z2){
        x1 = z1;
        x2 = z2;
    }
    void calculate(){
        cout << pow(x1, x2) << endl;
    }
private:
    double x1 = 2;
    double x2 = 3;
};

class RGBA {
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:
    RGBA(){
    }
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : m_red(r), m_green(g), m_blue(b), m_alpha(a)
    {
    }
    void print(){
        cout << "Red: " << (int)m_red << endl; // (int) т.к. mingw выводит как char
        cout << "Green: " << (int)m_green << endl;
        cout << "Blue: " << (int)m_blue << endl;
        cout << "Alpha: " << (int)m_alpha << endl;
    }
};

class Stack{
private:
    typedef struct node {
        int data;
        struct node * next;
    } Node;
    int size = 0;
    Node *head;

    bool isEmpty(){
        if (size <= 0) {
            cout << "Stack is Empty";
            return true;
        } else return false;
    }
public:
    bool push(int value){
        Node* tmp = (Node*) new Node;
        if (tmp == NULL){
            cout << "Stack Overflow";
            return false;
        }
    tmp->data = value;
    tmp->next = head;

    head = tmp;
    size++;
    return true;
}
    int pop () {
        if (isEmpty()) return 0;
        Node* tmp = head;
        int value = tmp->data;
        head = head->next;
        delete(tmp);
        size--;
        return value;
    }

    void print() {
        if (isEmpty()) return;
        Node *current = head;
        cout << "( ";
        for (int i = 0; i < size; i++) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << ")" << endl;
        delete(current);
    }
    void reset(){
        if (isEmpty()) return;
            else
                while (size)
                    pop();
    }
    ~Stack(){
        if(!isEmpty())reset();
    }
};

int main(){
    // task 1
    Power t1;
    t1.calculate();
    t1.set(3.2, 4.1);
    t1.calculate();

    // task 2
    RGBA t2;
    t2.print();
    RGBA t21(123, 123, 233, 233);
    t21.print();

    //task 3
    Stack stack;

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}
