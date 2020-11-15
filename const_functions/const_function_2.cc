#include<iostream>
using namespace std;

class Test{
    int value;
    public:
    Test(int v = 0){
        value = v;
    }
    int getValue(){return value;}
};

int main(){
    const Test t;
    // const object cannot call unconst function
    cout << t.getValue();
    return 0;
}
