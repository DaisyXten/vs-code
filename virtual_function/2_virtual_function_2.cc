#include <iostream>
class base {
    public:
        void func_1(){
            std::cout<<"non virtual base-1\n";
        }
        virtual void func_2(){
            std::cout<<"virtual base-2\n";
        }
        virtual void func_3(){
            std::cout<<"virtual base-3\n";
        }
        virtual void func_4(){
            std::cout<<"virtual base-4\n";
        }
};

class derived: public base{
    public:
        void func_1(){
            std::cout<<"derived 1\n";
        }
        void func_2(){
            std::cout<<"derived 2\n";
        }
        void func_4(int x){
            std::cout<<"derived 4\n";
        }
};

int main(){
    base* p;
    derived obj;
    p = &obj;

    p->func_1(); // it should show base

    p->func_2(); // it shoule be derived 2

    p->func_3(); // Late binding. It should be base 3

    p->func_4(); // Late binding. It should be base 4
    
    // Early binding but this function is illegal
    // because pointer is of base type but base type does not have this function signature
    // p->func_4(5); // Error
}
