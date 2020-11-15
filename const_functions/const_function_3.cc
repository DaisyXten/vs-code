#include<iostream>
using namespace std;
class Demo{
    int value;
    public:
        Demo(int v = 0){
            value = v;
        }

        void showMessages(){
            cout<<"This is a non-const function"<<std::endl;
        }
        void display() const{
            cout<<"This is const function"<<std::endl;
        }
};

int main(){
    const Demo d(5);
    d.display();
    return 0;
}
