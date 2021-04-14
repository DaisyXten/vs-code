#include <iostream>

using namespace std;

class Singleton {
public:
   // This is how clients can access the single instance
   static Singleton& getInstance();

   void setValue(int val) {value_ = val;}
   int  getValue()           {return(value_);}

protected:
   int value_;

private:
   static Singleton inst_;   // The one, single instance
   Singleton& operator=(const Singleton&);
};

// Define the static Singleton pointer
Singleton Singleton::inst_ = 0;

Singleton& Singleton::getInstance() {
   if (inst_) {
      inst_ = new Singleton();
   }
   return(inst_);
}

int main() {

   Singleton p1 = Singleton::getInstance();

   p1.setValue(10);
    
   Singleton p2 = Singleton::getInstance();

   cout << "Value = " << p2.getValue() << '\n';
}
