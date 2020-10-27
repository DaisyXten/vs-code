// A friend class can access private and protected members and functions in which class it is declared and friend

#include<iostream>

using namespace std;

class XYZ{
private:
    char ch='A';
    int num = 11;
public:
    /*
     * class friend
     */
    friend class ABC;
};
class ABC{
    public:
        void disp(XYZ obj){
            cout<<obj.ch<<std::endl;
            cout<<obj.num<<std::endl;
        }
};

int main(){
    ABC obj;
    XYZ obj2;
    obj.disp(obj2);
    return 0;
}

