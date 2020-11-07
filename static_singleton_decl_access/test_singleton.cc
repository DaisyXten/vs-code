//[ref1](https://gist.github.com/pazdera/1098119)
#include <iostream>

using namespace std;

class Singleton {
public:
   // This is how clients can access the single instance
   static Singleton* getInstance();

   void setValue(int val) {value_ = val;
   cout << "Value = " << value_ << '\n';}
   int  getValue(){return(value_);}

private:

   int value_;
   static Singleton* inst_;   // The one, single instance
   Singleton();
   Singleton* operator=(const Singleton*);
};

// Define the static Singleton pointer
Singleton* Singleton::inst_ = 0;

Singleton* Singleton::getInstance() {
   if (!inst_) {
      inst_ = new Singleton();
   }
   return(inst_);

}

Singleton::Singleton(){}

int main() {
   std::cout<<"P1"<<std::endl;
   Singleton* p1 = Singleton::getInstance();

   std::cout<<"P2"<<std::endl;
   p1->setValue(10); 
   cout << "Value = " << p1->getValue() << '\n';

   std::cout<<"P3"<<std::endl;
   Singleton* p2 = Singleton::getInstance();

   cout << "Value = " << p2->getValue() << '\n';
}
