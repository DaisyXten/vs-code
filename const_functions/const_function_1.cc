#include<iostream>

class Test{
    int value;
    public:
    Test(int v = 0){
        value = v;
    }
    int getValue() const 
    {
        return value;
    }
};

int main(){
    Test t(20);
    std::cout<<t.getValue()<<std::endl;
    return 0;
}


