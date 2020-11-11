#include "boost/variant.hpp"
#include <iostream>

class my_visitor : public boost::static_visitor<int>{
    public:
        int operator()(int i) const{
            return i;
        }

        int operator()(const std::string & str) const{
            return str.length();
        }

};

int main(){
    boost::variant<int, std::string> u("hello world");
    std::cout<<u;

    int result = boost::apply_visitor(my_visitor(), u);
    std::cout << result;//output: 11

}
