

#include<iostream>

using namespace std;

class XYZ{
    private:
        int num=100;
        char ch='Z';
    public:
        friend void disp(XYZ obj);
};

//Global Function
