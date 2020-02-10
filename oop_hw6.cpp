#include <iostream>
#include <string>
using namespace std;

class Endll{
    
public:
    friend ostream& operator<< (ostream& out, Endll &endll){
        out << "\n" << endl;
      return out;
    }
};
int main()
{
  //task 1 ------------------------------------------------------  
    string number;
    bool isNumber = false;
    while (!isNumber){
        cout << "Enter number:" << endl;
        getline(cin, number);
        for (auto  digit : number)
            if (isdigit(digit)) {isNumber = true ; continue;}
            else { isNumber = false; break;}
    }
  //task 2 ------------------------------------------------------  
    Endll endll;    
    cout << endll;
    cout << "Test two endl." << endll;
    getchar();
    return 0;
}
