//[Definition]
// virtual function is declared within a base class 
// and is redefined(Override) by a derived class.
// You can refer a derived object with a base class pointer or reference to call a virtual function
// to execute the derived class's version of function
//
//[Note]
// virtual functions are mainly used to achieve Runtime Polymorphism
// The resolving of function call is done at Run-time.
//
//[Rule]
// 1. Virtual functions can not be static and can not be a friend function of another class
// 2. Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism
// 3. The prototype of virtual functions should be same in base as well as derived class.
// 4. They are always defined in base class and overridden in derived class. 
//  But it is not mandatory for derived class to override.
// 5. A class can have virtual destructor but it can not have a virtual constructor
//
#include <iostream>

class base {
public:
    virtual void print(){
        std::cout<<"print base class"<<std::endl;
    }

    void show(){
        std::cout<<"show base class"<<std::endl;
    }
};

class derived : public base{
    public:
        void print(){
            std::cout << "print derived class"<<std::endl;
        }

        void show(){
            std::cout<<"show derived class"<<std::endl;
        }
};

int main(){
    base* bptr;
    derived d;
    bptr = &d;

    //virtual function, binded at runtime
    bptr->print();

    //Non-virtual function, binded at compiled time
    bptr->show();
}
