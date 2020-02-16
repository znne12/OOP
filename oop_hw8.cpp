#include <iostream>

using namespace std;

  // task 1------------------------------------------------------------
double div1(int x1, int x2) {
    if (x2 == 0) throw "you can't divide by zero";
    return x1 / x2;
 }

  //rask 2 ------------------------------------------------------------
class Ex {
private:
    double x;
public:
    Ex(double _x) : x(_x){ }
    double get(){return x;}
};

class Bar{
private:
    double y;
public:
    Bar() { y = 0; }
    void set(double a){
        if (y + a > 100) {throw Ex(y+a);}
        else y = a;

    }
};
  // task 3-----------------------------------------------------------
class IllegalCommand{
private:
    int posX, posY, x, y;
public:
    IllegalCommand(int _posX, int _posY, int _x, int _y) :
        posX(_posX), posY(_posY), x(_x), y(_y) {}
    friend ostream& operator<<(ostream& out, IllegalCommand& illegalCommand){
        out << "Robot is in position: x = " << illegalCommand.posX << ", y = " << illegalCommand.posY << endl;
        out << "Illegal command, robot can move only one square! " << "moveX = " << illegalCommand.x << " moveY = " << illegalCommand.y << endl;
        return out;
    }
};
class OffTheField{
private:
    int posX, posY, x, y;
public:
    OffTheField(int _posX, int _posY, int _x, int _y) :
        posX(_posX), posY(_posY), x(_x), y(_y) {}
    friend ostream& operator<<(ostream& out, OffTheField& otf){
        out << "Robot is in position: x = " << otf.posX << ", y = " << otf.posY << endl;
        out << "Illegal command! Robot can't move at position " << otf.posX + otf.x << ", " << otf.posY + otf.y << endl;
        return out;
    }
};

class Robot{
private:
    int posX, posY;
public:
    Robot(){posX = 1; posY = 1;}
    void move(int moveX, int moveY){
        if (moveX > 1 || moveX < -1 || moveY > 1 || moveY < -1){
            throw IllegalCommand(posX, posY, moveX, moveY);
        } else if  ((posX == 1 && moveX == -1)||
                    (posX == 10 && moveX == 1) ||
                    (posY == 1 && moveY == -1) ||
                    (posY == 10 && moveY == 1)) {
            throw OffTheField(posX, posY, moveX, moveY);            
        }
        posX += moveX;
        posY += moveY;
        cout << "Robot at position " << posX << ", " << posY << endl;
    }
};

int main(){
    int x1, x2, n = 1;
    cout << "Enter 2 numbers:" << endl;
    cin >> x1 >> x2;
    try {
        cout << "div:" << div1(x1, x2) << endl;
    }
    catch (const char* exception) {
        cerr << "Error:" << exception << endl;
    }
    Bar bar;

    while(n){
        cout << "Enter number ( 0 - exit ): ";
        cin >> n;
        try{
            bar.set(n);
        }
        catch(Ex& ex){
            cerr << "Exception object data y+a = " << ex.get() << endl;
       }
    }
    int moveX = 0;
    int moveY = 0;
    Robot robot;
    cout << "Robot starts at position 1, 1" << endl;
    cout << "Enter moveX (type 25 to exit): " << endl;
    cin >> moveX;
    if (moveX != 25){
        cout << "Enter moveY: " << endl;
        cin >> moveY;
    }
    while(moveX != 25){
        try{
            robot.move(moveX, moveY);
        }
        catch(IllegalCommand& illegalCommand){
            cerr << illegalCommand << endl;
        }
        catch(OffTheField& offTheField){
            cerr << offTheField << endl;
        }
        cout << "Enter moveX (type 25 to exit): " << endl;
        cin >> moveX;
        if (moveX != 25){
            cout << "Enter moveY: " << endl;
            cin >> moveY;
        }
    }
    return 0;
}