//g++ -std=c++11 emplace_push_back.cc
#include<vector>
#include<iostream>
using namespace std;
class A{
    public:
         A(int a):_a(a) { cout<<"A constructor called!!"<<_a<<std::endl; }
          ~A() { cout<<"\nA destructor called for"<<_a<<std::endl; }
    private:
      int _a;    
};

class B{
    public:
         B(int b):_b(b) { cout<<"B constructor called!!"<<_b<<std::endl; }
         ~B() { cout<<"\nB destructor called!!"<<_b<<std::endl; }
    private:
         int _b;
};
 
int main()
{
    vector<A> v; 
     
    v.push_back(78);
    v.push_back(90);
    
    vector<B> bv;
    bv.emplace_back(18);
     
   // cin.get();
    return 0;
}
